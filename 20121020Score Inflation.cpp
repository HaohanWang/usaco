/*
ID:haohanw1
PROG: inflate
LANG: C++
*/
//f[i,v]=max{f[i,v-vi]+wi,f[i-1,v]}

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int M, N;

int main()
{
	ifstream in ("inflate.in");
	ofstream out ("inflate.out");
	int Bag[10000][2];
	int Value[10001]={0};
	in>>M>>N;
	int i, j;
	for (i=0;i<=N-1;i++)
	{
		in>>Bag[i][0]>>Bag[i][1];
	}
	for (i=0;i<=M;i++)
	{
		Value[i]=Bag[0][0]*(i/Bag[0][1]);
	}
	for (i=1;i<=N-1;i++)
	{
		for (j=0;j<=M;j++)
		{
			if (j>=Bag[i][1])
			{
				Value[j]=max(Value[j],Value[j-Bag[i][1]]+Bag[i][0]);
			}
		}
	}
	out<<Value[M]<<endl;
	return 0;
}