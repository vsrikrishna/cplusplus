#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "string.h"
using namespace std;

char* replace_char(char *str)
{
	int i=0;

	if(str[i]==' ')
	{
		cout<<"Blank string passed"<<endl;
		return str;
	}
	while(str[i])
	{
		if(str[i]=='a')
		{
			str[i]= 'A';
		}
		i++;
	}
	return str;
}
void compare_strings(char* input, string ouput)
{
	char *str;
	str = replace_char(input);
	if(ouput.compare(str)==0)
	{
		cout<<"PASS"<<endl;
	    cout<<"The returned string is"<<str<<endl;
	}
	else
	{
		cout<<"FAIL"<<endl;
		cout<<"The returned string is"<<str<<endl;
	}
}
int main()
{
	char* str;	
	string str_compare;

	//Test 1
	char test[] = "naBac a";
	str_compare="nABAc A";
    compare_strings(test,str_compare);

	//Test 2
	strcpy(test,"");
    str_compare = " ";
	compare_strings(test,str_compare);

	//Test 3
	strcpy(test,"aaa");
	str_compare = "AAA";
	compare_strings(test,str_compare);

    getch();
    return 0;
}
