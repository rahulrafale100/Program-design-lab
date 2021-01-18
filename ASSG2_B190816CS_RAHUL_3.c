#include<stdio.h>
#include<stdlib.h>
int binarysearch(int x,int st,int end,int *b){
	int mid;
	if(st<=end)
		{
	mid=st+((end-st)/2);
	if(x==*(b+mid)){
		if(x==*(b+mid-1)){
			return binarysearch(x,0,mid-1,b);
		}
		else{
			return mid;
		}
      /*  while(mid>0&&*(b+mid-1)==x)
		mid--;
		return mid;*/
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
  long int q;
  scanf("%d",&n);
  scanf("%ld",&q);
  a=(int*)malloc(n*sizeof(int));
  for(int i=0;i<n;i++){
  	scanf("%d",&t);
  	*(a+i)=t;
  }
  while(q--){
  int s,p;
  scanf("%d",&s);
  p=binarysearch(s,0,n-1,a);
  printf("%d\n",p);}
  return 0;
}
