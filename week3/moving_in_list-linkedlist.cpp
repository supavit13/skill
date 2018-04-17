#include<iostream>
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
void print(struct rec *head){
    tmp=head;
    if(head==NULL){
        cout<<"Empty Set.";
    }
    while(tmp){
        cout<<tmp->value<<endl;
//        cout<<tmp->value<<" ";
        tmp=tmp->next;
    }
//    cout<<endl;
}
void printB(struct rec *head){
    tmp=tail;
    if(head==NULL){
        cout<<"Empty Set.";
    }
    while(tmp){
//        cout<<tmp->value<<endl;
        cout<<tmp->value<<" ";
        tmp=tmp->prev;
    }
    cout<<endl;
}
struct rec *calculate(struct rec *head){
	int first=0,last=0;
	char cmd;
	cin>>cmd;
	cin>>first;
	cin>>last;
//	if(first<last){
//		tmp=head;
//		p=tail;
//		while(tmp->value!=first) tmp=tmp->next;
//		while(p->value!=last) p=p->prev;
//	}else if(first>last){
//		tmp=tail;
//		p=head;
//		while(tmp->value!=last) tmp=tmp->prev;
//		while(p->value!=first) p=p->next;
//	}else {
//		return head;
//	}
	tmp=head;
	p=tail;
	while(tmp->value!=first){
		tmp=tmp->next;
	}
	while(p->value!=last){
		p=p->prev;
	}
	if(cmd=='A'&&tmp->value==tail->value&&p->value==head->value){
		tail=tail->prev;
		tail->next=NULL;
		p->prev=tmp;
		tmp->next=p;
		head=head->prev;
		head->prev=NULL;
	}
	else if(cmd=='A'&&tmp->value==head->value){
		head=head->next;
		head->prev=NULL;
		p->prev->next=tmp;
		tmp->prev=p->prev;
		tmp->next=p;
		p->prev=tmp;
	}else if(cmd=='A'&&tmp->value==tail->value){
		tail=tail->prev;
		tail->next=NULL;
		p->prev->next=tmp;
		tmp->prev=p->prev;
		tmp->next=p;
		p->prev=tmp;
	}
	else if(cmd=='A'&&p->value==head->value){
		tmp->next->prev=tmp->prev;
		tmp->prev->next=tmp->next;
		p->prev=tmp;
		tmp->next=p;
		head=head->prev;
		head->prev=NULL;
	}
	else if(cmd=='A'){
		tmp->next->prev=tmp->prev;
		tmp->prev->next=tmp->next;
		p->prev->next=tmp;
		tmp->prev=p->prev;
		tmp->next=p;
		p->prev=tmp;
	}
	else if(cmd=='B'&&p->value==tail->value&&tmp->value==head->value){
		tail=tail->prev;
		tail->next=NULL;
		tmp->prev=p;
		p->next=tmp;
		head=head->prev;
		head->prev=NULL;
	}
	else if(cmd=='B'&&p->value==tail->value){
		tail=tail->prev;
		tail->next=NULL;
		tmp->prev->next=p;
		p->prev=tmp->prev;
		tmp->prev=p;
		p->next=tmp;
	}
	else if(cmd=='B'&&p->value==head->value){
		head=head->next;
		head->prev=NULL;
		tmp->prev->next=p;
		p->prev=tmp->prev;
		tmp->prev=p;
		p->next=tmp;
	}
	else if(cmd=='B'&&tmp->value==head->value){
		p->next->prev=p->prev;
		p->prev->next=p->next;
		tmp->prev=p;
		p->next=tmp;
		head=head->prev;
		head->prev=NULL;
	}
	else if(cmd=='B'){
		p->next->prev=p->prev;
		p->prev->next=p->next;
		tmp->prev->next=p;
		p->prev=tmp->prev;
		tmp->prev=p;
		p->next=tmp;
		
	}
	
	return head;
}
int main(){
	struct rec *head=NULL;
	int n=0,k=0;
	cin>>n;
	cin>>k;
	for(int i=0;i<n;i++){
		head=insert(head,i+1);
	}
	for(int i=0;i<k;i++){
		head=calculate(head);
//		print(head);
//		printB(head);
	}
	print(head);
//	printB(head);
}
