#include "iostream"
using namespace std;

struct Node{
   int value;
   Node* next;
};

class LinkedList{
   Node* head;
public:
   LinkedList(){
      head = NULL;
   }
   void addNode(int value);
   void wrapAround();
   bool isCyclic();
};

void LinkedList::addNode(int val){
   if (head == NULL){
      head = new Node();
      head->value = val;
      head->next = NULL;
   }
   else{
      Node* temp = head;
	  while(temp->next!=NULL){
         temp = temp->next;
	  }
	  Node* temp2 = new Node();
	  temp2->value = val;
      temp2->next = NULL;
	  temp->next = temp2;
   }
}

void LinkedList::wrapAround(){
	Node* temp = head;
	while(temp->next!=NULL){
	 temp = temp->next;
	}
	temp->next = head;
}
bool LinkedList::isCyclic(){
   Node *n1, *n2, *n3;
   n1 = n2 = n3 = head;
   while(n1){
	  n2 = n3->next;
	  n3 = n2->next;
       if(n1==n2 || n1 == n3){
          return true;
	   }
	   n1 = n1->next;
	}
   return false;
}
/*
   Node *slowNode,*fastNode1,*fastNode2;
   slowNode = fastNode1 = fastNode2 = head;
   while (slowNode){
	  fastNode1 = fastNode2->next;
      fastNode2 = fastNode1->next;
      if (slowNode == fastNode1 || slowNode == fastNode2) return true;
      slowNode = slowNode->next;
   }
   return false;
}
*/
int main(){
   LinkedList L1;
   L1.addNode(5);
   L1.addNode(6);
   L1.addNode(7);
   L1.addNode(3);
   L1.addNode(1);
   L1.wrapAround();
   bool loopTest = L1.isCyclic();
   cout << "loop test is " << loopTest << endl;
   return 0;
}