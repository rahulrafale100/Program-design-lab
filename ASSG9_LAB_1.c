#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct bst_node{
	int data;
	struct bst_node *left;
	struct bst_node *right;
	struct bst_node *parent;
};
struct bst{
	struct bst_node *root;
};
typedef struct bst_node *bn;
typedef struct bst *bst;
bn create_node(int k){
	bn p;
	p=(bn)malloc(sizeof(struct bst_node));
	p->data=k;
	p->parent=NULL;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void  insert(bst z,bn x){
 bn y=NULL;
 bn p=z->root;
 while(p!=NULL){
 	y=p;
 	if(x->data<p->data){
 		p=p->left;
	 }
	 else
	 p=p->right;}
	x->parent=y;
	if(y==NULL){
		z->root=x;
	}
	else if(x->data<y->data)
	 y->left=x;
	 else
	 y->right=x;
 
}
bn search (bn z,int k){
	if(z==NULL||z->data==k){
		return z;
	}
	else if(k<z->data){
		return search(z->left,k);
	}
	else{
		return search(z->right,k);
	}	
}
void  transplant(bst z, bn u,bn v){
	if(u->parent==NULL)
	 z->root=v;
	 else if( u==u->parent->left)
	  u->parent->left=v;
	  else
	  u->parent->right=v;
	   if(v!=NULL){
	   	v->parent=u->parent;
	   }
}
bn tree_minimum( bn z){
	while(z->left!=NULL){
		z=z->left;
	}
	return z;
}
void  delete_node(bst t,bn z){
	bn y;
	if(z->left==NULL)
	transplant(t,z,z->right);
	 else if(z->right==NULL)
	   transplant(t,z,z->left);
	   else {
	   	y=tree_minimum(z->right);
	   	if(y->parent!=z){
	   		transplant(t, y,y->right);
	   		y->right=z->right;
	   		y->right->parent=y;}
	   	transplant(t,z,y);
	   	y->left=z->left;
		   y->left->parent=y;	
	   }
	   printf("%d\n",z->data);
	   free(z);
}
void inorder(bn z){
	if(z!=NULL){
		inorder(z->left);
		printf("%d ",z->data);
		inorder(z->right);
	}
}
void preorder(bn z){
		if(z!=NULL){
		
		printf("%d ",z->data);
		preorder(z->left);
		preorder(z->right);
	}
}
void postorder(bn z){
	if(z!=NULL){
		postorder(z->left);
		postorder(z->right);
		printf("%d ",z->data);
	}
}
void combine1(bst T1,int k,bst T2){
	bst T3;
	T3=(bst)malloc(sizeof(struct bst));
	bn x;
	x=create_node(k);
	x->left=T1->root;
	x->right=T2->root;
	if(T1->root!=NULL)
	T1->root->parent=x;
	if(T2->root!=NULL)
	T2->root->parent=x;
	free(T1);
	free(T2);
	T3->root=x;
	inorder(T3->root);
}	
int main(){
	bst T1,T2;
	T1=(bst)malloc(sizeof(struct bst));
	T2=(bst)malloc(sizeof(struct bst));
	T1->root=NULL;
	T2->root=NULL;
	bn x;
	int k;
	char in1[50];
	char in2[50];
	gets(in1);
//	scanf("%s",in1);
	//scanf("%[^\n]%c",in1);
//	fflush(stdin);
   gets(in2);
//	scanf("%[^\n]%c",in2);
//scanf("%s",in2);  
	scanf("%d",&k);
    int n1,n2,p,q=0,c=0;
    n1=strlen(in1);
    n2=strlen(in2);
//   printf("%d %d ",n1,n2);
   if(n1!=0){
    for(int i=0;i<n1;i++){
    	if(in1[i]!=' '){
    	p=in1[i]-48;
    	q=p+(int)pow(10,c)*q;
		c++;
		}
		else{
		//printf("%d ",q);
			x=create_node(q);
		insert(T1,x);
			q=0;c=0;
		}
		if(i==n1-1){
			if(q!=0){
				x=create_node(q);
		insert(T1,x);}
			q=0;c=0;
		}
	}}
	//inorder(T1->root);
	if(n2!=0){
    for(int i=0;i<n2;i++){
    	if(in2[i]!=' '){
    	p=in2[i]-'0';
    	q=p+(int)pow((10),(c))*q;
		c++;
		}
		else{
		//	printf("%d ",q);
			x=create_node(q);
		insert(T2,x);
			q=0;c=0;
		}
			if(i==n2-1){
				if(q!=0){
				x=create_node(q);
		insert(T2,x);}
			q=0;c=0;
		}
	}}
//	inorder(T2->root);
	combine1(T1,k,T2);
	}
