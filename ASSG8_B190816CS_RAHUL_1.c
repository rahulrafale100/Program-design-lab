#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct stack_node{
	char data;
	struct stack_node *next;
};
struct stack{
	struct stack_node *top;
};
typedef struct stack_node *sn;
typedef struct stack *st;
sn create_node(char  c){
	sn new_node;
	new_node=(sn)malloc(sizeof(struct stack_node));
	new_node->data=c;
	new_node->next=NULL;
	return new_node;
}
bool stack_empty(sn node){
	if(node==NULL){
		return true;
	}
	else
	return false;
}
bool is_operator(char c){
	if(c=='+'||c=='-'||c=='*'||c=='/')
	return true;
	else
	return false;
}
int power(char c){
	int w;
	switch(c){
		case '+':
	    case '-':
	    	w=1;
	    	break;
	    case '*':
	    case '/':
	    	w=2;
	    	break;
	}
	return w;
}
bool high_priority(char o1,char o2){
	int o1w=power(o1);
	int o2w=power(o2);
	if(o1w>=o2w)
		return true;
		else
		return false;
}
void push(st s,sn node){
	sn new_node;
	new_node=node;
	new_node->next=s->top;
	s->top=new_node;
}
void  pop(st s){
	sn node1;
	node1=s->top;
	s->top=node1->next;
	free(node1);
}
bool is_operand(char c){
	if(c>='a'&&c<='z'){
		return true;
	}
	else
	return false;
}
 char *infix_to_postfix(char e[]){
 	st s;
	s=(st)malloc(sizeof(struct stack));
	s->top=NULL;
	int k=strlen(e);
	   static char p[200];
	   int j=0;
   for(int i=0;i<k;i++){
   	if(is_operator(e[i])){
   		while(!stack_empty(s->top)&&s->top->data!='('&&high_priority(s->top->data,e[i])){
   			p[j]=s->top->data;
   			j++;
   			pop(s);
		   }
		   sn cn;
		   cn=create_node(e[i]);
		   push(s,cn);
	   }
	   else if(is_operand(e[i])){
	   	p[j]=e[i];
	   	j++;
	   }
	   else if(e[i]=='('){
	   	sn cn;
	   	cn=create_node(e[i]);
	   	push(s,cn);
	   }
	   else if(e[i]==')'){
	   	while(!stack_empty(s->top)&&s->top->data!='('){
	   		p[j]=s->top->data;
	   		j++;
	   		pop(s);
		   }
		   pop(s);
	   }
   }
   while(!stack_empty(s->top)){
   	p[j]=s->top->data;
   	j++;
   	pop(s);
   }
	return p;
}
int main(){
	char e[100];
	scanf("%s",e);
	char *ptr=infix_to_postfix(e);
	printf("%s",ptr);
  return 0;
}
