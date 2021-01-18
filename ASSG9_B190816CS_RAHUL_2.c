#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct bst_node{
	int modal_no;
	char name[50];
	int price;
	struct bst_node *left;
	struct bst_node *right;
	struct bst_node *parent;
};
struct bst{
	struct bst_node *root;
};
typedef struct bst_node *bn;
typedef struct bst *bst;
bn create_node(int k,char n[],int pr){
	bn p;
	p=(bn)malloc(sizeof(struct bst_node));
	p->modal_no=k;
	strcpy(p->name,n);
	p->price=pr;
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
 	if(x->modal_no<p->modal_no){
 		p=p->left;
	 }
	 else
	 p=p->right;}
	x->parent=y;
	if(y==NULL){
		z->root=x;
	}
	else if(x->modal_no<y->modal_no)
	 y->left=x;
	 else
	 y->right=x;
 
}
bn search (bn z,int k){
	if(z==NULL||z->modal_no==k){
		return z;
	}
	else if(k<z->modal_no){
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
	   printf("%d %s %d\n",z->modal_no,z->name,z->price);
	   free(z);
}
void inorder(bn z){
	if(z!=NULL){
		inorder(z->left);
		printf("%d %s %d\n",z->modal_no,z->name,z->price);
		inorder(z->right);
	}
}	
void modify(bn cn ,int p){
	cn->price=p;
}
int main(){
	bst z;
	z=(bst)malloc(sizeof(struct bst));
	z->root=NULL;
	char c;
	char n[50];
	int p;
	bn cn;
	while(1){
		scanf("%c",&c);
		if(c=='a'){
			int k;
			scanf("%d",&k);
			scanf("%s",n);
			scanf("%d",&p);
		  cn=create_node(k,n,p);
		  insert(z,cn);
		  //preorder(z->root);	
		}
		if(c=='s'){
			int k;
			scanf("%d",&k);
			cn=search(z->root,k);
			if(cn==NULL){
				printf("%d\n",-1);
			}
			if(cn!=NULL){
				printf("%d %s %d\n",cn->modal_no,cn->name,cn->price);
			}
		}
		if(c=='d'){
			int k;
			scanf("%d",&k);
			cn=search(z->root,k);
			if(cn!=NULL)
			delete_node(z,cn);
			else
			printf("-1\n");
			}
		if(c=='i'){
			inorder(z->root);
		
		}
		if(c=='m'){
			int k;
			scanf("%d%d",&k,&p);
			cn =search(z->root,k);
			modify(cn,p);
		}
		if(c=='e')
		return 0;
		}
	}
