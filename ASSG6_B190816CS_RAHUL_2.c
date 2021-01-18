#include<stdio.h>
#include<stdlib.h>
struct linked_list_node{
	int data;
	struct linked_list_node *next;
	struct linked_list_node *prev;
};
struct linked_list{
	struct linked_list_node *head;
};
typedef struct linked_list_node *node;
typedef struct linked_list *list;
node create_node(int value){
	node temp;
	temp=(node)malloc(sizeof(struct linked_list_node));
	if(temp==NULL){
		printf("Error in creating node\n");
		exit(0);
	}
	temp->data=value;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}
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
node list_insert_front(node head,node x){
	x->next=head;
	if(head!=NULL)
	head->prev=x;
	head=x;
	return head;
}
node list_insert_tail(node head,node x){
	node p;
	p=head;
	if(head==NULL){
		head=x;
	}
	else{
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=x;
	x->prev=p;
	}
	return head;
}
node list_insert_after(node head,node x,node y){
	x->next=y->next;
	y->next=x;
	x->prev=y;
	if(x->next!=NULL)
	x->next->prev=x;
	return head;
}	
node list_insert_before(node head,node x,node y){
	if(head==y){
		y->prev=x;
		x->next=y;
		head=x;
	}
	else{
	x->next=y;
	x->prev=y->prev;
	y->prev->next=x;
	y->prev=x;}
	return head;
}
node list_delete(node head,node x){
	node p;int z=0;
	if(head==x){
		head=x->next;
		printf("%d\n",x->data);
		z=1;
	  free(x);
	}
	else{
		p=head;
		while(p!=x&&p->next!=NULL)
		p=p->next;
		if(p==x){
			printf("%d\n",x->data);
			z=1;
			x->prev->next=x->next;
				if(x->next!=NULL)
	x->next->prev=x->prev;
		}
		free(x);
	}
	if(z==0){
		printf("%d\n",-1);
	}
	return head;
}
node list_delete_initial(node head){
	node p;
	if(head==NULL){
		printf("%d\n",-1);
	}
	else{
	p=head;
	if(p->next!=NULL){
	p->next->prev=NULL;
	head=p->next;}
	else
	head=NULL;
	printf("%d\n",p->data);
	free(p);}
	return head;
}
node list_delete_last(node head){
	node p;
	if(head==NULL){
		printf("%d\n",-1);
	}
	else{
		p=head;
		while(p->next!=NULL){
			p=p->next;
		}
		printf("%d\n",p->data);
		if(p->prev==NULL)
		head=NULL;
		else
		p->prev->next=NULL;
		free(p);
	}
	return head;
}
int main(){
	list llist;
	llist=(list)malloc(sizeof(struct linked_list));
	llist->head=NULL;
	node head_pro ,x,y;
	char c;
	int k,m;
	while(1){
		scanf("%c",&c);
		if(c=='f'){
			scanf("%d",&k);
			x=create_node(k);
			head_pro=list_insert_front(llist->head,x);
			llist->head=head_pro;
		}
		if(c=='t'){
			scanf("%d",&k);
			x=create_node(k);
			head_pro=list_insert_tail(llist->head,x);
			llist->head=head_pro;
		}
		if(c=='a'){
			scanf("%d%d",&k,&m);
			x=create_node(k);
			y=list_search(llist->head,m);
			head_pro=list_insert_after(llist->head,x,y);
			llist->head=head_pro;
		}
		if(c=='b'){
			scanf("%d%d",&k,&m);
			x=create_node(k);
			y=list_search(llist->head,m);
			head_pro=list_insert_before(llist->head,x,y);
			llist->head=head_pro;
		}
		if(c=='d'){
			scanf("%d",&k);
			x=list_search(llist->head,k);
			if(x==NULL){
				printf("%d\n",-1);
			}
			else{
			head_pro=list_delete(llist->head,x);
			llist->head=head_pro;}
		}
		if(c=='i'){
			head_pro=list_delete_initial(llist->head);
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
