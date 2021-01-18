#include<stdio.h>
#include<stdlib.h>
int binarysearch(int x,int st,int end,int *b){
	int mid;
	if(st<=end)
		{
	mid=st+((end-st)/2);
	if(x==*(b+mid)){
    	while(mid>0&&*(b+mid-1)==x)
		mid--;
		return mid;
	}
	else if(x>*(b+mid)){
		return binarysearch(x,mid+1,end,b);
	}
	else if(x<*(mid+b)){
		return binarysearch(x,st,mid-1,b);
	}}
	return -1;
}
int main(){
  int n,*a,t;
  scanf("%d",&n);
  a=(int*)malloc(n*sizeof(int));
  for(int i=0;i<n;i++){
  	scanf("%d",&t);
  	*(a+i)=t;
  }
  int s,p;
  scanf("%d",&s);
  p=binarysearch(s,0,n-1,a);
  printf("%d",p);
  return 0;
}
