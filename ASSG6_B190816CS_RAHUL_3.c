#include<stdio.h>
#include<stdlib.h>
struct pcb_node {
	int data;
	char st[20];
	struct pcb_node *next;
};
struct pcb_list{
	struct pcb_node* head;
};
typedef struct pcb_node *node;
typedef struct pcb_list *list;
node list_search(node head,int k){
	node q=head;
	if(head==NULL){
		return NULL;
	}
	else{
	while(q->data!=k&&q->next!=NULL){
		q=q->next;
	}
	if(q->data==k){
		return q;
	}
	else
	return NULL;}
}
node create_node(int value){
	node temp;
	temp=(node)malloc(sizeof(struct pcb_node));
	if(temp==NULL){
		printf("Error in creating node\n");
		exit(0);
	}
	temp->data=value;
	temp->next=NULL;
	return temp;
}
node insert(node head ,node value){
	node new_head;
	new_head=value;
	new_head->next=head;
	head=new_head;
	return new_head;
}
node delete_(node head,node k){
	node temp,p,q;int x=0;
	if(head==k){
		printf("%d\n",k->data);
		p=head;
		free(p);
		head=NULL;
		x=1;
	}
	else{
		p=head;
		q=NULL;
		while(p!=k&&p->next!=NULL){
		q=p;
		p=p->next;
	}
	if(p==k){
	q->next=p->next;
	printf("%d\n",k->data);
	free(p);
	x=1;}
	}
	if(x==0)
	printf("%d\n",-1);
	return head;
}
void get_state(node head ,int k){
	node p;int z=0;
	p=head;
	if(head==NULL){
		printf("%d\n",-1);
	}
	else{
	while(p->data!=k&&p->next!=NULL){
		p=p->next;
	}
	if(p->data==k){
		printf("%s\n",p->st);
		z=1;
	}
	}
	if(z==0)
	printf("%d\n",-1);
}
void list_waiting_process(node head){
	node p;int z=0;
	p=head;
	while(p->next!=NULL){
		if(p->st[0]=='w'){
		printf("%d ",p->data);
		z=1;}
		p=p->next;
	}
	if(z==0){
		printf("%d\n",-1);
	}
	else
	printf("\n");
}
int main(){
	list llist;
	llist=(list)malloc(sizeof(struct pcb_list));
	llist->head=NULL;
	node head_pro,ct,d;
	char c;
	int k;
	char str[20];
	while(1){
		scanf("%c",&c);
		if(c=='i'){
			scanf("%d",&k);
			ct=create_node(k);
			scanf("%s",&ct->st);
			head_pro=insert(llist->head ,ct);
			llist->head=head_pro;
		}
		if(c=='d'){
			scanf("%d",&k);
			ct=list_search(llist->head,k);
			if(ct==NULL){
				printf("%d\n",-1);
			}
			else{
			head_pro=delete_(llist->head,ct);
			llist->head=head_pro;}
		}
	    if(c=='g'){
	    	scanf("%d",&k);
	    	get_state(llist->head,k);
		}
		if(c=='l'){
		 list_waiting_process(llist->head);
		}
		if(c=='u'){
			scanf("%d",&k);
			ct=list_search(llist->head,k);
			scanf("%s",&ct->st);
		}
		if(c=='e'){
			return 0;
		}
	}
}
