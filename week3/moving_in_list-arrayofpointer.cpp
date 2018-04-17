#include<iostream>
using namespace std;
struct rec{
    int value;
    struct rec *next;
    struct rec *prev;
};
struct rec *head=NULL;
struct rec *tail=NULL;
struct rec *tmp=NULL;
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
    while(tmp->next!=NULL){
        cout<<tmp->value<<endl;
//        cout<<tmp->value<<" ";
        tmp=tmp->next;
    }
    cout<<tmp->value;
//    cout<<endl;
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
	cin>>n;
	cin>>k;
	struct rec *pt[n];
	for(int i=0;i<n;i++){
		pt[i]=insert(i+1);
	}
//	tmp=head;
//	for(int i=0;i<n;i++){
//		pt[i]=tmp;
//		tmp=tmp->next;
//	}
	for(int i=0;i<k;i++){
		int x=0,y=0;
		char cmd=' ';
		cin>>cmd;
		cin>>x>>y;
		int f=x-1;
		int s=y-1;
		if(cmd=='A'){ 
			if(pt[f]->value==tail->value && pt[s]->value==head->value&&tail->prev==pt[s]){
				pt[f]->next=pt[s];
				pt[s]->prev=pt[f];
				pt[f]->prev=NULL;
				pt[s]->next=NULL;
				head=pt[f];
				tail=pt[s];
			}
			else if(pt[f]->value==tail->value && pt[s]->value==head->value){
				pt[f]->prev->next=NULL;
				tail=pt[f]->prev;															
				pt[f]->next=pt[s];
				pt[s]->prev=pt[f];
				pt[f]->prev=NULL;
				head=pt[f];							
			}
			else if(pt[f]->value==head->value && pt[s]->prev->value==head->value){
				continue;
			}
			else if(pt[f]->value==head->value){
				pt[f]->next->prev=NULL;
				head=pt[f]->next;												
				pt[f]->next=pt[s];
				pt[s]->prev->next=pt[f];
				pt[f]->prev=pt[s]->prev;
				pt[s]->prev=pt[f];
				
			}else if(pt[s]->value==head->value){
				pt[f]->prev->next=pt[f]->next;
				pt[f]->next->prev=pt[f]->prev;
				pt[f]->next=pt[s];
				pt[s]->prev=pt[f];
				pt[f]->prev=NULL;
				head=pt[f];
			}
			else if(pt[s]->value==tail->value){
				pt[f]->prev->next=pt[f]->next;
				pt[f]->next->prev=pt[f]->prev;
				pt[f]->next=pt[s];
				pt[f]->prev=pt[s]->prev;
				pt[s]->prev->next=pt[f];
				pt[s]->prev=pt[f];
			}
			else if(pt[f]->value==tail->value){
				pt[f]->prev->next=NULL;
				tail=pt[f]->prev;				
				pt[f]->next=pt[s];
				pt[f]->prev=pt[s]->prev;
				pt[s]->prev->next=pt[f];
				pt[s]->prev=pt[f];
			}
			
			
			else{
				pt[f]->prev->next=pt[f]->next;
				pt[f]->next->prev=pt[f]->prev;
				pt[f]->next=pt[s];
				pt[f]->prev=pt[s]->prev;
				pt[f]->prev->next=pt[f];
				pt[s]->prev=pt[f];
			}
		}
		if(cmd=='B'){ 
			if(pt[f]->value==head->value && pt[s]->value==tail->value&&head->next==pt[s]){
				pt[s]->next=pt[f];
				pt[f]->prev=pt[s];
				pt[s]->prev=NULL;
				pt[f]->next=NULL;
				head=pt[s];
				tail=pt[f];	
			}
			else if(pt[f]->value==head->value && pt[s]->value==tail->value){ 
				pt[f]->next->prev=NULL;
				head=pt[f]->next;										
				pt[s]->next=pt[f];
				pt[f]->next=NULL;
				pt[f]->prev=pt[s];
				tail=pt[f];
			}
			else if(pt[f]->value==head->value){ 
				pt[f]->next->prev=NULL;
				head=pt[f]->next;				
				pt[f]->next=pt[s]->next;
				pt[f]->next->prev=pt[f];
				pt[s]->next=pt[f];
				pt[f]->prev=pt[s];
				
			}
			else if(pt[s]->value==tail->value){ 
				pt[f]->prev->next=pt[f]->next;
				pt[f]->next->prev=pt[f]->prev;
				pt[s]->next=pt[f];
				pt[f]->next=NULL;
				pt[f]->prev=tail;
				tail=pt[f];
			}
			else if(pt[f]->value==tail->value){ 
				pt[f]->prev->next=NULL;
				tail=pt[f]->prev;				
				pt[s]->next->prev=pt[f];
				pt[f]->next=pt[s]->next;
				pt[s]->next=pt[f];
				pt[f]->prev=pt[s];
			}
			
			
			else{ 	
				pt[f]->prev->next=pt[f]->next;
				pt[f]->next->prev=pt[f]->prev;
				pt[s]->next->prev=pt[f];
				pt[f]->next=pt[s]->next;
				pt[s]->next=pt[f];
				pt[f]->prev=pt[s];
												
			}
		}
//		print(head);
//		cout<<endl;
//		printback(head);
	}
//	for(int i=0;i<n;i++){
//		cout<<pt[i]->value<<" ";
//	}

	print(head);
//	printback(head);
}
