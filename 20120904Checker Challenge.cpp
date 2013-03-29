/*
ID: haohanw
PROG: checker
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

ofstream out("checker.out");
int N;
int row[14]={0};
int dia1[24]={0};
int dia2[29]={0};
int result[14]={0};
int countresult=0;

bool PlaceIn(int, int);
void Remove(int, int);
int TryPlace(int, int);

int main()
{
	ifstream in("checker.in");
	
	int index=1;
	int i;
	int loop;
	int count=0;

	in>>N;
	loop=N;
	for (i=1;i<=N;i++)
	{
		if (PlaceIn(index,i))
		{
			count+=TryPlace(loop-1,index+1);
			Remove(index, i);
		}
	}
	out<<count<<endl;
	return 0;
}

int TryPlace(int loop, int index)
{
	int count=0;
	int i;
	if (loop==1)
	{
		for (i=1;i<=N;i++)
		{
			if (PlaceIn(index,i))
			{
				countresult+=1;
				if(countresult<=3)
				{
					for (int j=1;j<=N-1;j++)
					{
						out<<result[j]<<" ";
					}
					out<<result[N]<<endl;
				}
				Remove(index, i);
				count=1;
			}
		}
	}
	else
	{
		for (i=1;i<=N;i++)
		{
			if (PlaceIn(index, i))
			{
				count+=TryPlace(loop-1,index+1);
				Remove(index,i);
			}
		}
	}
	return count;
}

bool PlaceIn(int i, int j)
{
	if (row[j]==0&&dia1[j-i+N-1]==0&&dia2[i+j]==0)
	{
		row[j]=1;
		dia1[j-i+N-1]=1;
		dia2[i+j]=1;
		result[i]=j;
		return true;
	}
	else
	{
		return false;
	}
}

void Remove(int i, int j)
{
	row[j]=0;
	dia1[j-i+N-1]=0;
	dia2[i+j]=0;
	result[i]=0;
}