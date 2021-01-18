#include<stdio.h>
struct record{
		char name[15];
		int salary;
		int workpd;
		int finalsal;
		int cl;
	};
int computedeductions(struct record t[],char ename[15],int z){
		for(int i=0;i<z;i++){
			if(t[i].name==ename){
			 if(t[i].cl>5)
			  return ((t[i].cl-5)*1000);
			  else
			  return 0;
			}
		}
	}
void print_workperday(struct record t[],int k){
		for(int i=0;i<10;i++){
			if(t[i].salary!=0){
				if(t[i].workpd==k)
				printf("%s %d\n",t[i].name,t[i].finalsal);
			}
		}
	}
void print_finalsalary(struct record t[],int z){
	for(int i=0;i<z;i++){
			if(t[i].salary!=0){
				printf("%s %d\n",t[i].name,t[i].finalsal);
				int p=computedeductions(t,t[i].name,z);
				printf("%d\n",p);
			}
		}
}
void print_nonincrement(struct record t[],int z){
		for(int i=0;i<z;i++){
			if(t[i].salary==0){
			break;}
			else{
				if(t[i].workpd<8)
				printf("%s %d\n",t[i].name,t[i].salary);
			}
		}
	}
void insert(int i,struct record t[]){
  scanf("%s",t[i].name);
	scanf("%d%d%d",&t[i].salary,&t[i].workpd,&t[i].cl);
	if(t[i].workpd==8)
		t[i].finalsal=t[i].salary+50;
		else if(t[i].workpd==10)
			t[i].finalsal=t[i].salary+100;
			else if(t[i].workpd>10)
			t[i].finalsal=t[i].salary+150;
			else
			t[i].finalsal=t[i].salary;
   }
int main(){
  struct record t[10];
 
	char ip;
	int i=0;
	while(1){
    scanf("%c",&ip);
    if(ip=='t')
    break;
	 if(ip=='r'){
		insert(i,t);
		i++;
	}
	 if(ip=='i')
	print_nonincrement(t,i);
 if(ip=='f'){
	print_finalsalary(t,i);}
 if(ip=='w'){
		int k;
		scanf("%d",&k);
		print_workperday(t,k);
	}
 	
}}

