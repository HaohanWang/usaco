/*
ID: haohanw
PROG: runround
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

typedef struct cc
{
	int digit;
	bool visited;
	cc* next;
} NUM;

int main()
{
	ifstream in ("runround.in");
	ofstream out ("runround.out");

	unsigned long M, N;;
	in>>N;
	cc* h=NULL;
	cc* p=NULL;
	cc* q=NULL;
	cc* t=NULL;
	bool unique[10]={false};
	int total;
	int count;
	int last;
	int move;
	bool m0=false;
	while (1)
	{
		for (int i=0;i<=9;i++)
		{
			unique[i]=false;
		}
		N+=1;
		M=N;
		m0=false;
		count=0;
		total=0;
		h=new NUM;
		h->digit=M%10;
		unique[h->digit]=true;
		h->next=NULL;
		h->visited=false;
		total++;
		if (h->digit==0)
		{
			m0=true;
		}
		M/=10;
		p=h;
		t=h;
		while (M!=0)
		{
			p=new NUM;
			p->digit=M%10;
			total++;
			M/=10;
			p->next=h;
			p->visited=false;
			if (p->digit==0||unique[p->digit]==true)
			{
				m0=true;
				break;
			}
			unique[p->digit]=true;
			h=p;
		}
		t->next=h;
		if (!m0)
		{
			p=h;
			last=0;
			while (p->visited==false&&p->digit!=last)
			{
				last=p->digit;
				p->visited=true;
				count++;
				move=p->digit;
				for (;move>=1;move--)
				{
					p=p->next;
				}
			}
			if (count==total&&p->digit!=last&&p==h)
			{
				out<<N<<endl;
				break;
			}
		}
		q=h;
		for (p=h->next;p!=t;p=p->next)
		{
			delete q;
			q=p;
		}
		delete t;
	}
}