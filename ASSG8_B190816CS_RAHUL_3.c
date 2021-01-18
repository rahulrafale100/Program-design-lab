#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
struct tree_node{
	char data;
	struct tree_node *left;
	struct tree_node *right;
	struct tree_node *parent;
	struct tree_node *next;
};
struct stack{
	struct tree_node  *top;
};

typedef struct tree_node *sn;
typedef struct stack *st;
sn create_node(char c){
	sn new_node;
	new_node=(sn)malloc(sizeof(struct tree_node));
	new_node->data=c;
	new_node->left=NULL;
	new_node->right=NULL;
	new_node->parent=NULL;
	new_node->next=NULL;
	return new_node;
}

bool is_operator(char c){
	if(c=='+'||c=='-'||c=='*'||c=='/')
	return true;
	else
	return false;
}
bool is_operand(char c){
	if(c>='a'&&c<='z'){
		return true;
	}
	else
	return false;
}
void push(st s,sn node){
	sn new_node;
	new_node=node;
	new_node->next=s->top;
	s->top=new_node;
	
}
void pop(st s){
	sn node1;
	node1=s->top;
	s->top=node1->next;
}
sn construct_tree(char e[]){
	int k=strlen(e);
    st s;
    s=(st)malloc(sizeof(struct stack));
    s->top=NULL;
	for(int i=0;i<k;i++){
		if(is_operand(e[i])){
			sn cn;
			cn=create_node(e[i]);
			push(s,cn);
		}
		if(is_operator(e[i])){
			sn cn,nr,nl;
				cn=create_node(e[i]);
			nr=s->top;
			pop(s);
			nl=s->top;
			pop(s);
			cn->left=nl;
			cn->right=nr;
			nl->parent=cn;
			nr->parent=cn;
		//	printf("%c",nl->data);
		//	printf("%c",nr->data);
		//	printf("%c",nr->parent->data);
			push(s,cn);
		}
	}
	return s->top;
}
void inorder(sn s){
if(s!=NULL){
		inorder(s->left);
		printf("%c",s->data);
		inorder (s->right);
	}
}
void preorder(sn s){
if(s!=NULL){
		printf("%c",s->data);
		preorder(s->left);
		preorder (s->right);
	}
}
void postorder(sn s){
if(s!=NULL){
		postorder(s->left);
		postorder (s->right);
			printf("%c",s->data);
	}
}
int main(){
	char c;
	sn cn;
   while(1){
   	scanf("%c",&c);
   	if(c=='e'){
   		char e[200];
   		scanf("%s",e);
   		cn=construct_tree(e);
	   }
	   if(c=='i'){
	   	inorder(cn);
	   	printf("\n");
	   }
	   if(c=='p'){
	   	preorder(cn);
	   	printf("\n");
	   }
	   if(c=='s'){
	   	postorder(cn);
	   	printf("\n");
	   }
	   if(c=='t'){
	   	return 0;
	   }
   }
}
