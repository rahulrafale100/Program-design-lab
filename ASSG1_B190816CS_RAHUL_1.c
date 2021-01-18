#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

void main(){
  int n,x;
  scanf("%d",&n);
  int array[n];
  for(int i=0;i<n;i++)
    scanf("%d",&array[i]);
  bool check=true;
  scanf("%d",&x);
  for(int i=0;i<n;i++){
    if(array[i]==x){
        check=false;
        printf("%d ",i);
    }
  }
  if(check)
  printf("%d",-1);
}
