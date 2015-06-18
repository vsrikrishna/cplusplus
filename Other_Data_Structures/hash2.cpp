#include "hash2.h"
#include "iostream"
using namespace std;

int main(){
    MyHashSet<int> *H1 = new MyHashSet<int>();
	H1->addElementAtTheEndOfTheSet(123, 456);
	int value = 0;
	value = H1->searchElementInTheSet(123, 476);
	cout << "element found is " << value << endl;
    return 0;
}
