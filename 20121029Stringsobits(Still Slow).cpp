/*
ID: haohanw1
PROG: kimbits
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

typedef struct cc
{
	int num;
	int value;
	cc* next;
} Unit;

int main()
{
	ifstream in ("kimbits.in");
	ofstream out ("kimbits.out");
	int N, L, I;
	in>>N>>L>>I;
	int i, k;
	int r[32]={0};
	int count=2;
	cc* head = new cc;
	head->value=1;
	head->num=1;
	head->next=NULL;
	//head->visit=false;
	if (I<=2)
	{
		if (I==1)
		{
			for (;N>=1;N--)
			{
				out<<"0";
			}
			out<<endl;
			return 0;
		}
		else
		{
			for (;N>=2;N--)
			{
				out<<"0";
			}
			out<<"1"<<endl;
			return 0;
		}
	}
	cc* tail=head;
	cc* p;
	cc* q=new cc;
	for (p=head;p!=NULL;p=p->next)
	{
		delete q;
		//cout<<q->value<<endl;
		/*if (p->visit==false)
		{*/
			//p->visit=true;
			q=new cc;
			q->num=p->num;
			q->value=p->value*2;
			q->next=NULL;
			//q->visit=false;
			count++;
			tail->next=q;
			tail=tail->next;
			//out<<q->value<<" "<<q->num<<endl;
			if (count==I)
				break;
			if (p->num<L)
			{
				q=new cc;
				q->num=p->num+1;
				q->value=p->value*2+1;
				q->next=NULL;
				//q->visit=false;
				count++;
				tail->next=q;
				tail=tail->next;
				//out<<q->value<<" "<<q->num<<endl;
				if (count==I)
					break;
			}
		//}
		q=p;
	}
	i=tail->value;
	for (k=0;k<=N-1;k++)
	{
		r[k]=i%2;
		i/=2;
	}
	for (k=N-1;k>=0;k--)
	{
		out<<r[k];
	}
	out<<endl;
	//system("pause");
	return 0;
}