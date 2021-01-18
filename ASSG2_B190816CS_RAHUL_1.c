#include<stdio.h>
int GCD(int x,int y){
	if(x==0)
	return abs(y);
	else
	return GCD(y%x,x);
}
int main(){
	int n,m,k,t;
	scanf("%d%d",&n,&m);
	if(n==0&&m==0)
	printf("-1");
	else{
		k=GCD(n,m);
		printf("%d",k);
	}
  return 0;
}
