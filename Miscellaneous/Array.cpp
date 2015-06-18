/**
*
*/
#include "conio.h"
#include "iostream"
using namespace std;

/*int CounterStep(int counter,int N);
int LocatePosition(int *cards,int N, int startPointer,int value);
*/
void main()
{
    int cards[20];
    int N=20;
    int POS = 0,TOP = 0;

    // Initializing everything to zero
    for(int i=0;i<N;i++) cards[i]=0;

    // Putting the right value at the
    // available correct location index
    for(int index=1;index<=N;index++)
    {
        POS=LocatePosition(cards,N,TOP,index);

        TOP = POS;
        cards[TOP] = index;
    }

    // Printing the cards series
    for(int index=0;index<N;index++)
    cout << cards[index] << endl;
}

int CounterStep(int counter,int N)
{
    if(counter==N-1) return 0;
    else return counter+1;
}

int LocatePosition(int *cards,int N, int startPointer,int value)
{
    if(value == 1) return 1;
    int position =startPointer;
    for(int index=0;index <=value;index++)
    {
        do
        {
            position = CounterStep(position,N);
        }while(cards[position] != 0);
    }
    return position;
}