/*
ID: haohanw1
PROG: kimbits
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

typedef struct cc
{
	int num;
	int value;
	cc* next;
} Unit;

int main()
{
	ifstream in ("kimbits.in");
	ofstream out ("kimbits.out");
	int N, L, I;
	in>>N>>L>>I;
	int i, n, k, j;
	int m, c=0;
	int result[32]={0};
	int s=pow((double)2,L+1)-1;
	if (s>I)
	{
	for (i=0;i<=pow((double)2,N)-1;i++)
	{
		n=0;
		m=i;
		for (k=1;k<=N;k++)
		{
			n+=m%2;
			m/=2;
		}
		if (n>L)
		{
		}
		else
		{
			c++;
		}
		if (c==I)
			break;
	}	
	}
	else
	{
	for (i=s;i<=pow((double)2,N)-1;i++)
	{
		n=0;
		m=i;
		for (k=1;k<=N;k++)
		{
			n+=m%2;
			m/=2;
		}
		if (n>L)
		{
		}
		else
		{
			c++;
		}
		if (c==I-s)
			break;
	}
	}
	for (k=0;k<=N-1;k++)
	{
		result[k]=i%2;
		i/=2;
	}
	for (k=N-1;k>=0;k--)
	{
		out<<result[k];
	}
	out<<endl;
	return 0;
}