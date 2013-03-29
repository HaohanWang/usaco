/*
ID: haohanw
PROG: subset
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

#define MAX (40*40/2)

int main()
{
	ifstream in ("subset.in");
	ofstream out ("subset.out");
	int N;
	long long result[40][MAX*2+1]={0.0};
	in>>N;
	int i, j;
	int scope=0;
	int diff=0;

	result[1][-1+MAX]=1;
	result[1][1+MAX]=1;

		for (i=2;i<=N;i++)
		{
			if (i==37)
				int a=1;
			scope=(i-1)*(i)/2;
			for (j=MAX-scope;j<=MAX+scope;j++)
			{
				if (result[i-1][j]!=0)
				{
					diff=j-MAX;
					result[i][diff+i+MAX]+=result[i-1][j];
					result[i][diff-i+MAX]+=result[i-1][j];
				}
			}
		}
		out<<result[N][0+MAX]/2<<endl;
		return 0;

}
