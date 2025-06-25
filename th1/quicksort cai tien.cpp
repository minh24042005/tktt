#include <stdio.h>

typedef struct{
	int key;
	float other;
}record;

void read(record a[],int *n){
	FILE *f;
    f=fopen("data.txt","r");
    int i=0;
    if(f!= NULL)
    while(!feof(f)){
    	fscanf(f,"%d %f",&a[i].key,&a[i].other);
    	i++;
	}else
	    printf("loi mo file");
	fclose(f);
	*n=i;
}

void print(record a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%3d %5d %8.2f\n",i+1,a[i].key,a[i].other);
	}
}

void swap(record *x, record *y){
	record temp;
	temp=*x;
	*x=*y;
	*y=temp;
}


int partition(record a[],int i,int j){
	int pivot=a[i].key;
	int l,r;
	l=i+1;
	r=j;
	while(l<=r){
		while(l<=r && a[l].key<pivot) l++;
		while(l<=r && a[r].key>=pivot) r--;
		if(l<r)
		swap(&a[l],&a[r]);
	}
	swap(&a[r],&a[i]);
	return r;
}

void quicksort(record a[],int i,int j){
if(i<j){
  int p=partition(a,i,j);
  quicksort(a,i,p-1);
  quicksort(a,p+1,j);
	}
}

int main(){
	record a[100];
	int n;
	printf("thuat toan quicksort\n");
	printf("du lieu truoc khi sap xep\n");
	read(a,&n);
	print(a,n);
	printf("du lieu sau khi sap xep\n");
	quicksort(a,0,n-1);
	print(a,n);
	return 0;
}
