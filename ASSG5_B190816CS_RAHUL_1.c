#include<stdio.h>
struct size{
	int ar;
	int n;
	int k;
};
int c=0;
void max_heapify(struct size  a[],int i){
	int l,r,largeidx;
	l=2*i+1;
	r=2*i+2;
	if(l<a[0].k&&a[l].ar>a[i].ar){
		largeidx=l;
		c++;
	}
	else{
		largeidx=i;
		if(l<a[0].k)
		c++;
	}
	if(r<a[0].k&&a[r].ar>a[largeidx].ar){
		largeidx=r;
		c++;
	}
	else{
		if(r<a[0].k)
	c++;}
	if(largeidx!=i){
//	swap(&a[i].ar,&a[largeidx].ar);
	int t;
	t=a[i].ar;
	a[i].ar=a[largeidx].ar;
	a[largeidx].ar=t;
		max_heapify(a,largeidx);
	}
}
void build_max_heap(struct size a[]){
	a[0].k=a[0].n;
	int q=a[0].n;
	for(int i=(q/2)-1;i>=0;i--){
		max_heapify(a,i);
	}
}
void heapsort(struct size a[]){
	build_max_heap(a);
	int t;
	t=a[0].n;
	for(int i=t-1;i>0;i--){
//	swap(&a[i],&a[0]);
	int t;
	t=a[i].ar;
	a[i].ar=a[0].ar;
	a[0].ar=t;
		a[0].k--;
		max_heapify(a,0);
	}
}
int main(){
	int p;
	scanf("%d",&p);
	struct size a[p];
	a[0].n=p;
 	for(int i=0;i<p;i++){
		scanf("%d",&a[i].ar);
	}
	heapsort(a);
		for(int i=0;i<p;i++){
		printf("%d ",a[i].ar);
	}
	printf("\n%d",c);
	return 0;
}
