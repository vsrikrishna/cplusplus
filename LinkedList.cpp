/**
*Linked List
* Jan 24 2014
*/
#include "iostream"
#include "conio.h"
#include "unordered_map"

using namespace std;

struct node{
   int data;
   node* next;
};

class LinkedList
{
public:
	node* head;
	LinkedList(){
    	head = NULL;
	}
	~LinkedList(){	
	}
	void append_front(int);
	void del(int);
	void reverse_list();
	node* reverse_list_recursive(node*);
	void print_list();
	void print_list_with_head(node*);
	void removeRepeatedValue(node*);
};

void LinkedList::append_front(int data){
   node *parse,*new_element;
   parse =head;
   if(head==NULL){
	  head = new node;
	  head->data = data;
	  head->next = NULL;
	  return;
   }
   else{
	   while(parse->next!=NULL)
	   {
	      parse=parse->next;
	   }
   }
   new_element = new node;
   new_element->data = data;
   new_element->next = NULL;
   parse->next=new_element;
}
void LinkedList::del(int data){
	node *parse,*prev;
	parse=prev=head;
	if(head->data==data && head->next==NULL)
	{
		cout<<"Only Head element present"<<endl;
	}
	while(parse->data!=data)
	{
		prev=parse;
		parse=parse->next;
	}
	prev->next=parse->next;
	delete parse;
}


/*
* Iteration way of reversing the linked list. More lines of code and extra pointer but more efficient and less memory overhead compared to recursive method.
* Recursive method might run out of space for large number of elements.
*/
void LinkedList::reverse_list(){
	node *parse,*prev;
	parse=head;
	prev=NULL;
	while(head)
	{
		parse=head->next;
		head->next=prev;
		prev=head;
		if(parse==NULL){
			break;
		}
		head=parse;
	}
}

node* LinkedList::reverse_list_recursive(node *n)
{
    node *first,*next;
	first= n;
	next=first->next;
	
	if(next==NULL)
	{
		return first;
	}
	
	head=reverse_list_recursive(next);
	first->next->next=first;
	first->next=NULL;
	return head;
}

void LinkedList::print_list(){
	node *parse;
	parse=head;
	while(parse)
	{
		cout<<parse->data<<endl;
		parse=parse->next;
	}
}

int main(void){
	cout<<"Printing List 1"<<endl;
	LinkedList List1;
	List1.append_front(7);
	List1.append_front(5);
	List1.append_front(3);
	List1.append_front(1);
	List1.print_list();
	cout<<"reversing"<<endl;
	List1.reverse_list();
	List1.print_list();
    cout<<"reversing"<<endl;
	List1.head = List1.reverse_list_recursive(List1.head);
	List1.print_list();
	
	cout<<"Printing List 2"<<endl;
	LinkedList List2;
	List2.append_front(8);
	List2.append_front(6);
	List2.append_front(4);
	List2.append_front(2);
	List2.print_list();
	List2.del(2);
	cout<<"After deletion"<<endl;
	List2.print_list();
	cout << "After reversing" << endl;
	List2.head = List2.reverse_list_recursive(List2.head);
	List2.print_list();
	getch();
	return 0;	
}
