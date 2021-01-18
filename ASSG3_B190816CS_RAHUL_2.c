#include<stdio.h>
#include<stdlib.h>
long long int  merge(int a[],int s,int m,int e){
 long long int k=0;
	int n1=m-s+1;
	int n2=e-m;
	int al[n1+1],ar[n2+1];
	for(int i=0;i<n1;i++)
        al[i]=a[s+i];
    for(int j=0;j<n2;j++)
        ar[j]=a[m+1+j];
        al[n1]=2000000;
        ar[n2]=2000000;
    int i=0,j=0;
for(int p=s;p<=e;p++){
    if(al[i]<=ar[j]){
        a[p]=al[i];i++; 
        }
        else{
            a[p]=ar[j];
            j++;
         if(i!=n1)
           k+=m-i+1;
        }
}
return k;
}
long long int  merge_sort(int a[],int s,int e){
	long long int c=0;
	if(s<e){
		int m=(s+e)/2;
	c=merge_sort(a,s,m);
	c=c+merge_sort(a,m+1,e);
	c=c+merge(a,s,m,e);
	}
	return c;
}
void print(int a[]){
	int k=0;
	while(a[k]!=2000002)
	k++;
	for(int i=0;i<k;i++)
	printf("%d ",a[i]);
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	a[n]=2000002;
	int c=0;
   c=merge_sort(a,0,n-1);
  //  print(a);
//	printf("\n");
	printf("%d",c);
	return 0;
}
