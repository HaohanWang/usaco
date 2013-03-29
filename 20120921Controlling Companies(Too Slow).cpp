/*
ID: haohanw1
PROG: concom
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

typedef struct cc
{
	int a;
	int b;
	bool v;
	cc* n;
} ComRelation;

int main()
{
	ifstream in ("concom.in");
	ofstream out ("concom.out");
	int N;
	int Com[101][101]={0};
	in>>N;
	int i, j, stock;
	int m;
	ComRelation* head=new ComRelation;
	head->a=0;
	head->b=0;
	head->v=1;
	head->n=NULL;
	ComRelation* t=NULL;
	ComRelation* p=head;
	ComRelation* q=NULL;
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
				q=new ComRelation;
				q->a=i;
				q->b=j;
				q->v=false;
				q->n=NULL;
				p->n=q;
				p=p->n;
			}
		}
	}
	while (!finish)
	{
		finish=true;
		//cout<<"a"<<endl;
		for (p=head;p!=NULL;p=p->n)
		{
			if (p->v==false)
			{
				finish=false;
				p->v=true;
				for (i=1;i<=100;i++)
				{
					if (p->a==i)
					{
					}
					else
					{
					if (Com[p->a][i]<50&&Com[p->a][i]+Com[p->b][i]>=50)
					{
						bool change=false;
						Com[p->a][i]+=Com[p->b][i];
						//cout<<p->a<<"\t"<<i<<endl;
						t=new ComRelation;
						t->a=p->a;
						t->b=i;
						t->v=false;
						t->n=NULL;
						for (q=head;q->n!=NULL;q=q->n)
						{
							if (q->n->a>t->a)
							{
								t->n=q->n;
								q->n=t;
								change=true;
								break;
							}
							else if (q->n->a==t->a&&q->n->b>t->b)
							{
								t->n=q->n;
								q->n=t;
								change=true;
								break;
							}
							else if (q->n->a==t->a&&q->n->b==t->b)
							{
								change=true;
								break;
							}
						}
						if (change==false)
						{
							t->n=q->n;
							q->n=t;
						}
					}
					else
					{
						Com[p->a][i]+=Com[p->b][i];
					}
					}
				}
			}

		}
	}
	for (p=head->n;p!=NULL;p=p->n)
	{
		if (p->a!=p->b)
			out<<p->a<<" "<<p->b<<endl;
	}
	return 0;
}