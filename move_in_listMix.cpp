#include <iostream>
#include <stdio.h>
#include <algorithm> 
#include <vector>

using namespace std;

struct node{
	int value;
	struct node *next,*prev;
};
struct node *head=NULL,*tail=NULL;

struct node *print(struct node *head){
	struct node *p;
	p=head; 
	while(p!=NULL)
	{	cout << p->value << " ";
		p=p->next;
	}
	cout << endl;
}

int main (){
	int n,k;
	cin >> n >> k;
	struct node *ptr[n];
	for(int i=1 ; i<=n ;i++){
		if(i==1){
			ptr[i] = new struct node;
			ptr[i]->prev = NULL;
			ptr[i]->value = i;
			head = ptr[i];
		}
		else if(i == n){
			ptr[i] = new struct node;
			ptr[i]->next = NULL;
			ptr[i]->value = i;
			ptr[i]->prev = ptr[i-1];
			ptr[i]->prev->next = ptr[i];
			tail = ptr[i];
		}
		else{
			ptr[i] = new struct node;
			ptr[i]->value = i;
			ptr[i]->prev = ptr[i-1];
			ptr[i]->prev->next = ptr[i];
		}		
	}	
	while(k>0){
		int x,y;
		char z;
		cin >> z >> x >> y;
		if(z=='A'){ //A
			if(ptr[x]->next == NULL && ptr[y]->prev == NULL){//A
				if(ptr[x]->prev == ptr[y]){
					ptr[x]->next = ptr[y];
					ptr[y]->prev = ptr[x];
					ptr[x]->prev = NULL;
					ptr[y]->next = NULL;
					head = ptr[x];
					tail = ptr[y];					
				}
				else {//A
					ptr[x]->prev->next = NULL;
					tail = ptr[x]->prev;															
					ptr[x]->next = ptr[y];
					ptr[y]->prev = ptr[x];
					ptr[x]->prev = NULL;
					head = ptr[x];					
				}		
			}
			else if(ptr[x]->prev == NULL){//A
				ptr[x]->next->prev = NULL;
				head = ptr[x]->next;												
				ptr[x]->next = ptr[y];
				ptr[y]->prev->next = ptr[x];
				ptr[y]->prev->next->prev = ptr[y]->prev;
				ptr[y]->prev = ptr[x];
			}
			else if(ptr[x]->next == NULL){//A
				ptr[x]->prev->next = NULL;
				tail = ptr[x]->prev;				
				ptr[x]->next = ptr[y];
				ptr[x]->prev = ptr[y]->prev;
				ptr[x]->prev->next = ptr[x];
				ptr[x]->next->prev = ptr[x];
			}
			else if(ptr[y]->prev == NULL){//A
				ptr[x]->prev->next = ptr[x]->next;
				ptr[x]->next->prev = ptr[x]->prev;
				ptr[x]->next = ptr[y];
				ptr[y]->prev = ptr[x];
				ptr[x]->prev = NULL;
				head = ptr[x];
			}
			else if(ptr[y]->next == NULL){
				ptr[x]->prev->next = ptr[x]->next;
				ptr[x]->next->prev = ptr[x]->prev;
				ptr[x]->next = ptr[y];
				ptr[x]->prev = ptr[y]->prev;
				ptr[y]->prev->next = ptr[x];
				ptr[y]->prev = ptr[x];
			}
			else{//A
				ptr[x]->prev->next = ptr[x]->next;
				ptr[x]->prev->next->prev = ptr[x]->prev;
				ptr[x]->next = ptr[y];
				ptr[x]->prev = ptr[y]->prev;
				ptr[x]->prev->next = ptr[x];
				ptr[y]->prev = ptr[x];
			}
		}
		if(z=='B'){ //B
			if(ptr[x]->prev == NULL && ptr[y]->next == NULL){ //B
				if(ptr[x]->next == ptr[y]){
					ptr[y]->next = ptr[x];
					ptr[x]->prev = ptr[y];
					ptr[y]->prev = NULL;
					ptr[x]->next = NULL;
					head = ptr[y];
					tail = ptr[x];
				}
				else{
					ptr[x]->next->prev = NULL;
					head = ptr[x]->next;										
					ptr[y]->next = ptr[x];
					ptr[x]->next = NULL;
					ptr[x]->prev = ptr[y];
					tail = ptr[x];
				}
			}
			else if(ptr[x]->next == NULL){ //B
				//cout << tail->value << endl;
				ptr[x]->prev->next = NULL;
				tail = ptr[x]->prev;				
				ptr[y]->next->prev = ptr[x];
				ptr[x]->next = ptr[y]->next;
				ptr[y]->next = ptr[x];
				ptr[x]->prev = ptr[y];
				//cout << tail->value << endl;
			}
			else if(ptr[x]->prev == NULL){ //B
				ptr[x]->next->prev = NULL;
				head = ptr[x]->next;				
				ptr[x]->next = ptr[y]->next;
				ptr[x]->next->prev = ptr[x];
				ptr[y]->next = ptr[x];
				ptr[x]->prev = ptr[y];
				
			}
			else if(ptr[y]->next == NULL){ //B
				ptr[x]->prev->next = ptr[x]->next;
				ptr[x]->next->prev = ptr[x]->prev;
				ptr[y]->next = ptr[x];
				ptr[x]->next = NULL;
				ptr[x]->prev = tail;
				tail = ptr[x];
				//cout << tail->prev->value << endl;
			}
			else{ //B	
				ptr[x]->prev->next = ptr[x]->next;
				ptr[x]->prev->next->prev = ptr[x]->prev;
				ptr[y]->next->prev = ptr[x];
				ptr[x]->next = ptr[y]->next;
				ptr[y]->next = ptr[x];
				ptr[x]->prev = ptr[y];
												
			}
		}
		//print(head);
		k--;
	}
	struct node *p;
	p=head; 
	while(p!=NULL)
	{	cout << p->value;
		p=p->next;
		if(p!= NULL)
			cout << endl;
	}	
}
