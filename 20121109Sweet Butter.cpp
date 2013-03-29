/*
ID: haohanw1
PROG: butter
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

typedef struct cc{
	int a;
	int b;
	int l;
} ConnectedPath;

typedef struct dd{
	int b;
	int l;
	dd* next;
} Path;

int main()
{
	ifstream in ("butter.in");
	ofstream out ("butter.out");
	int P[801]={0};
	int C[801]={0};
	Path* path[801];
	Path* pathTail[801];
	int n,p,c;
	in>>n>>p>>c;
	int i,j;
	int a,b,l;
	Path* s;
	Path* t;
	for (i=1;i<=p;i++)
	{
		s= new Path;
		s->b=0;
		s->l=0;
		s->next=NULL;
		path[i]=s;
		pathTail[i]=path[i];
	}
	for (i=0;i<=n-1;i++)
	{
		in>>j;
		C[j]++;
	}
	j=0;
	for (i=0;i<=c-1;i++)
	{
		in>>a>>b>>l;
		s= new Path;
		s->b=b;
		s->l=l;
		s->next=NULL;
		pathTail[a]->next=s;
		pathTail[a]=pathTail[a]->next;
		s = new Path;
		s->b=a;
		s->l=l;
		s->next=NULL;
		pathTail[b]->next=s;
		pathTail[b]=pathTail[b]->next;
	}
	long max=100000000;
	long tempMax=0;
	int queue[800]={0};
	int head=0,tail=0;
	int u=0;
	for (i=1;i<=p;i++)
	{
		tempMax=0;
		head=0;
		tail=0;
		for (j=1;j<=p;j++)
		{
			queue[j]=0;
			P[j]=0;
		}
		P[i]=0;
		queue[tail++]=i;
		tail=tail%800;
		while (head!=tail)
		{
			u=queue[head++];
			head=head%800;
			for (s=path[u];s!=NULL;s=s->next)
			{
				if (s->b!=0)
				{
					int v=s->b;
					if ((P[v]==0||P[v]>P[u]+s->l)&&v!=i)
					{
						P[v]=P[u]+s->l;
						queue[tail++]=v;
						tail=tail%800;
					}
				}
			}
		}
		for (j=1;j<=p;j++)
		{
			if (C[j]!=0)
			{
				tempMax+=C[j]*P[j];
			}
		}
		if (tempMax!=0&&tempMax<max)
		{
			max=tempMax;
		}
	}
	out<<max<<endl;
	return 0;
}
