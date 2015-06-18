#include <iostream>
#include <thread>
#include <vector>
using namespace std;

const int MAX_NO_OF_THREADS = 10;

void any_random_func(int i){
	cout << "Output from thread: " << i << endl;
}
int main(){
	vector<thread> th;
	
   //Launch a thread
	for (int i = 0; i < MAX_NO_OF_THREADS; i++){
		th.push_back(std::thread(any_random_func, i));
	}
   
   //Join the thread with the main thread
	for (auto &t:th){
		t.join();
	}

	cout << "Output from main thread" << endl;
    
	//Get input from console before closing it
    getchar();
    return 0;
}