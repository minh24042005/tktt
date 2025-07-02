#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char tentien[25];
	int MG,PA;
	}tien;
	
typedef struct{
	int key;
	float other;
}recordtype;

void readfromfile(int *n,tien *dslt){
	FILE *f;
	f=fopen("ATM.txt","r");
	int i=0;
	if(f==NULL){
		printf("loi mo file");
		return;
	}
	while(!feof(f)){
		fscanf(f, "%d %[^\n]", &dslt[i].MG, dslt[i].tentien);
		dslt[i++].PA=0;
	}
	*n=i;
	fclose(f);
}
void swap(tien *x,tien *y){
    tien temp=*x;
    *x=*y;
    *y=temp;
}

void Bubblesort(tien a[],int n){
	int i,j;
	for(i=0;i<=n-2;i++){
		for(j=n-1;j>=i+1;j--){
			if(a[j].MG > a[j-1].MG)
			    swap(&a[j],&a[j-1]);
		}
	}
}

void Greedy(tien dslt[], int n, int tiencanrut) {
    int i = 0;
    Bubblesort(dslt, n);  
    while (i < n && tiencanrut > 0) {
        dslt[i].PA = tiencanrut / dslt[i].MG;
        if (dslt[i].PA > 0) {
            tiencanrut -= dslt[i].PA * dslt[i].MG;  
        }
        i++;
    }
}

void inds(tien *dslt,int n,int tiencanrut){
	int i;
	int tongtientra=0;
	printf("|---|-------------------------------------|---------|--------|-------------|\n");
	printf("|%-3s|%-25s|%-9s|%-9s|%-10s|\n","STT","    Loai tien", "Menh Gia","So To","Thanh Tien");
	printf("|---|-------------------------------------|---------|--------|-------------|\n");
	for(i=0;i<n;i++){
		if(dslt[i].PA != 0){
			printf("|%-3d",i+1);
			printf("|%-25s",dslt[i].tentien);
			printf("|%-9d",dslt[i].MG);	
			printf("|%-9d",dslt[i].PA);
			printf("|%-10d|\n",dslt[i].MG*dslt[i].PA);
			tongtientra=tongtientra+dslt[i].PA* dslt[i].MG;
		}else{
			continue;
		}
	}
	printf("|---|-------------------------------------|---------|--------|-------------|\n");
	printf("so tien can rut= %9d\n",tiencanrut);
	printf("so tien can rut= %9d\n",tongtientra);
	
}

int main(){
	int n; 
	int tiencanrut;
	tien *dslt;
	 dslt = (tien *)malloc(100 * sizeof(tien)); 
	 if (dslt == NULL) {
    printf("Không th? c?p phát b? nh?!\n");
    return 1;
} 
	printf("nhap so tien can rut\n");
	scanf("%d",&tiencanrut);
	readfromfile(&n,dslt);
Greedy(dslt,n,tiencanrut);
inds(dslt,n,tiencanrut);
free(dslt);
return 0;
}

