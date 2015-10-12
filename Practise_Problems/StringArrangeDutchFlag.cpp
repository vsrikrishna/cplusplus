/*
A string contains a-z, A-Z and spaces. Sort the string so that all lower cases are at the beginning, 
spaces in the middle and upper cases at the end. Original order among lower and upper cases needs 
to remain the same. 
For example: a cBd LkmY becomes ackm BLY. Is there a way in O(n) without extra space?
*/
#include<iostream>
#include <string>
using namespace std;

/* Function to swap *a and *b */
void swap(char *a, char *b);

// Sort the input array, the array is assumed to
// have values in {small, blank, capital} letters
void dutchSortString(char* a, int arr_size)
{
	int lo = 0;
	int hi = arr_size - 1;
	int mid = 0;

	while (mid <= hi)
	{
		if (a[mid] >= 'a'&& a[mid] <= 'z'){
			swap(&a[lo++], &a[mid++]);
		}
		if (a[mid] == ' '){
			mid++;
		}
		if (a[mid] >= 'A' && a[mid] <= 'Z' && mid<=hi){
			swap(&a[mid], &a[hi--]);
		}
	}
}

/*Used to order the output based on the input order*/
void orderByInput(string &in, string &out){
	int i = 0,j=0;
	if (in.length() != out.length()){
		cout << "The length cannot be different" << endl;
	}
	while (j<in.length()){
		if (out[i] >= 'a' && out[i] <= 'z' && in[j] >= 'a' && in[j] <= 'z'){
			out[i++] = in[j];
		}
		j++;
	}
	i = in.length()-1; j = in.length()-1;
	while (j>=0){
		if (out[i] >= 'A' && out[i] <= 'Z' && in[j] >= 'A' && in[j] <= 'Z'){
			out[i--] = in[j];
		}
		j--;
	}
}

/* UTILITY FUNCTIONS */
void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

/* driver program to test */
int main()
{
	string str = "a cBd LkmY";
	string cpyStr = str;
	
	dutchSortString(&str[0], str.length());
	cout << "string after segregation is " << str<<endl;

	orderByInput(cpyStr, str);
	cout <<"string after input order is " << str<<endl;

	getchar();
	return 0;
}
