/*
Complexity of hashMap
Insertion: O(1) if insertion is at head of linkedlist
Deletion:  O(1+k/n) - where k is no of collisions in one location
Search:    O(1+k/n) 
*/
#include "iostream"
#include "string"
using namespace std;
const int TABLE_SIZE = 128;

class LinkedHashEntry {
private:
      int key;
      int value;
	  LinkedHashEntry *next;
public:
      LinkedHashEntry(int key, int value) {
         this->key = key;
         this->value = value;
         this->next = NULL;
      }
 
	  LinkedHashEntry(){
		  this->key = NULL;
		  this->value = NULL;
		  this->next = NULL;
	  }
      int getKey() {
         return key;
      }
 
      int getValue() {
         return value;
      }

	  void setValue(int val){
         this->value = val;
	  }

	  LinkedHashEntry *getNext(){
         return next;
	  }

	  void setNext(LinkedHashEntry *next){
	     this->next = next;
	  }
};

class HashMap {

private:
   LinkedHashEntry **table;
public:
   HashMap() {
      table = new LinkedHashEntry* [TABLE_SIZE];
      for (int i = 0; i < TABLE_SIZE; i++)
         table[i] = NULL;
   }

   int get(int key) {
      int hash = (key % TABLE_SIZE);
      if(table[hash] == NULL)
         return -1;
	  else{
         LinkedHashEntry *temp = table[hash];
		 while(temp!=NULL && temp->getKey()!= key){
            temp = temp->getNext();
		 }
		 if(temp == NULL) 
			 return -1;
		 else 
			 return temp->getValue();
	  }
   }

   void put(int key, int value) {
      int hash = (key % TABLE_SIZE);
	  
	  if(table[hash] == NULL){
	     table[hash] = new LinkedHashEntry(key,value);
	  }
	  else{
         LinkedHashEntry* tmp = table[hash];
         while(tmp->getNext() != NULL)
            tmp = tmp->getNext();
         if(tmp->getKey() == key)
            tmp->setValue(value);
         else
            tmp->setNext(new LinkedHashEntry(key,value));
	  }
   }     

   void remove(int key){
      int hash = (key%TABLE_SIZE);
	  
	  if(table[hash]!=NULL){
         LinkedHashEntry *prev = NULL;
		 LinkedHashEntry *entry = table[hash];

		 while(entry->getNext() != NULL && entry->getKey() != key){
			 prev = entry;
			 entry = entry->getNext();
		 }
		 if(entry->getKey() == key){
			 if(prev == NULL){
                table[hash]= entry->getNext();
				delete entry;
			 }
			 else{
				 prev->setNext(entry->getNext());
				 delete entry;
			 }
		 }
	  }
   }
   ~HashMap() {
      for(int i = 0; i < TABLE_SIZE; i++){
         if (table[i] != NULL){
            LinkedHashEntry* prev = NULL;
            LinkedHashEntry* entry = table[i];
			while(entry){
               prev = entry;
               entry= entry->getNext();
			   delete prev;
			}
		 }
	  }
      delete[] table;
   }
};

int main(){
   HashMap m1;
   m1.put(310,955);
   m1.put(310,800);
   m1.put(410,500);
   m1.remove(310);
   //int retVal = m1.get(310);
   cout << "retVal is " << m1.get(410) << endl;
   cout << "retVal is " << m1.get(310) << endl;
   getchar();
   return 0;
}