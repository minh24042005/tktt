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
	f= fopen("data.txt","r");
	int i=0;
	if(f!= NULL)
	while(!feof(f)){
		fscanf(f,"%d %f",&a[i].key,&a[i].otherfields);
		i++;
	} else
	      printf("loi mo file\n");
	fclose(f);
	*n=i;
}

void print(recordtype a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%3d %5d %8.2f\n",i+1,a[i].key,a[i].otherfields);
	}
}

void bubblesort(recordtype a[],int n){
	int i,j;
	for(i=0;i<=n-2;i++){
		for(j=n-1;j>=i+1;j--){
			if(a[j].key < a[j-1].key){
				swap(&a[j],&a[j-1]);
			}
		}
	}
}

int main(){
	recordtype a[100];
	int n;
	printf("thuat toan bubblesort\n");
	printf("du lieu truoc khi sap xep\n");
	read(a,&n);
	print(a,n);
	printf("du lieu sau khi sap xep\n");
	bubblesort(a,n);
	print(a,n);
	return 0;
}
