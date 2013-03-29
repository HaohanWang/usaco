/*
ID: haohanw
PROG: subset
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

typedef struct cc
{
	int v;
	cc* n;
} num;

int main()
{
	ifstream in ("subset.in");
	ofstream out ("subset.out");
	int N;
	in>>N;
	int result=0;
	num Num[40];
	cc* P[40];
	cc* T[40];
	int i, total;
	for (i=1;i<=N;i++)
	{
		Num[i].n=NULL;
		Num[i].v=i;
		P[i]=&Num[i];
		T[i]=P[i];
	}
	total=(N+1)*N/2;
	cc* h1=&Num[1];
	cc* h2=NULL;
	cc* h3=NULL;
	if (N==1||N==2)
	{
		out<<0<<endl;
		return 0;
	}
	//for (i=N-1;i>N/2;i--)
	//{
	//	//cout<<i<<endl;
	//	for (h1=P[i+1];h1!=NULL;h1=h1->n)
	//	{
	//		h2=new(num);
	//		h2->v=P[i]->v+h1->v;
	//		if (h2->v==total/2)
	//		{
	//			result+=1;
	//		}
	//		else if (h2->v>total/2)
	//		{
	//		}
	//		else
	//		{
	//			h2->n=P[i]->n;
	//			P[i]->n=h2;
	//		}
	//		h3=h1;
	//	}
	//	h3->n=P[i]->n;
	//	P[i]=P[i+1];
	//}
	for (i=2;i<=N;i++)
	{
		//cout<<i<<endl;
		for (h1=P[i-1];h1!=NULL;h1=h1->n)
		{
			h2=new(num);
			h2->v=P[i]->v+h1->v;
			h2->n=NULL;
			if (h2->v==total/2)
			{
				result+=1;
			}
			else if (h2->v>total/2)
			{
				//break;
			}
			else
			{
				T[i]->n=h2;
				T[i]=T[i]->n;
			}
			h3=h1;
		}
		h3->n=P[i];
		P[i]=P[i-1];
	}
	/*h1=&Num[N/2];
	for (;h1!=NULL;h1=h1->n)
	{
		for (h2=&Num[N/2+1];h2!=NULL;h2=h2->n)
		{
			if (h1->v+h2->v==total/2)
				result+=1;
		}
	}*/
	out<<result/2<<endl;
	return 0;
}