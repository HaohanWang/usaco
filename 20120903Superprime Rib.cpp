/*
ID: haohanw
PROG: sprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

void Search(int, int);
bool Prime(int);

char num[9];
ofstream out ("sprime.out");

int main()
{
	ifstream in ("sprime.in");

	int N;
	in>>N;
	if (N==1)
	{
		out<<2<<endl<<3<<endl<<5<<endl<<7<<endl;
		return 0;
	}
	else
	{
		num[0]='2';
		Search(N-1,1);
		num[0]='3';
		Search(N-1,1);
		num[0]='5';
		Search(N-1,1);
		num[0]='7';
		Search(N-1,1);
		return 0;
	}
}

void Search(int N, int index)
{
	int i, j;
	char a;
	if (N==1)
	{
		for (i=1;i<=9;i+=2)
		{
			a='0'+i;
			num[index]=a;
			num[index+1]='\0';
			j=atoi(num);
			if (Prime(j))
			{
				out<<j<<endl;
			}
		}
	}
	else
	{
		for (i=1;i<=9;i+=2)
		{
			a='0'+i;
			num[index]=a;
			num[index+1]='\0';
			j=atoi(num);
			if (Prime(j))
			{
				Search(N-1,index+1);
			}
		}
	}
}

bool Prime(int a)
{
	int n=(int)sqrt((double)a);
	int i;
	for (i=3;i<=n;i+=2)
	{
		if (a%i==0)
			return false;
	}
	return true;
}