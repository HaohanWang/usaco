/*
ID:haohanw
PROG: numtri
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int tri[1001][1001];
int R;


int main()
{
	ifstream in("numtri.in");
	ofstream out("numtri.out");

	in>>R;
	int i, j;
	for (i=1;i<=R;i++)
	{
		for (j=1;j<=i;j++)
		{
			in>>tri[i][j];
		}
	}
	
	if (R==1)
	{
		out<<tri[1][1]<<endl;
	}
	else
	{
		for (i=R-1;i>=1;i--)
		{
			for (j=1;j<=i;j++)
			{
				tri[i][j]=max(tri[i+1][j],tri[i+1][j+1])+tri[i][j];
			}
		}
		out<<tri[1][1]<<endl;
	}

	return 0;
}

