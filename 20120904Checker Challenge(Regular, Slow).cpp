/*
ID: haohanw
PROG: checker
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int N;
int Checker[14][14]={0};
ofstream out("checker.out");

int Search(int, int);
bool Check();
void Output();
int times=0;

int main()
{
	ifstream in("checker.in");
	
	in>>N;
	int index=1;
	int count=0;
	int loop=N;
	for (int i=1;i<=N;i++)
	{
		Checker[index][i]=1;
		count+=Search(loop-1,index+1);
		Checker[index][i]=0;
	}
	out<<count<<endl;
	return 0;
}

int Search(int loop,int index)
{
	int count=0;
	int i, j;
	if (loop==1)
	{
		for (i=1;i<=N;i++)
		{
			Checker[index][i]=1;
			if (Check())
			{
				if (times<3)
				{
					Output();
					times+=1;
				}
				Checker[index][i]=0;
				return 1;
			}
			else
			{
				Checker[index][i]=0;
			}
		}
		return 0;
	}
	else
	{
		for (i=1;i<=N;i++)
		{
			Checker[index][i]=1;
			if (Check())
			{
				count+=Search(loop-1,index+1);
			}
			Checker[index][i]=0;
		}
		return count;
	}
}

bool Check()
{
	/*int a=1;
	int b=3;
	int c=5;
	int d=2;
	int e=4;
	int f=7;
	if (Checker[1][a]==1&&Checker[2][b]==1&&Checker[3][c]==1&&Checker[4][d]==1&&Checker[5][e]==1&&Checker[6][f]==1)
	{
		a++;
		a--;
	}*/
	int i,j;
	int count=0;
	int dia=N;
	for (i=1;i<=N;i++)
	{
		count=0;
		for (j=1;j<=N;j++)
		{
			count+=Checker[i][j];
			if (count>1)
				return false;
		}
	}
	for (i=1;i<=N;i++)
	{
		count=0;
		for (j=1;j<=N;j++)
		{
			count+=Checker[j][i];
			if (count>1)
				return false;
		}
	}
	for (dia=N;dia>=2;dia--)
	{
		count=0;
		i=1;
		for (j=N+1-dia;j<=N;j++)
		{
			count+=Checker[i][j];
			if (count>1)
				return false;
			i++;
		}
	}
	for (dia=N;dia>=3;dia--)
	{
		count=0;
		j=1;
		for (i=N+2-dia;i<=N;i++)
		{
			count+=Checker[i][j];
			if (count>1)
				return false;
			j++;
		}
	}
	for (dia=N;dia>=2;dia--)
	{
		count=0;
		i=1;
		for (j=dia;j>=1;j--)
		{
			count+=Checker[i][j];
			if (count>1)
				return false;
			i++;
		}
	}
	/*for (dia=N;dia>=2;dia--)
	{
		count=0;
		i=1;
		for (j=dia;j>=2;j--)
		{
			count+=Checker[i][j];
			if (count>1)
				return false;
			i++;
		}
	}*/
	for (dia=N;dia>=2;dia--)
	{
		count=0;
		j=N;
		for (i=N+2-dia;i<=N;i++)
		{
			count+=Checker[i][j];
			if (count>1)
				return false;
			j--;
		}
	}
	return true;
}

void Output()
{
	int i, j;
	for (i=1;i<=N;i++)
	{
		for (j=1;j<=N;j++)
		{
			if (Checker[i][j]==1)
			{
				if (i!=N)
				{
					out<<j<<" ";
				}
				else
				{
					out<<j<<endl;
				}
			}
		}
	}
}