#include<iostream>
#include<stdio.h>
using namespace std;
struct rec{
    int value;
    struct rec *next;
    struct rec *prev;
};
struct rec *head=NULL;
struct rec *tail;
struct rec *tmp,*p;
struct rec *insert(int data){
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
    	return tmp;
	}
//    return head;
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
int main(){
	
	int n=0,k=0;
	int x=0,y=0;
	cin>>n;
	cin>>k;
	struct rec *pt[n];
	for(int i=0;i<n;i++){
		pt[i]=insert(i+1);
	}
//	print(head);
//	for(int i=0;i<n;i++){
//		cout<<pt[i]->value<<endl;
//	}
	for(int i=0;i<k;i++){
		cin>>x>>y;
		int f=x-1;
		int s=y-1;
		if(pt[f]->value==head->value){
			tail->next=head;
			pt[f]->prev=tail;
			head=pt[s]->next;
			tail=pt[s];
			head->prev=NULL;
			tail->next=NULL;
			continue;
		}
		if(pt[s]->value==tail->value){
			continue;
		}
		pt[f]->prev->next=pt[s]->next;
		pt[s]->next->prev=pt[f]->prev;
		tail->next=pt[f];
		pt[f]->prev=tail;
		tail=pt[s];
		tail->next=NULL;
	}
	print(head);
}
