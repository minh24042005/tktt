#include <stdio.h>

typedef struct{
	int key;
	float otherfields;
}recordtype;

void swap(recordtype *x, recordtype *y){
	recordtype temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void read(recordtype a[],int *n){
	FILE *f;
	f=fopen("data.txt","r");
	int i=0;
	if(f!= NULL)
	while(!feof(f)){
		fscanf(f,"%d %f",&a[i].key,&a[i].otherfields);
		i++;
    }else
         printf("loi\n");
    fclose(f);
    *n=i;
}

void print(recordtype a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%3d %5d %8.2f\n",i+1,a[i].key,a[i].otherfields);
	}
}

void insertionsort(recordtype a[],int n){
	int i,j;
	for(i=1;i<=n-1;i++){
		j=i;
		while(j>0 && a[j].key < a[j-1].key){
			swap(&a[j],&a[j-1]);
			j--;
		}
	}
}


int main(){
	int n;
	recordtype a[100];
	printf("thuat toan Insertionsort\n");
	printf("du lieu truoc khi sap xep\n");
	read(a,&n);
	print(a,n);
	
	printf("thuat toan sau khi sap xep\n");
	insertionsort(a,n);
	print(a,n);
	return 0;
}
