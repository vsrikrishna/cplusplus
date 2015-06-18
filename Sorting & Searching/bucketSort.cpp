#include "iostream"
#include "conio.h"
using namespace std;

struct tag_list {
	int elem;
	tag_list *next;
};

void print(int *input, int n)
{
	for (int i = 0; i < n; i++)
		cout << input[i] << " ";
}



int bucketSort(int a[], int a_len, int maxVal)
{
	int i, count;
	tag_list* bucket[10] = { 0 };

	/* one loop simple processing with one more inner loop
	to get sorted buckets (insert-sort on lists, Cormen-style) */
	for (i = 0; i != a_len; ++i)
	{
		int bnum = (10 * a[i]) / maxVal;
		tag_list* bptr = bucket[bnum];
		tag_list* belem = new tag_list;
		belem->elem = a[i];
		if (bptr == NULL)
		{
			bucket[bnum] = belem;
			belem->next = 0;
		}
		else if (a[i] <= bptr->elem)
		{
			belem->next = bptr;
			bucket[bnum] = belem;
		}
		else
		{
			while (bptr != 0)
			{
				if ((bptr->elem <= a[i]) && ((bptr->next == 0) || (bptr->next->elem > a[i])))
				{
					belem->next = bptr->next;
					bptr->next = belem;
					break;
				}
				else{
					bptr = bptr->next;
				}
			}
		}
	}

	/* one loop (looks as two) to get all back */
	count = 0;

	for (i = 0; i != 10; ++i)
	{
		tag_list* bptr = bucket[i];
		while (bptr)
		{
			tag_list* optr = bptr;
			a[count] = bptr->elem;
			count++;
			bptr = bptr->next;
			delete(optr);
		}
	}

	return 0;
}

int main(){
    int input[10] = { 143, 123, 222, 186, 235, 9, 905, 428, 543, 373 };
	cout << "Input: ";
	print(input, 10);
	bucketSort(input,10,1000);
	cout << "\nOutput: ";
	print(input, 10);
	cout << "\n";
	getchar();
	return 0;
}