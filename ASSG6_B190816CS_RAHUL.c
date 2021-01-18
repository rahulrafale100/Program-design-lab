#include<stdio.h>
#include<stdlib.h>
struct linked_list_node {
	int data;
	struct linked_list_node *next;
};
struct linked_list{
	struct linked_list_node* head;
};
typedef struct linked_list_node *node;
typedef struct linked_list *list;
node list_search(node head,int k){
	node q=head;int x=0;
	while(q->data!=k&&q->next!=NULL){
		q=q->next;
	}
	if(q->data==k){
		return q;
	}
	else
	return NULL;
}
node create_node(int value){
	node temp;
	temp=(node)malloc(sizeof(struct linked_list_node));
	if(temp==NULL){
		printf("Error in creating node\n");
		exit(0);
	}
	temp->data=value;
	temp->next=NULL;
	return temp;
}
node list_insert_front(node head ,int value){
	node new_head;
	new_head=create_node(value);
	new_head->next=head;
	head=new_head;
	return new_head;
}
node list_insert_tail(node head,int value){
	node new_node,t;
	new_node=create_node(value);
	if(head==NULL){
		head=new_node;
	}
	else{
		t=head;
		while(t->next!=NULL)
		t=t->next;
	t->next=new_node;
	return head;
	}
}
node list_insert_after(node head,node x,node  y){
	node temp,p;
	temp=x;
	p=y;
   temp->next=p->next;
   p->next=temp;
   return head;
}
node list_insert_before(node head,node x,node y){
	node temp,p,q;
	temp=x;
	if(head==y){
	temp->next=head;
	head=temp;
	}
	else{
	p=head;
	q=NULL;
	while(p!=y){
		q=p;
		p=p->next;
	}
	temp->next=q->next;
	q->next=temp;}
	return head;
}
node list_delete(node head,int k){
	node temp,p,q;int x=0;
	if(head->data==k){
		printf("%d\n",k);
		p=head;
		free(p);
		head=NULL;
		x=1;
	}
	else{
		p=head;
		q=NULL;
		while(p->data!=k&&p->next!=NULL){
		q=p;
		p=p->next;
	}
	if(p->data==k){
	q->next=p->next;
	printf("%d\n",k);
	free(p);
	x=1;}
	}
	if(x==0)
	printf("%d\n",-1);
	return head;
}
node list_delete_first(node head){
	node p;
	if(head==NULL){
		printf("%d\n",-1);
	}
	else{
		p=head;
		head=p->next;
		printf("%d\n",p->data);
		free(p);
	}
	return head;
}
node list_delete_last(node head){
	node p,q=NULL;
	p=head;
	if(head==NULL){
		printf("%d\n",-1);
	}
	else{
	while(p->next!=NULL){
		q=p;
		p=p->next;
	}
	if(q!=NULL)
	q->next=NULL;
	if(p==head)
	head=NULL;
	printf("%d\n",p->data);
	free(p);
	}
	return head;
}
int main(){
	list llist;
	llist=(list)malloc(sizeof(struct linked_list));
	llist->head=NULL;
	node head_pro;
	char c;
	int k,m;
	while(1){
		scanf("%c",&c);
		if(c=='f'){
			scanf("%d",&k);
			head_pro=list_insert_front(llist->head ,k);
			llist->head=head_pro;
		}
		if(c=='t'){
			scanf("%d",&k);
			head_pro=list_insert_tail(llist->head,k);
			llist->head=head_pro;
		}
		if(c=='a'){
			scanf("%d%d",&k,&m);
			node c,d;
		   c=create_node(k);
		   d=list_search(m);
			head_pro=list_insert_after(llist->head,c,d);
			llist->head=head_pro;
		}
		if(c=='b'){
		scanf("%d%d",&k,&m);
		node c,d;
		c=create_node(k);
		d=list_search(m);
		head_pro=list_insert_before(llist->head,c,d);
		llist->head=head_pro;}
		if(c=='d'){
			scanf("%d",&k);
			head_pro=list_delete(llist->head,k);
			llist->head=head_pro;
		}
		if(c=='i'){
			head_pro=list_delete_first(llist->head);
			llist->head=head_pro;
		}
		if(c=='l'){
			head_pro=list_delete_last(llist->head);
			llist->head=head_pro;
		}
		if(c=='s'){
			scanf("%d",&k);
			head_pro=list_search(llist->head,k);
			if(head_pro!=NULL){
				printf("%d\n",1);
			}
			else
			printf("%d\n",-1);
		}
		if(c=='e')
		return 0;
	}
}
