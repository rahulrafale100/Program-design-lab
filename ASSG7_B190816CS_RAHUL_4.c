#include<stdio.h>
#include<stdlib.h>
struct queue_node{
	int data;
	struct queue_node *next;
};
struct queue{
	struct queue_node *head;
	struct queue_node *tail;
};
typedef struct queue_node *node;
typedef struct queue *queue;
node create_node(int k){
	node x;
	x=(node)malloc(sizeof(struct queue_node));
	x->data=k;
	x->next=NULL;
	return x;
}
int empty_queue(queue q){
	if(q->head==NULL){
		return -1;
	}
	else
	return 1;
}
void enqueue(queue q,node x){
	if(q->head==NULL){
		q->head=x;
	}else{
		q->tail->next=x;
	}
	q->tail=x;
}
void dequeue(queue q){
	node p;
	if(empty_queue(q)==-1)
	printf("-1\n");
	else{
	p=q->head;
	q->head=p->next;
	printf("%d\n",p->data);
	free(p);}
}
int main(){
	queue q;
	q=(queue)malloc(sizeof(struct queue));
	q->head=NULL;
	q->tail=NULL;
	node x,head_pro,tail_pro;
	char c;
	int k;
	while(1){
		scanf("%c",&c);
		if(c=='i'){
			scanf("%d",&k);
			x=create_node(k);
			enqueue(q,x);
		}
		if(c=='d'){
			dequeue(q);
		}
		if(c=='e'){
			int d;
			d=empty_queue(q);
			if(d==-1){
				printf("-1\n");
			}
			else
			printf("1\n");
		}
		if(c=='t'){
			return 0;
		}
	}
}

