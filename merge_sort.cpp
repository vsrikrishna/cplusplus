#include "conio.h"
#include "string.h"
#include "iostream"
#include "math.h"
using namespace std;

void merge(int a[],int first,int mid, int last)
{
	int x,y,i;
	int b[10];
	x= first;
	y= mid+1;
	i= first;
	while((x<=mid)&&(y<=last))
	{
	  if(a[x]<=a[y])
		  b[i++]=a[x++];
	  else
		  b[i++]=a[y++];
	}
	if((x>mid)&&(y<=last))
	{
	  for(int k=y;k<=last;k++)
	  {
		b[i++]= a[k];
		y++;
	  }
	}
	else if((x<=mid)&&(y>last))
	{
	  for(int k=x;k<=mid;k++)
	  {
        b[i++] = a[k];
		x++;
	  }
	}
	for(int k=first;k<=last;k++)
	{
		a[k]=b[k];
	}
}

void merge_sort(int arr[],int first, int last)
{
  if(first<last)
  {
	int mid;
    mid = (first+last)/2;
	merge_sort(arr,first,mid);
    merge_sort(arr,mid+1,last);
	merge(arr,first,mid,last);
  }
}
void testAndPrintResult(int arr1[], int arr2[], int size)
{
	int flag=1;
	if(size==1)
	{
		cout<<"Only 1 element, no sorting Required"<<endl;

	}
	else
	{
		merge_sort(arr1,0,size-1);
		for(int i=0;i<sizeof(arr1);i++)
		{
			if(arr1[i]!=arr2[i])
			{
				cout<<"string is not sorted"<<endl;
				flag=0;
				break;
			}
		}
		if(flag)
		  cout<<"string sorted"<<endl;
	   for(int i=0;i<5;i++)
		   cout<<arr1[i]<<endl;
	}
}

int main()
{
 //Test1
cout<<"Test 1 Results"<<endl;
int test_arr[]={5,4,3,2,1};
int expected_arr[]={1,2,3,4,5};
//int flag=0;
int noOfElements = sizeof(test_arr)/sizeof(int);
testAndPrintResult(test_arr,expected_arr,noOfElements);

//Test 2
cout<<"Test 2 Results"<<endl;
int test_arr2[]={1};
int expected_arr2[]={1};
noOfElements = sizeof(test_arr2)/sizeof(int);
testAndPrintResult(test_arr2,expected_arr2, noOfElements);

//Test 3
cout<<"Test 3 Results"<<endl;
int test_arr3[]={4,5,8,7};
int expected_arr3[]={4,5,6,8};
noOfElements = sizeof(test_arr3)/sizeof(int);
testAndPrintResult(test_arr3,expected_arr3, noOfElements);

_getch();
return 0;
}