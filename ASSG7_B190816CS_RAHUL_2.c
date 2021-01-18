#include<stdio.h>
#include<stdlib.h>
struct stack_node{
	int data;
	struct stack_node *next;
};
struct stack{
	struct stack_node *top;
};
typedef struct stack_node *sn;
typedef struct stack *st;
sn create_node(int k){
	sn new_node;
	new_node=(sn)malloc(sizeof(struct stack_node));
	new_node->data=k;
	new_node->next=NULL;
	return new_node;
}
sn push(sn top,sn node){
	sn new_node;
	new_node=node;
	new_node->next=top;
	top=new_node;
	return top;
}
sn pop(sn top){
	sn node1;
	if(top==NULL)
	printf("-1\n");
	else{
	node1=top;
	top=node1->next;
	printf("%d\n",node1->data);
	free(node1);}
	return top;
}
void stack_empty(sn top){
	if(top==NULL){
		printf("-1\n");
	}
	else
	printf("1\n");
}
int main(){
	st s;
	s=(st)malloc(sizeof(struct stack));
	s->top=NULL;
	char c;
	int k;
	sn cn,top_pro;
	while(1){
    scanf("%c",&c);
     if(c=='i'){
     	scanf("%d",&k);
     	cn=create_node(k);
     	top_pro=push(s->top,cn);
     	s->top=top_pro;
	 }
	 if(c=='d'){
	 	top_pro=pop(s->top);
	 	s->top=top_pro;
	 }
	 if(c=='e'){
	 	stack_empty(s->top);
	 }
	 if(c=='t')
	 return 0;
	}
	
}
