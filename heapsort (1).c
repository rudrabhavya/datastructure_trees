#include<stdio.h>
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void printarray(int a[],int n){
	int i;
	printf("Sorted array:");
	for (i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
void heapify(int a[],int n,int i){
	int max=i;
	int left=2*i+1;
	int right=2*i+2;
	if (left<n && a[left]>a[max])
		max=left;
	if (right<n && a[right]>a[max])
		max=right;
	if (max!=i){
		swap(&a[max],&a[i]);
		heapify(a,n,max);
	}
}
void heap_sort(int a[],int n){
	int j,k;
	for (j=n/2-1;j>=0;j--){
		heapify(a,n,j);
	}
	for (k=n-1;k>=0;k--){
		swap(&a[0],&a[k]);
		heapify(a,k,0);
	}
}
int main(){
	int n,i;
	printf("Enter the size of array:");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements of array:");
	for (i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	heap_sort(a,n);
	printarray(a,n);
	return 0;
}
