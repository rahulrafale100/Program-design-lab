#include<stdio.h>
struct size{
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
void min_heapify(struct size a[],int i){
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
void build_min_heap(struct size a[]){
	a[0].k=a[0].n;
	int t=a[0].n;
	for(int i=(t/2)-1;i>=0;i--){
		min_heapify(a,i);
	}
}
void min_heap_insert(struct size a[],int d){
	a[(a[0].n)-1].ar=d;
	build_min_heap(a);
}
void heap_extract_min(struct size a[]){
	if(a[0].n==0)
	printf("-1\n");
	else{
		printf("%d\n",a[0].ar);
		a[0].ar=a[(a[0].n)-1].ar;
		a[0].n=(a[0].n)-1;
		build_min_heap(a);
	}
}
void heap_minimum(struct size a[]){
	if(a[0].n==0)
	printf("-1\n");
	else
	printf("%d\n",a[0].ar);
}
void heap_decrease_key(struct size a[],int p,int q){
	a[p].ar=q;
	while(p>0&&a[p/2].ar>a[p].ar){
		swap(&a[p].ar,&a[p/2].ar);
		p=p/2;
	}
}
int main(){
	char c;
	int p=0;
	struct size a[100000];
	a[0].n=0;
	while(1){
		scanf("%c",&c);
		if(c=='i'){
		int d;
			a[0].n++;
			scanf("%d",&d);
		min_heap_insert(a,d);
		}
		if(c=='e'){
			heap_extract_min(a);
		}
		if(c=='m'){
			heap_minimum(a);
		}
		if(c=='d'){
			int p,q;
			scanf("%d%d",&p,&q);
			heap_decrease_key(a,p,q);
		}
		if(c=='s')
		return 0;
	}
}
