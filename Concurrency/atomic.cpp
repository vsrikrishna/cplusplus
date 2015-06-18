#include <thread>
#include <iostream>
#include <mutex>
#include <vector>
using namespace std;

const unsigned int NTHREADS = 20;
const int ITERS = 100;

mutex m1, m2, m3;
int counter = 0;

void increment(int n)
{
	cout <<"Inside increment method"<< endl;
	for (int i = 0; i<ITERS; i++)
	{
		lock_guard<mutex> l1(m1);
		lock_guard<mutex> l2(m2);
		lock_guard<mutex> l3(m3);
		counter++;
	}
}

void decrement(int n)
{
	cout << "Inside decrement method" << endl;
	for (int i = 0; i<ITERS; i++)
	{
		lock_guard<mutex> l1(m1);
		lock_guard<mutex> l2(m2);
		lock_guard<mutex> l3(m3);
		counter--;
	}
}


int main()
{
	vector<thread> vt;

	for (unsigned int i = 0; i < NTHREADS; i++){
		if (i % 2 == 0)
			vt.push_back(thread(increment, i));
		else
			vt.push_back(thread(decrement, i));
	}
	
	for (thread &t : vt)
		t.join();

    cout << "The counter is " << counter << endl;
	getchar();

	return 0;
}