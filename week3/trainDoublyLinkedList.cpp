#include<iostream>
#include<stdio.h>
using namespace std;
struct rec{
    int value;
    struct rec *next;
    struct rec *prev;
};
struct rec *tail;
struct rec *tmp,*p;
struct rec *insert(struct rec *head,int data){
    if(head==NULL){
        head=new rec;
        head->value=data;
        head->next=NULL;
        head->prev=NULL;
        tail=head;
        return head;
    }else{
    	tmp =new rec;
    	tmp->value=data;
    	tmp->next=NULL;
    	tail->next=tmp;
    	tmp->prev=tail;
    	tail=tmp;
	}
    return head;
}
struct rec * searchfront(struct rec *tmp,int first){
	if(tmp->value!=first&&tmp!=NULL){
		return searchfront(tmp->next,first);
	}else{
		return tmp;
	}
}
struct rec * searchback(struct rec *p,int last){
	if(p->value!=last&&p!=NULL){
		return searchback(p->prev,last);
	}else{
		return p;
	}
}
void print(struct rec *head){
    tmp=head;
    if(head==NULL){
        cout<<"Empty Set.";
    }
    while(tmp){
//        cout<<tmp->value<<" ";
        cout<<tmp->value<<endl;
        tmp=tmp->next;
    }
}
void printback(struct rec *head){
    tmp=tail;
    if(head==NULL){
        cout<<"Empty Set.";
    }
    while(tmp){
        cout<<tmp->value<<" ";
        tmp=tmp->prev;
    }
}
struct rec *calculate(struct rec *head,int first,int last){
	tmp=NULL;
	p=NULL;
	tmp=head;
//	while(tmp!=NULL&&tmp->value!=first){
//		tmp=tmp->next;
//	}
	tmp=searchfront(tmp,first);
	p=tail;
	p=searchback(p,last);
//	cout<<"pass loop"<<endl;
//	cout<<"last = "<<last<<endl;
//	while(p!=NULL&&p->value!=last){
////		cout<<"node "<<p->value<<" ";
//		p=p->prev;
//	}
//	if(tmp==NULL) return head;
//	if(p==NULL) return head;
	if(first==head->value){
		tail->next=head;
		tmp->prev=tail;
		head=p->next;
		tail=p;
		head->prev=NULL;
		tail->next=NULL;
		return head;
	}
	if(last==tail->value){
		return head;
	}
	tmp->prev->next=p->next;
	p->next->prev=tmp->prev;
	tail->next=tmp;
	tmp->prev=tail;
	tail=p;
	tail->next=NULL;
	return head;
}
int main(){
	struct rec *head=NULL;
	int n=0,k=0;
	int x=0,y=0;
	cin>>n;
	cin>>k;
	for(int i=0;i<n;i++){
		head=insert(head,i+1);
	}
	for(int i=0;i<k;i++){
		cin>>x>>y;
		head=calculate(head,x,y);
//		print(head);cout<<endl;
//		printback(head);cout<<endl;
//		cout<<"head = "<<head->value<<" tail = "<<tail->value<<endl;
	}
	print(head);
}
