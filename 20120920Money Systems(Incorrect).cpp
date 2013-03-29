/*
ID: haohanw1
PROG: money
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int cmp(const void *a, const void *b)
{
	return (int*)a-(int*)b;
}

int main()
{
	ifstream in ("money.in");
	ofstream out ("money.out");
	int Coin[26];
	int V, N;
	in>>V>>N;
	int i, j;
	int ways=0;
	int quo, rem;
	long long Result[26][10001];
	for (i=1;i<=V;i++)
	{
		in>>Coin[i];
	}
	qsort(Coin,V,sizeof(int),cmp);
	for (i=1;i<=V;i++)
	{
		for (j=1;j<=N;j++)
		{
			Result[i][j]=0;
			if (i==1&&j%Coin[1]==0)
			{
				Result[i][j]=1;
			}
		}
	}
	for (i=2;i<=V;i++)
	{
		for (j=1;j<=N;j++)
		{
			if (j%Coin[i]==0)
			{
				Result[i][j]+=1;
			}
			quo=j/Coin[i];
			for (;quo>=1;quo--)
			{
				Result[i][j]+=Result[i-1][j-quo*Coin[i]];
			}
		}
	}
	out<<Result[V][N]<<endl;
	return 0;
}