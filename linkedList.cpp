#include <iostream>
#include <stdlib.h>     /* malloc, free, rand */

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

using namespace std;

struct node {
	int data;
	struct node* next;
};

struct node* Build(int numberItem);
//void pushBack(struct node *& head, struct node * anode);	//use reference of head
//void pushBack(struct node ** head, struct node * anode);	//using pointer's pointer for head
void pushBack(struct node *& head, int data);	//use reference of head
void push(struct node *& head, int data);
int length(struct node* head);
struct node* copyList(struct node* list);
struct node* copyListRecursive(struct node* list);
struct node* pop(struct node*& list);
struct node* popBack(struct node*& list);

main(){
	struct node* myList = Build(5);
	
	for (struct node* current = myList; current!=NULL; current=current->next){
		cout<< current->data<<", ";
	}
	cout<<endl<<"List length = "<<length(myList)<<endl;

	//struct node* newList = copyList(myList);
	struct node* newList = copyListRecursive(myList);
//	for (struct node* current = myList; current!=NULL; current=current->next){
//		cout<< current->data<<", ";
//	}
	//while(struct node* anode = pop(myList)){
	while(struct node* anode = popBack(myList)){
		cout <<anode->data<<", ";
		//free (anode);
		delete anode;
	}
	cout<<endl;
	if (myList==NULL) cout<<"myList is deleted"<<endl;
}
struct node* Build(int numberItem) {
	struct node* head = NULL;
	for (int i=1; i<numberItem+1; ++i){
		//pushBack(head, i);
		push(head, i);
	}
	return head;
}
void pushBack(struct node *& head, int data){	//use reference of head
	//struct node * anode = (struct node*) malloc(sizeof(struct node)); // allocate a node in the heap
	struct node * anode = new (struct node); // allocate a node in the heap
	anode->data = data;
	anode->next = NULL;
	//cout <<"In pushBack: anode= "<<anode<<endl;
	if (head==NULL){
		head = anode;
		//cout <<"In pushBack: set head= "<<head<<endl;
	} else {
		struct node* current = head;
		while(current->next!=NULL){
			//cout<<"In pushBack: current="<<current<<", current->next="<<current->next<<endl;
			current=current->next;	
		} 
		current->next=anode;
	}
}
void push(struct node *& head, int data){	//use reference of head
	//struct node * anode = (struct node*) malloc(sizeof(struct node)); // allocate a node in the heap
	struct node * anode = new (struct node); // allocate a node in the heap
	anode->data = data;
	anode->next = head;
	head = anode;
}
int length(struct node* head){
	int count=0;
	struct node* current = head;
	while(current!=NULL){
		++count;
		current = current->next;
	}
	return count;
}
struct node* copyList(struct node* list){
	struct node* newList = NULL;
	struct node* tail =NULL;
	while(list!=NULL){
		if (newList==NULL){
			//newList = (struct node*)malloc(sizeof(struct node));
			newList = new (struct node);
			newList->data = list->data;
			newList->next = NULL;
			tail = newList;
		} else {
			//tail->next = (struct node*)malloc(sizeof(struct node));
			tail->next = new (struct node);
			tail = tail->next;
			tail->data = list->data;
			tail->next = NULL;
		}
		list = list->next;
	}
	return newList;
}
struct node* copyListRecursive(struct node* list){
	if (list==NULL){
		return NULL;
	} else {
		//struct node* newList = (struct node*)malloc(sizeof(struct node));
		struct node* newList = new (struct node);
		newList->data = list->data;
		newList->next = copyListRecursive(list->next);
		return newList;
	}
}
struct node* pop(struct node*& list){
	//cout<<"In pop function"<<endl;
	struct node* anode = list;
	if (list!=NULL) {
		list = list->next;
		//cout <<"The Data is "<<anode->data<<"; return from pop"<<endl;	
	}
	return anode;
}
struct node* popBack(struct node*& list){
	if (list==NULL) {
		return NULL;
	}
	struct node* anode = list;
	struct node* secondLastNode;
	while(anode->next!=NULL){
		secondLastNode =anode;
		 anode = anode->next;
	}
	if (list==anode) {
		list = NULL;
	} else {
		secondLastNode->next=NULL;
	}
	return anode;
}