/*
ID: haohanw1
PROG: concom
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in ("concom.in");
	ofstream out ("concom.out");
	int N;
	int Com[101][101]={0};
	int Result[101][101]={0};
	in>>N;
	int i, j, stock;
	int m, p, q;
	bool finish=false;
	for (m=1;m<=N;m++)
	{
		in>>i>>j>>stock;
		Com[i][j]=stock;
	}
	for (i=1;i<=100;i++)
	{
		for (j=1;j<=100;j++)
		{
			if (Com[i][j]>=50)
			{
				Result[i][j]=1;
			}
		}
	}
	while (!finish)
	{
		finish=true;
		for (i=1;i<=100;i++)
		{
			for (j=1;j<=100;j++)
			{
				if (Result[i][j]==1)
				{
					finish=false;
					Result[i][j]=2;
					for (p=1;p<=100;p++)
					{
						if (Result[i][p]==0)
						{
							Com[i][p]+=Com[j][p];
							if (Com[i][p]>=50)
							{
								Result[i][p]=1;
							}
						}
					}
				}
			}
		}
	}
	for (i=1;i<=100;i++)
	{
		for (j=1;j<=100;j++)
		{
			if (Result[i][j]!=0&&i!=j)
			{
				out<<i<<" "<<j<<endl;
			}
		}
	}
	return 0;
}