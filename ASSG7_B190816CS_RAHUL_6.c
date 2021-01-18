#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct queue_node{
	char s1[50],s2[50];
	int page;
    float size;
    struct queue_node *next;
};
struct queue {
	struct queue_node *head;
	struct queue_node *tail;
	int q_len;
};
typedef struct queue_node *node;
typedef struct queue *qqueue;
node create_node(char st1[],char st2[],int p,float kb){
	node x;
	x=(node)malloc(sizeof(struct queue_node));
	int n,m;
	n=strlen(st1);
	m=strlen(st2);
	strcpy(x->s1,st1);
	strcpy(x->s2,st2);
	//printf("%d %d",n,m);
/*	for(int i=0;i<n;i++){
		x->s1[i]=st1[i];
	}
		for(int i=0;i<m;i++){
		x->s2[i]=st2[i];
	}*/
	x->page=p;
	x->size=kb;
	x->next=NULL;
	return x;
}
int queue_empty(qqueue q){
	if(q->head==NULL){
		return -1;
	}
	else
	return 1;
}
void add_request(qqueue q,node x){
	if(q->head==NULL){
		q->head=x;
	}
	else{
		q->tail->next=x;
	}
	q->tail=x;
}
void extract_next_request(qqueue q){
	if(queue_empty(q)==-1){
		printf("-1\n");
	}
	else{
		node p;
		p=q->head;
		q->head=p->next;
		printf("%s\n",p->s1);
	//	printf("%s\n",p->s2);
		free(p);
	}
}
void list_request(qqueue q){
	if(queue_empty(q)==-1){
		printf("-1\n");
	}
	else{
	node x;
	x=q->head;
	for(int i=0;i<q->q_len;i++){
		printf("%s ",x->s1);
	printf("%s ",x->s2);
		printf("%d ",x->page);
		printf("%f\n",x->size);
		x=x->next;}
	}
}
int main(){
	qqueue q;
	q=(qqueue)malloc(sizeof(struct queue));
	q->head=NULL;
	q->tail=NULL;
	q->q_len=0;
	node x;
	char c;
	char str1[50],str2[50];
	float f;
	int t;
	while(1){
		scanf("%c",&c);
		if(c=='a'){
			scanf("%s",str1);
		//	fflush(stdin);
			scanf("%s",str2);
		//	fflush(stdin);
	//	printf("%d",strlen(str2));
			scanf("%d",&t);
			scanf("%f",&f);
			x=create_node(str1,str2,t,f);
			add_request(q,x);
			q->q_len++;
		}
		if(c=='e'){
			extract_next_request(q);
			if(q->q_len!=-1){
				q->q_len--;
			}
		}
		if(c=='l'){
			list_request(q);
		}
		if(c=='t'){
			return 0;
		}
	}
}
