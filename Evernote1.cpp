/*
Evernote Coding challenge 1: 30 mins
Implement a circular buffer of size N. Allow the caller to append, remove and list the contents of the buffer. 
Implement the buffer to achieve maximum performance for each of the operations.
The new items are appended to the end and the order is retained i.e elements are placed in increasing order of their insertion time. 
When the number of elements in the list elements exceeds the defined size, the older elements are overwritten.

There are four types of commands.
"A" n - Append the following n lines to the buffer. If the buffer is full they replace the older entries.
"R" n - Remove first n elements of the buffer. These n elements are the ones that were added earliest among the current elements.
"L" - List the elements of buffer in order of their inserting time.
"Q" - Quit.
Your task is to execute commands on circular buffer.

Input format
First line of input contains N , the size of the buffer.
A n - append the following n lines to the buffer.
R n - remove first n elements of the buffer.
L - list the buffer.
Q - Quit.

Output format
Whenever L command appears in the input, print the elements of buffer in order of their inserting time. 
Element that was added first should appear first.

Sample Input
10
A 3
Fee
Fi
Fo
A 1
Fum
R 2
L
Q

Sample Output
Fo
Fum

Constraint
0 <= N <= 10000
Number of removing elements will <= number of elements presents in circular buffer.
Total number of commands <= 50000.
Total number of characters in input <= 20000000.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node{
   string data;
   Node* next;
};

class circleBuffer{
public:
   Node* head;
   Node* write;
   int maxNode;
   int nodeCount;

   circleBuffer();
   circleBuffer(int maxValue);
   void addNode(string,int);
   void delNode(int);
   void printNode();
};

circleBuffer::circleBuffer(){
   head = NULL;
   maxNode = 0;
   nodeCount = 0;
}
circleBuffer::circleBuffer(int maxValue){
   head = NULL;
   maxNode = maxValue;
   nodeCount = 0;
}
void circleBuffer::addNode(string input, int length){

	if(head == NULL){
      head = new Node;
	  head->data = input;
	  head->next = NULL;
	  nodeCount++;
   }
   else{
	   Node* parse;

	   if(nodeCount == maxNode){
          head->data = input;
          head = head->next;
	   }
	   else{
          parse = head;
          while(parse->next!=NULL){
             parse = parse->next;
	      }
	      parse->next = new Node;
	      parse->next->data = input;
		  nodeCount++;

		  if(nodeCount < maxNode){
	        parse->next->next = NULL;
	      }
	      else{
             parse->next->next = head;
	      }
	   }
   }
}
void circleBuffer::delNode(int noDel){
   if(head == NULL){
      cout << "No elements to delete" << endl;
   }
   else{
      Node* parse = head;

	  if(nodeCount == maxNode){
         while(parse->next != head){
	        parse = parse->next;
	     }
		 parse->next = NULL;
	  }
	  while(noDel){
	     parse = head;
	     head = head->next;         
		 delete parse;
		 nodeCount--;
		 noDel--;
	  }
   }
}

void circleBuffer::printNode(){
   Node* parse;
   if(head == NULL){
	   cout << "No element to print" << endl;
	   return;
   }
   else cout<<head->data<<endl;
   parse=head->next;
   while(parse!=NULL && parse!=head){
      cout<<parse->data<<endl;
      parse = parse->next;
   }
}

int main(){
	int N;
	char Char;
	cin >> N;
    circleBuffer* cb = new circleBuffer(N);

	while(cin >> Char && Char != 'Q'){
	   int num1;
	   string str;
	   switch(Char){
		   case 'A':
				cin >> num1;
				for(int i=0; i< num1; i++){
					cin >> str;
					cb->addNode(str,num1);
				}
		  		break;
		   case 'R':
			    cin>>num1;
				cb->delNode(num1);
				break;
		   case 'L':
			    cb->printNode();
                break;
		   case 'Q':
                cout << "Quitting the program" << endl;     
			    break;
		   default:
              cout << Char << " is not a valid command"  << endl;
              break;
	   }
	}
	return 0;
}
