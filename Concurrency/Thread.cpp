/*
 * Program to use and implement Thread class in C++
 * 07/13/2014
 */

#include "iostream"
#include "thread"
#include "chrono"
using namespace std;

void prtFunc1(int n){
	std::this_thread::sleep_for(std::chrono::seconds(n));
	cout << "1" << endl;
}
void prtFunc2(int n){
	std::this_thread::sleep_for(std::chrono::seconds(n));
	cout << "2" << endl;
}
void prtFunc3(int n){
	std::this_thread::sleep_for(std::chrono::seconds(n));
	cout << "3" << endl;
}
int main(){
	thread t1(prtFunc1, 5);
	thread t2(prtFunc2, 5);
	thread t3(prtFunc3, 10);
	//t2.join();
	//t1.join();
	t3.join();
	//t3.detach();
	getchar();
    return 0;
}