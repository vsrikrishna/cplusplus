#include <iostream>
using namespace std;

/*
Allocation where the variable value is changed
*/
void alloc1(int* p) {
	//p = (int*)malloc(sizeof(int)); //Note:Uncommenting this will cause this memory allocation to be lost
	*p = 10;
}
/*
Allocation where the memory allocation and the value of the variable is changed 
*/
void alloc2(int** p) {
	*p = (int*)malloc(sizeof(int));
	**p = 10;
}

int main(){
	/* Valid pointer assignment
	int var = 5;
	int *p = &var;
	*/
	//int *p = (int*)100; Valid pointer assignment
	int *p;
	//alloc1(p); //this is not valid because the memory allocation is lost 

	//printf("%d ",*p);//value is undefined
	alloc2(&p);
	printf("%d ", *p);//will print 10
	free(p);
	return 0;
}