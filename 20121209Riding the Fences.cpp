/*
ID:haohanw1
PROG:fence
LANG:C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in ("fence.in");
	ofstream out ("fence.out");

	int** grid = (int**)malloc(502*sizeof(int*));
	for (int n = 0;n<=502;n++)
	{
		grid[n]=(int*)malloc(502*sizeof(int));
	}
	int result[1024]={0};
	int stack[1024]={0};
	int s=0;
	int r=0;
	int num;
	int i, j;
	for (i=0;i<=501;i++)
	{
		for (j=0;j<=501;j++)
		{
			grid[i][j]=0;
		}
	}
	in>>num;
	for (int m=num;m>=1;m--)
	{
		in>>i>>j;
		grid[i][j]++;
		grid[j][i]++;
	}
	int start=0;
	for (i=1;i<=501;i++)
	{
		int countedge=0;
		for (j=1;j<=501;j++)
		{
			countedge+=grid[i][j];
			countedge+=grid[j][i];
		}
		if (countedge%4==2)
		{
			start=i;
			stack[s++]=start;
			break;
		}
	}
	if (start==0)
	{
		stack[s++]=1;
	}
	bool edgemore=true;
	while (r!=num+1)
	{
		for (i=1;i<=500;i++)
		{
			edgemore=false;
			if (grid[stack[s-1]][i]!=0)
			{
				edgemore=true;
				grid[stack[s-1]][i]--;
				grid[i][stack[s-1]]--;
				stack[s++]=i;
				break;
			}
		}
		if (!edgemore)
		{
			result[r++]=stack[--s];
		}
		//cout<<r<<endl;
	}
	for (i=r-1;i>=0;i--)
	{
		out<<result[i]<<endl;
	}
	return 0;
}