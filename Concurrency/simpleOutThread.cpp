#include <iostream>
#include <thread>
using namespace std;


void any_random_func(){
	cout << "Output from thread" << endl;
}
int main(){
	std::thread t(any_random_func);
   //Launch a thread
   std::thread t(any_random_func, i);
   
   //Join the thread with the main thread
   t.join();

   //Get input from console before closing it
   getchar();
   return 0;
}