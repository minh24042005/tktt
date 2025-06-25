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

void pushdown(record a[],int f,int l){
	int r=f;
	while(r <= (l-1)/2){
		if(l == 2*r+1){
			if(a[r].key<a[l].key) swap(&a[r],&a[l]);
			r=l;
		}else
		   if(a[r].key<a[2*r+1].key && a[2*r+1].key >= a[2*r+2].key){
		   	swap(&a[r],&a[2*r+1]);
		   	r=2*r+1;
		   }else
		      if(a[r].key < a[2*r+2].key){
		      	swap(&a[r],&a[2*r+2]);
		      	r=2*r+2;
			  }else
			     r=l;
	}
}

void heapsort(record a[],int n){
	int i;
	for(i = (n-2)/2 ;i>=0;i--)
	    pushdown(a,i,n-1);
	for(i=n-1;i>=2;i--){
		swap(&a[0],&a[i]);
		pushdown(a,0,i-1);
	}
	swap(&a[0],&a[1]);
}

int main(){
	record a[100];
	int n;
	printf("thuat toan heapsort\n");
	printf("du lieu truoc khi sap xep\n");
	read(a,&n);
	print(a,n);
	printf("du lieu sau khi sap xep\n");
	heapsort(a,n);
	print(a,n);
	return 0;
	
}
