#include<stdio.h>
long long  int fact(int k){
	if(k==0)
	return 1;
	return k*(fact(k-1));
}
int main(){
	long long int n,f;
	scanf("%lld",&n);
	f=fact(n);
	printf("%lld",f);
	return 0;
}
