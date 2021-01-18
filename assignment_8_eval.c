#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
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
struct tree_node{
	char data;
	struct tree_node *left;
	struct tree_node *right;
	struct tree_node *parent;
	struct tree_node *next;
};
struct stackd{
	struct tree_node  *top;
};

typedef struct tree_node *tn;
typedef struct stackd *std;
tn create_nodex(char c){
	tn new_node;
	new_node=(tn)malloc(sizeof(struct tree_node));
	new_node->data=c;
	new_node->left=NULL;
	new_node->right=NULL;
	new_node->parent=NULL;
	new_node->next=NULL;
	return new_node;
}

void pushx(std s,tn node){
	tn new_node;
	new_node=node;
	new_node->next=s->top;
	s->top=new_node;
	
}
void popx(std s){
	tn node1;
	node1=s->top;
	s->top=node1->next;
}
tn construct_tree(char e[]){
	int k=strlen(e);
    std s;
    s=(std)malloc(sizeof(struct stack));
    s->top=NULL;
	for(int i=0;i<k;i++){
		if(is_operand(e[i])){
			tn cn;
			cn=create_nodex(e[i]);
			pushx(s,cn);
		}
		if(is_operator(e[i])){
			tn cn,nr,nl;
				cn=create_nodex(e[i]);
			nr=s->top;
			popx(s);
			nl=s->top;
			popx(s);
			cn->left=nl;
			cn->right=nr;
			nl->parent=cn;
			nr->parent=cn;
			pushx(s,cn);
		}
	}
	return s->top;
}
tn create_assignment_tree(char s[]){
	char c1,c2;
	c1=s[0];
	c2=s[1];
	int n=strlen(s);
	char s1[150];
	for(int i=0;i<n-1;i++){
		s1[i-2]=s[i];
	}
	char *s2;
	s2=infix_to_postfix(s1);
	tn t,n1,n2;
	t=construct_tree(s2);
	n1=create_nodex(c1);
	n2=create_nodex(c2);
	n2->left=n1;
	n2->right=t;
	n1->parent=n2;
	t->parent=n2;
	return n2;
}
void inorder(tn s){
	if(s!=NULL){
		inorder(s->left);
		printf("%c",s->data);
		inorder (s->right);
	}
}
int main(){
	tn cn;
   		char e[200];
   		scanf("%s",e);
   		cn=create_assignment_tree(e);
   		inorder(cn);

}
