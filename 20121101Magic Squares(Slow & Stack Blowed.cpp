/*
ID: haohanw1
PROG: msquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char A(int *a)
{
	int temp, i;
	for (i=0;i<=3;i++)
	{
		temp=a[i];
		a[i]=a[7-i];
		a[7-i]=temp;
	}
	return 'A';
}

char B(int *a)
{
	int temp[8];
	int i;
	for (i=0;i<=7;i++)
	{
		temp[i]=a[i];
	}
	for (i=0;i<=3;i++)
	{
		a[i]=temp[(i+3)%4];
	}
	for (i=4;i<=7;i++)
	{
		a[i]=temp[(i+1)%4+4];
	}
	return 'B';
}

char C(int *a)
{
	int temp;
	temp=a[1];
	a[1]=a[6];
	a[6]=a[5];
	a[5]=a[2];
	a[2]=temp;
	return 'C';
}

void Copy(int *a, int *b)
{
	for (int i=0;i<=7;i++)
	{
		b[i]=a[i];
	}
}

void CopyR(char *a, char *b, int num)
{
	for (int i=0;i<=num-1;i++)
	{
		b[i]=a[i];
	}
}

bool Compare(int *a, int *b)
{
	for (int i=0;i<=7;i++)
	{
		if (a[i]!=b[i])
			return false;
	}
	return true;
}

typedef struct cc
{
	int str[8];
	char result[1000];
	int index;
	int Cnumber;
	int Bnumber;
	cc * next;
} Unit;

int main()
{
	ifstream in ("msquare.in");
	ofstream out ("msquare.out");
	int s[8]={1, 2, 3, 4, 5, 6, 7, 8};
	int g[8];
	int i;
	for (i=0;i<=7;i++)
	{
		in>>g[i];
	}
	Unit * head=new Unit;
	Copy(s,head->str);
	head->index=0;
	head->Cnumber=0;
	head->Bnumber=0;
	head->next=NULL;
	Unit * tail=head;
	Unit * p;
	Unit * q;
	Unit * t = new Unit;
	int count=0;
	for (p=head;p!=NULL;p=p->next)
	{
		out<<count++<<endl;
		delete t;
		/*if (p->index>0)
		{
			out<<p->index<<endl;
			out<<p->result[p->index-1]<<endl;
			for (i=0;i<=7;i++)
			{
				out<<p->str[i]<<" ";
			}
			out<<endl<<"---------------"<<endl;
		}*/
		if (Compare(p->str,g))
		{
			out<<p->index<<endl;
			for (i=0;i<=p->index-1;i++)
			{
				out<<p->result[i];
				if ((i+1)%60==0)
					out<<endl;
			}
			if (i%60!=0||i==0)
				out<<endl;
			break;
		}
		else
		{
			if (p->index==0)
			{
				/////////1. A
				q= new Unit;
				Copy(p->str,q->str);
				CopyR(p->result,q->result,p->index);
				q->index=p->index+1;
				q->result[p->index]=A(q->str);
				q->Cnumber=0;
				q->Bnumber=0;
				tail->next=q;
				tail=tail->next;
				//////////2. B
				q= new Unit;
				Copy(p->str,q->str);
				CopyR(p->result,q->result,p->index);
				q->index=p->index+1;
				q->result[p->index]=B(q->str);
				q->Cnumber=0;
				q->Bnumber=1;
				tail->next=q;
				tail=tail->next;
				//////////3. C
				q= new Unit;
				Copy(p->str,q->str);
				CopyR(p->result,q->result,p->index);
				q->index=p->index+1;
				q->result[p->index]=C(q->str);
				q->Cnumber=1;
				q->Bnumber=0;
				tail->next=q;
				tail=tail->next;
			}
			else if (p->result[p->index-1]=='A')
			{
				//////////4 B
				q= new Unit;
				Copy(p->str,q->str);
				CopyR(p->result,q->result,p->index);
				q->index=p->index+1;
				q->result[p->index]=B(q->str);
				q->Cnumber=0;
				q->Bnumber=1;
				tail->next=q;
				tail=tail->next;
				//////////5 C
				q= new Unit;
				Copy(p->str,q->str);
				CopyR(p->result,q->result,p->index);
				q->index=p->index+1;
				q->result[p->index]=C(q->str);
				q->Cnumber=1;
				q->Bnumber=0;
				tail->next=q;
				tail=tail->next;
			}
			else if (p->result[p->index-1]=='B')
			{
				//////////6 A
				q= new Unit;
				Copy(p->str,q->str);
				CopyR(p->result,q->result,p->index);
				q->index=p->index+1;
				q->result[p->index]=A(q->str);
				q->Cnumber=0;
				q->Bnumber=0;
				tail->next=q;
				tail=tail->next;
				//////////7 C
				q= new Unit;
				Copy(p->str,q->str);
				CopyR(p->result,q->result,p->index);
				q->index=p->index+1;
				q->result[p->index]=C(q->str);
				q->Cnumber=1;
				q->Bnumber=0;
				tail->next=q;
				tail=tail->next;
				if (q->Bnumber!=3)
				{
					q= new Unit;
					Copy(p->str,q->str);
					CopyR(p->result,q->result,p->index);
					q->index=p->index+1;
					q->result[p->index]=B(q->str);
					q->Cnumber=0;
					q->Bnumber=1+p->Bnumber;
					tail->next=q;
					tail=tail->next;
				}
			}
			else
			{
				/////////8. A
				q= new Unit;
				Copy(p->str,q->str);
				CopyR(p->result,q->result,p->index);
				q->index=p->index+1;
				q->result[p->index]=A(q->str);
				q->Cnumber=0;
				q->Bnumber=0;
				tail->next=q;
				tail=tail->next;
				//////////9. B
				q= new Unit;
				Copy(p->str,q->str);
				CopyR(p->result,q->result,p->index);
				q->index=p->index+1;
				q->result[p->index]=B(q->str);
				q->Cnumber=0;
				q->Bnumber=1;
				tail->next=q;
				tail=tail->next;
				if (p->Cnumber!=3)
				{
					q= new Unit;
					Copy(p->str,q->str);
					CopyR(p->result,q->result,p->index);
					q->index=p->index+1;
					q->result[p->index]=C(q->str);
					q->Cnumber=1+p->Cnumber;
					q->Bnumber=0;
					tail->next=q;
					tail=tail->next;
				}
			}
		}
		t=p;
	}
	return 0;
}