#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct stack{
	int top;
	int *elem;
	int size;
};
typedef struct stack st;
bool  stack_full(st *s){
	if(s->top==s->size-1)
	return true;
	else
	return false;
}
void  push(st *s,int k){
	
	if(!stack_full(s))
	 {
	 	s->top=s->top+1;
	s->elem[s->top]=k;
	}
}
void pop(st *s){
	if(s->top==-1){
		printf("%d\n",-1);
	}
	else{
	s->top=s->top-1;
	int p=(s->elem[s->top+1]);
	printf("%d\n",p);}
}
void  stack_empty(st *s){
	if(s->top==-1)
	printf("%d\n",-1);
	else
	printf("1\n");
}
int main(){
	struct stack s;
	s.top=-1;
	int n;
	scanf("%d",&n);
	s.size=n;
	s.elem=(int*)malloc(n*sizeof(int));
	while(1){
		char c;
		int k;
		scanf("%c",&c);
		if(c=='i'){
			scanf("%d",&k);
			push(&s,k);
		}
		if(c=='d'){
			pop(&s);
		}
		if(c=='e'){
			stack_empty(&s);
		}
		if(c=='t')
		return 0;
	}
}
