/*
ID:haohanw1
PROG: comehome
LANG: C++
*/
#define MAXNUM 27001

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

typedef struct ee
{
	bool v;
	int l;
} NodeInfo;

int main()
{
	ifstream in ("comehome.in");
	ofstream out ("comehome.out");
	int Graph[53][53];
	NodeInfo Node[53];
	char f, d;
	int length;
	int N;
	int i, j;
	for (i=0;i<=51;i++)
	{
		Node[i].l=MAXNUM;
		Node[i].v=0;
		for (j=0;j<=51;j++)
		{
			Graph[i][j]=MAXNUM;
		}
	}
	in>>N;
	for (i=N-1;i>=0;i--)
	{
		in>>f>>d>>length;
		if (f>='A'&&f<='Z')
		{
			if (d>='A'&&d<='Z')
			{
				Graph[f-'A'+26][d-'A'+26]=min(length,Graph[f-'A'+26][d-'A'+26]);
				Graph[d-'A'+26][f-'A'+26]=min(length,Graph[d-'A'+26][f-'A'+26]);
			}
			else
			{
				Graph[f-'A'+26][d-'a']=min(length,Graph[f-'A'+26][d-'a']);
				Graph[d-'a'][f-'A'+26]=min(length,Graph[d-'a'][f-'A'+26]);
			}
		}
		else
		{
			if (d>='A'&&d<='Z')
			{
				Graph[f-'a'][d-'A'+26]=min(length,Graph[f-'a'][d-'A'+26]);
				Graph[d-'A'+26][f-'a']=min(length,Graph[d-'A'+26][f-'a']);
			}
			else
			{
				Graph[f-'a'][d-'a']=min(length,Graph[f-'a'][d-'a']);
				Graph[d-'a'][f-'a']=min(length,Graph[d-'a'][f-'a']);
			}
		}
	}

	Node[51].l=0;
	int tempL;
	int tempM;
	bool find=false;
	int result=0;
	while (!find)
	{
		tempL=MAXNUM;
		for (i=0;i<=51;i++)
		{
			if (tempL>Node[i].l&&Node[i].v==false)
			{
				tempL=Node[i].l;
				tempM=i;
			}
		}
		if (tempM>=26&&tempM<=50)
		{
			find=true;
			result=tempM;
			break;
		}
		Node[tempM].v=true;
		for (i=0;i<=51;i++)
		{
			if (Graph[tempM][i]<MAXNUM)
			{
				Node[i].l=min(Graph[tempM][i]+Node[tempM].l,Node[i].l);
			}
		}
	}
	f=result+'A'-26;
	out<<f<<" "<<(signed int)Node[result].l<<endl;
	return 0;
}