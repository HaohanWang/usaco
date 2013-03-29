/*
ID: haohanw
PROG: holstein
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int c;
int V, G;
int feed[15][25];
int result[25];
int index=0;
bool finish=false;
typedef struct vv
{
	int V[25];
} vaccine;

ofstream out ("holstein.out");

void Search(int, int, vaccine);

vaccine Assign(vaccine i)
{
	vaccine j;
	for (int k=0;k<=24;k++)
	{
		j.V[k]=i.V[k];
	}
	return j;
}

int main()
{
	ifstream in ("holstein.in");
	
	vaccine Va;
	int i, j;

	in>>V;
	for (i=0;i<=V-1;i++)
	{
		in>>Va.V[i];
	}
	in>>G;
	for (i=0;i<=G-1;i++)
	{
		for (j=0;j<=V-1;j++)
		{
			in>>feed[i][j];
		}
	}
	int count=0;
	while (!finish)
	{
		count++;
		for (i=0;i<=G-1&&!finish;i++)
		{
			result[index]=i+1;
			index++;
			Search(i, count, Va);
			index--;
		}
	}
	//system("pause");
	return 0;
}

void Search(int i, int count, vaccine Va)
{
	//cout<<c<<endl;
	//c++;
	vaccine Vb=Assign(Va);
	int j, k;
	if (count==1)
	{
		finish=true;
		for (j=0;j<=V-1;j++)
		{
			if (Vb.V[j]-feed[i][j]>0)
			{
				finish=false;
				break;
			}
		}
		if (finish==true)
		{
			out<<index<<" ";
			for (j=0;j<=index-2;j++)
			{
				out<<result[j]<<" ";
			}
			out<<result[index-1]<<endl;
		}
	}
	else
	{
		for (k=i+1; k<=G-1&&!finish;k++)
		{
			Vb=Assign(Va);
			for (j=0;j<=V-1;j++)
			{
				Vb.V[j]-=feed[i][j];
			}
			result[index]=k+1;
			index++;
			Search(k,count-1,Vb);
			index--;
		}
	}
}