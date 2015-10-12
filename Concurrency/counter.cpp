#include <thread>
#include <iostream>
#include <atomic>
#include <vector>
using namespace std;

const unsigned int NTHREADS = 20;
const int ITERS = 100;

atomic<int> counter;

void increment()
{
	for (int i = 0; i<ITERS; i++)
		counter++;
}

void decrement()
{
	for (int i = 0; i<ITERS; i++)
		counter--;
}

int main()
{
	vector<thread> vt;

	cout << "The counter is " << counter << endl;

	for (unsigned int i = 0; i < NTHREADS; i++){
		if (i % 2 == 0)
			vt.push_back(thread(increment));
	    else
		   vt.push_back(thread(decrement));
	}
	for (thread &t : vt)
		t.join();

	cout << "The counter is " << counter << endl;;

	getchar();
	return 0;
}