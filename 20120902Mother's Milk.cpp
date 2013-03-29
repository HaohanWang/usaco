/*
ID:haohanw
PROG: milk3
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int A, B, C, a, b, c;
typedef struct tri
{
	int a;
	int b;
	int c;
	bool v;
	bool o;
} Tri;
Tri queue[8000];
int result[21];
//int rindex=0;
bool putin=true;

void NextState(Tri);
void AddState(Tri);
int Left(int, int);
int Goal(int, int);

int cmp(const void *va, const void *vb)
{
	return *(int*)va-*(int*)vb;
}

int main()
{
	ifstream in("milk3.in");
	ofstream out("milk3.out");

	in>>A>>B>>C;
	a=0; 
	b=0;
	c=C;
	int i;
	for (i=0;i<=7999;i++)
	{
		queue[i].a=-1;
		//queue[i].o=false;
		//queue[i].v=false;
	}
	/*for (i=0;i<=19;i++)
	{
		result[i]=-1;
	}*/
	queue[0].a=a;
	queue[0].b=b;
	queue[0].c=c;
	queue[0].o=false;
	while (putin)
	{
		putin=false;
		for (i=0;i<=7999;i++)
		{
			if(queue[i].a==-1)
			{
				break;
			}
			else
			{
				if (queue[i].a==0)
				{
					result[queue[i].c]=1;
					//rindex+=1;
				}
				if (queue[i].o==false)
				{
					NextState(queue[i]);
					//queue[i].v=true;
					queue[i].o=true;
				}
			}
		}
	}
	int count=0;
	for (i=0;i<=20;i++)
	{
		if (result[i]==1)
		{
			if (count!=0)
			{
				out<<" ";
			}
			out<<i;
			count+=1;
		}
	}
	out<<endl;;
	return 0;
}

void NextState(Tri item)
{
	Tri temp;
	if (item.a!=0)
	{
		temp.a=item.a;
		temp.b=item.b;
		temp.c=item.c;
		temp.a=Left(item.a+item.b, B);
		temp.b=Goal(item.a+item.b, B);
		AddState(temp);
		temp.a=item.a;
		temp.b=item.b;
		temp.c=item.c;
		temp.a=Left(item.a+item.c,C);
		temp.c=Goal(item.a+item.c,C);
		AddState(temp);
	}
	if (item.b!=0)
	{
		temp.a=item.a;
		temp.b=item.b;
		temp.c=item.c;
		temp.b=Left(item.a+item.b, A);
		temp.a=Goal(item.a+item.b, A);
		AddState(temp);
		temp.a=item.a;
		temp.b=item.b;
		temp.c=item.c;
		temp.b=Left(item.b+item.c,C);
		temp.c=Goal(item.b+item.c,C);
		AddState(temp);
	}
	if (item.c!=0)
	{
		temp.a=item.a;
		temp.b=item.b;
		temp.c=item.c;
		temp.c=Left(item.c+item.b, B);
		temp.b=Goal(item.c+item.b, B);
		AddState(temp);
		temp.a=item.a;
		temp.b=item.b;
		temp.c=item.c;
		temp.c=Left(item.a+item.c,A);
		temp.a=Goal(item.a+item.c,A);
		AddState(temp);
	}
}

int Left(int m, int n)
{
	if (m<=n)
		return 0;
	else
		return m-n;
}

int Goal(int m, int n)
{
	if (m<=n)
		return m;
	else
		return n;
}

void AddState(Tri item)
{
	int i;
	bool exist=false;
	for (i=0;i<=7999;i++)
	{
		if (queue[i].a==-1)
			break;
		else
		{
			if(queue[i].a==item.a&&queue[i].b==item.b&&queue[i].c==item.c)
			{
				exist=true;
				break;
			}
		}
	}
	if (!exist)
	{
		queue[i].a=item.a;
		queue[i].b=item.b;
		queue[i].c=item.c;
		queue[i].o=false;
		putin=true;
	}
}