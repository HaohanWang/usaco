/*
ID: haohanw
PROG: nocows
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
	ifstream in ("nocows.in");
	ofstream out ("nocows.out");

	int K, N, n;
	int ped[100][100];   //ped[height][module];
	in>>N>>K;
	int i, j, p, q, t;
	n=(N-1)/2;
	for (i=1;i<=K;i++)
	{
		for (j=1;j<=n;j++)
		{
			ped[i][j]=0;
		}
	}
	ped[2][1]=1;
	for (i=2;i<=K-1;i++)
	{
		for (j=i-1;j<=pow(2,(double)i-1)-1&&j<n;j++)
		{
			ped[i+1][j+1]+=ped[i][j]*2;
			ped[i+1][j+1]=ped[i+1][j+1]%9901;
			for (p=2;p<=i;p++)
			{
				for (q=p-1;q<=pow(2,(double)p-1)-1&&q<=n;q++)
				{
					if (i==p&&j==q-1)
					{
						break;
					}
					else if (i==p&&j==q)
					{
						if (j+q+1<=n)
						{
							ped[i+1][j+q+1]+=ped[i][j]*ped[p][q];
							ped[i+1][j+q+1]=ped[i+1][j+q+1]%9901;
						}
					}
					else
					{
						if (j+q+1<=n)
						{
							ped[i+1][j+q+1]+=2*ped[i][j]*ped[p][q];
							ped[i+1][j+q+1]=ped[i+1][j+q+1]%9901;
						}
					}
				}
			}
		}
		t=pow(2,(double)i);
		if (t<=n+1)
		{
			ped[i+1][t-1]=1;
		}
	}
	if (N%2==1)
	{
		out<<ped[K][n]<<endl;
	}
	else
	{
		out<<"0"<<endl;
	}
	/*for (i=2;i<=K;i++)
	{
		for (j=1;j<=n;j++)
		{
			out<<ped[i][j]<<"\t";
		}
		out<<endl;
	}*/
	return 0;
}