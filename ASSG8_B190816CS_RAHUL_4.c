#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
struct stack_node{
	int data;
    struct stack_node *next;
};
struct stack{
   	 struct stack_node *top;
};
typedef struct stack_node *sn;
typedef struct stack *st;
sn create_node(int  c){
	sn new_node;
	new_node=(sn)malloc(sizeof(struct stack_node));
	new_node->data=c;
	new_node->next=NULL;
	return new_node;
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
bool is_number(char c){
	if(c>='0'&&c<='9')
	return true;
	else
	return false;
}
bool is_operator(char c){
	if(c=='+'||c=='-'||c=='*'||c=='/')
	return true;
	else
	return false;
}
int evalute_postfix(char e[]){
	int k=strlen(e);
		st s;
	s=(st)malloc(sizeof(struct stack));
	s->top=NULL;
	for(int i=0;i<k;i++){
		if(e[i]==' ')
		continue;
		else if(is_number(e[i])){
			int p=0;
			while(i<k&&is_number(e[i])){
				p=p*10+e[i]-48;
				i++;
			}
			i--;
			sn cn;
			cn=create_node(p);
			push(s,cn);
		}
		else if(e[i]=='-'&&is_number(e[i+1])){
			int p=0;
			while(i<k&&is_number(e[i+1])){
				p=p*10+e[i+1]-48;
				i++;
			}
			p=(-1)*p;
			sn cn;
			cn=create_node(p);
			push(s,cn);
		}
		else if(is_operator(e[i])){
			if(e[i]=='+'){
				int t;
				int o1=s->top->data;
				pop(s);
				int o2=s->top->data;
				pop(s);
				t=o2+o1;
				sn cn;
				cn=create_node(t);
				push(s,cn);
			}
			if(e[i]=='-'){
				int t;
				int o1=s->top->data;
				pop(s);
				int o2=s->top->data;
				pop(s);
				t=o2-o1;
				sn cn;
				cn=create_node(t);
				push(s,cn);
			}
			if(e[i]=='*'){
				int t;
				int o1=s->top->data;
				pop(s);
				int o2=s->top->data;
				pop(s);
				t=o2*o1;
				sn cn;
				cn=create_node(t);
				push(s,cn);
			}
			if(e[i]=='/'){
				int t;
				int o1=s->top->data;
				pop(s);
				int o2=s->top->data;
				pop(s);
				t=o2/o1;
				sn cn;
				cn=create_node(t);
				push(s,cn);
			}
		}
	}
	return s->top->data;
}
int main(){
	FILE *fp;
	fp=fopen("input.txt","r");
	while(!feof(fp)){
	char e[200];
	fgets(e,200,fp);
	int ans=evalute_postfix(e);
	printf("%d\n",ans);}
	return 0;
}
