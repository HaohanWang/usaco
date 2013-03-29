/*
ID: haohanw
PROG: milk
LANG: C++
*/

#include <iostream>
#include <fstream>
#include<stdlib.h>

using namespace std;

typedef struct farmer
{
	int Price;
	int Total;
} Farmer;

int PriceCompare(const void *a, const void *b)
{
	Farmer *fa, *fb;
	fa=(Farmer*)a;
	fb=(Farmer*)b;
	if (fa->Price>fb->Price)
	{
		return 1;
	}
	else if (fa->Price<fb->Price)
	{
		return -1;
	}
	return 0;
}

int main()
{
	ifstream fin ("milk.in");
	ofstream fout ("milk.out");

	int N, M, i, S=0;
	Farmer P[5000];
	fin>>N>>M;
	for (i=0;i<=M-1;i++)
	{
		fin>>P[i].Price>>P[i].Total;
	}
	qsort(P,M,sizeof(Farmer),PriceCompare);

	for (i=0;i<=M-1;i++)
	{
		if (P[i].Total<N)
		{
			N=N-P[i].Total;
			S+=P[i].Price*P[i].Total;
		}
		else
		{
			S+=P[i].Price*N;
			break;
		}
	}
	fout<<S<<endl;

	return 0;
}