#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack{
	int top;
	char *elem;
	int size;
};
typedef struct stack st;
int Ispalindrome(char str[]){
	int n;
	n=strlen(str);
	st s;
	s.elem=(char*)malloc(n*sizeof(char));
	s.top=-1;
	s.size=n;
	for(int i=0;i<n;i++){
			s.top=s.top+1;
	s.elem[s.top]=str[i];
	}
	int i=0,p=0;
	while(s.top!=-1){
		if(s.elem[s.top]==str[i]){
			s.top=s.top-1;
			i++;
		}
		else{
			p=1;
			break;
		}
	}
	if(p==1){
		return -1;
	}
	else{
		return 1;
	}
}
int main(){
	 char str[50];
	 int k;
	 gets(str);
	 k=Ispalindrome(str);
	 if(k==1){
	 	printf("1\n");
	 }
	 else{
	 	printf("0\n");
	 }
}
