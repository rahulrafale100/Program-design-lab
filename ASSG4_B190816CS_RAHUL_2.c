#include<stdio.h>
#include<string.h>
int main(){
	char str[100];
	char se[100];
	gets(str);
	gets(se);
	int n1,n2;
	n1=strlen(str);
	n2=strlen(se);
	int found=0;
	int k=n1-n2,j=0,p=0;
	for(int i=0;i<k+1;i++){
		int q=i;
		j=0;p=0;
		while(str[q]==se[j]){
				q++;
			j++;
			p++;
			if(p==n2){
				found=1;
			printf("%d",i);
				break;
			}
		
		}
		if(found==1)
		break;
	}
	if(found==0)
	printf("%d",-1);
}
