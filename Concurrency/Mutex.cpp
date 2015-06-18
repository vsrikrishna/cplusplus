#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

mutex m;

void func(){
	m.lock();
	cout<<"Starting thread with id: "<<std::this_thread::get_id()<<endl;
	std::this_thread::sleep_for(std::chrono::seconds(rand()%10));
	cout<<"Ending thread with id: "<<std::this_thread::get_id()<<endl;
	m.unlock();
}

int main(){
   thread t1(func);
   thread t2(func);
   thread t3(func);
   
   t1.join();
   t2.join();
   t3.join();
   
   getchar();
   return 0;
}