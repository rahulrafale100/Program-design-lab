#include<stdio.h>
#include<stdlib.h>
struct queue{
	int head;
	int tail;
	int *elem;
	int size;
};
typedef struct queue qt;
int queue_full(qt *q){
	if(q->head==(q->tail+1)%q->size)
	return -1;
	else
	return 1;
}
int queue_empty(qt *q){
	if(q->head==q->tail)
	return -1;
	else
	return 1;
}
void enqueue(qt *q,int k){
	if(queue_full(q)!=-1){
		q->elem[q->tail]=k;
		q->tail=(q->tail+1)%q->size;
	}
}
void dequeue(qt *q ){
	if(queue_empty(q)==-1)
	printf("-1\n");
	else{
	printf("%d\n",q->elem[q->head]);
	q->head=q->head+1;}
}
int main(){
	struct queue q;
	q.head=0;
	q.tail=0;
	int n;
	scanf("%d",&n);
	q.size=n+1;
	q.elem=(int*)malloc((n+1)*(sizeof(int)));
	char c;
	int k;
	while(1){
		scanf("%c",&c);
		if(c=='i'){
			scanf("%d",&k);
			enqueue(&q,k);
		}
		if(c=='d'){
			dequeue(&q);
		}
		if(c=='f'){
			int t=queue_full(&q);
			printf("%d\n",t);
		}
		if(c=='e'){
			int t=queue_empty(&q);
			printf("%d\n",t);
		}
		if(c=='t'){
			return 0;
		}
	}
}
