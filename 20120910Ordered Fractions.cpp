/*
ID: haohanw
PROG: frac1
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

typedef struct nnn
{
	int nume;
	int denom;
	double v;
	nnn* next;
} frac;

bool Reduced(int j, int i)
{
	int a;
	for (a=2;a<=j;a++)
	{
		if (j%a==0&&i%a==0)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	ifstream in ("frac1.in");
	ofstream out ("frac1.out");

	int N;
	in>>N;
	frac* h=new(frac);
	h->nume=0;
	h->denom=1;
	h->v=0;
	h->next=NULL;
	frac* t=h->next;
	frac* a=NULL;
	bool putin=false;

	int i, j;
	for (i=1;i<=N;i++)
	{
		for (j=1;j<i;j++)
		{
			if (!Reduced(j, i))
			{
				putin=false;
				frac *c=new(frac);
				c->denom=i;
				c->nume=j;
				c->v=(double)j/(double)i;
				a=h;
				while (a->next!=NULL&&!putin)
				{
					if (c->v>=a->next->v)
					{
						a=a->next;
					}
					else
					{
						c->next=a->next;
						a->next=c;
						putin=true;
					}
				}
				if (!putin)
				{
					a->next=c;
					c->next=NULL;
				}
			}
		}
	}
	for (a=h;a!=NULL;a=a->next)
	{
		out<<a->nume<<"/"<<a->denom<<endl;
	}
	out<<"1/1"<<endl;
	return 0;
}
