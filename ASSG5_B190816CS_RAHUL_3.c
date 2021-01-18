#include<stdio.h>
struct data{
	int ar;
	int n;
	int k;
};
void swap(int *x,int *y){
	int t;
	t=*x;
	*x=*y;
	*y=t;
}
void min_heapify(struct data a[],int i){
	int l,r,smallidx;
	l=2*i+1;
	r=2*i+2;
	if(l<a[0].k&&a[l].ar<a[i].ar){
		smallidx=l;
	}
	else
	smallidx=i;
	if(r<a[0].k&&a[r].ar<a[smallidx].ar)
	smallidx=r;
	if(smallidx!=i){
		swap(&a[i].ar,&a[smallidx].ar);
		min_heapify(a,smallidx);
	}
}
void build_min_heap(struct data a[]){
	a[0].k=a[0].n;
	int q=a[0].n;
	for(int i=(q/2)-1;i>=0;i--){
		min_heapify(a,i);
	}
}
void insert_patient(struct data a[],int d){
	a[(a[0].n)-1].ar=d;
	build_min_heap(a);
}
void extract_next_patient(struct data a[]){
	if(a[0].n==0)
	printf("-1\n");
	else{
		printf("%d\n",a[0].ar);
		a[0].ar=a[(a[0].n)-1].ar;
		a[0].n--;
		build_min_heap(a);
	}
}
void get_next_patient(struct data a[]){
	if(a[0].n==0)
	printf("-1\n");
	else
	printf("%d\n",a[0].ar);
}
void change_token_number(struct data a[],int p,int q){
	for(int i=0;i<a[0].n;i++){
		if(a[i].ar==p){
			a[i].ar=q;
			break;
		}
	}
	build_min_heap(a);
}
int partition(int b[],int s,int p,int e){
	int k=b[p];
	int t=s-1;
	int x;
	for(int i=s;i<=e-1;i++){
		if(b[i]<=k){
			t++;
			x=b[i];
			b[i]=b[t];
			b[t]=x;
		}
	}
	x=b[e];
	b[e]=b[t+1];
	b[t+1]=x;
	return t+1;
}
void quicksort(int a[],int s,int e){
	if(s<e){
		int p=partition(a,s,e,e);
		quicksort(a,s,p-1);
		quicksort(a,p+1,e);
	}
}
void display_queue(struct data a[]){
	int k=a[0].n;
	int b[k];
	for(int i=0;i<k;i++){
		b[i]=a[i].ar;
	}
	quicksort(b,0,k-1);
	for(int i=0;i<k;i++){
		printf("%d " ,b[i]);
	}
	printf("\n");
}
int main(){
	char c;
	struct data a[100000];
	a[0].n=0;
	while(1){
		scanf("%c",&c);
		if(c=='i'){
		int d;
			a[0].n++;
			scanf("%d",&d);
		insert_patient(a,d);
		}
		if(c=='e'){
			extract_next_patient(a);
		}
		if(c=='m'){
			get_next_patient(a);
		}
		if(c=='c'){
			int p,q;
			scanf("%d%d",&p,&q);
			change_token_number(a,p,q);
		}
		if(c=='d'){
			display_queue(a);
		}
		if(c=='s')
		return 0;
	}
}
