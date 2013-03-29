/*
ID:haohanw1
PROG: agrinet
LANG: C++
*/
#define MAXNUM 100001

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in ("agrinet.in");
	ofstream out ("agrinet.out");

	int N;
	int Agri[100][100];
	in>>N;
	int i, j;
	for (i=0;i<=N-1;i++)
	{
		for (j=0;j<=N-1;j++)
		{
			in>>Agri[i][j];
		}
	}
	int distance=0;
	int Dis[100]={0};
	for (i=0;i<=99;i++)
	{
		Dis[i]=MAXNUM;
	}
	bool A[100]={false};
	A[0]=true;
	int tempM=0;
	int tempP=0;
	for (int count=N-1;count>=1;count--)
	{
		tempM=MAXNUM;
		for (i=0;i<=N-1;i++)
		{
			if (A[i]==true)
			{
				for (j=0;j<=N-1;j++)
				{
					if (A[j]==false)
					{
						Dis[j]=min(Dis[j],Agri[i][j]);
					}
				}
			}
		}
		for (i=0;i<=N-1;i++)
		{
			if (A[i]==false&&tempM>Dis[i])
			{
				tempM=Dis[i];
				tempP=i;
			}
		}
		A[tempP]=true;
		distance+=tempM;
	}
	out<<distance<<endl;
	return 0;
}