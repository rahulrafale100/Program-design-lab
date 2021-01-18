#include<stdio.h>
int c=0;
void insertion_sort(int a[]){
	int p=0;
	while(a[p]!=5001)
	p++;
	for(int i=1;i<p;i++){
		int t=a[i];
		int j=i;
		while(j>0&&t<a[j-1]){
			a[j]=a[j-1];
			j=j-1;
			c++;
		}
		if(t>=a[j-1]&&j>0)
		c++;
		a[j]=t;
		}
	}
	void print(int a[]){
		int k=0;
		while(a[k]!=5001)
		k++;
		for(int i=0;i<k;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	int main(){
		int n;
		scanf("%d",&n);
		int a[n];
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		a[n]=5001;
		insertion_sort(a);
		print(a);
		printf("%d",c);
		return 0;
	}
