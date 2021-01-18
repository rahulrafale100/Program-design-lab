#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main(){
  int n,t;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(int i=0;i<n-1;i++)
  {
      for(int j=0;j<n-i-1;j++){
        if(a[j]>a[j+1]){
            t=a[j+1];
            a[j+1]=a[j];
            a[j]=t;
            }
      }
  }
  for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}
