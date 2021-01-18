#include<stdio.h>
int partition(int a[],int s,int p,int e){
	int k=a[e];
	int t=s-1;
	int x;
	for(int i=s;i<=e-1;i++){
		if(a[i]<=k){
			t++;
			x=a[i];
			a[i]=a[t];
			a[t]=x;
	c++;
		}
		else
		c++;
	
	}
	x=a[e];
	a[e]=a[t+1];
	a[t+1]=x;
	return t+1;
}
int  quicksort(int a[],int s,int e){
	int c=0;
	if(s<e){
		int p=partition(a,s,e,e);
		return c+quicksort(a,s,p-1);
		 return c+quicksort(a,p+1,e);
	}
}
void print(int a[],int n){
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n],d;
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	d=quicksort(a,0,n-1);
	print(a,n);
	printf("\n%d",c);
}
