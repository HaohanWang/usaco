/*
ID: haohanw1
PROG: contact
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

typedef struct cc
{
	string str;
	int count;
	cc* next;
}Unit;

int main()
{
	//declare
	ifstream in ("contact.in");
	ofstream out ("contact.out");
	char str[200001]={' '};
	char buffer[81]={' '};
	int result [13][4097];
	cc* head = new Unit;
	head->count=0;
	head->str="";
	head->next=NULL;
	cc* tail=head;
	cc* p=NULL;
	cc* q=NULL;
	int i=0, j=0, k=0, length;
	int A, B, N;
	//read in
	in>>A>>B>>N;
	in.getline(buffer,80);
	while(in.getline(buffer,81))
	{
		k=0;
		for (i=j;i<j+80&&buffer[k]!='\0';i++)
		{
			str[i]=buffer[k++];
		}
		j+=80;
	}
	length=i;
	str[++i]='\0';
	// end read in
	// clear result
	for (j=A;j<=B;j++)
	{
		for (i=0;i<=pow((double)2,j);i++)
		{
			result[j][i]=0;
		}
	}
	//end clear result
	//main process
	int num;
	for (i=0;i<=length;i++)
	{
		for (j=A;j<=B;j++)
		{
			num=0;
			for (k=0;k<=j-1&&i+k<=length;k++)
			{
				num=num*2+(str[i+k]-'0');
			}
			if (i+k<=length)
			{
				result[j][num]+=1;
			}
		}
	}
	//end main
	//sort the result
	char r[12];
	for (j=A;j<=B;j++)
	{
		for (i=0;i<=pow((double)2,j);i++)
		{
			if (result[j][i]>0)
			{
				for (p=head;p->next!=NULL&&p->next->count>=result[j][i];p=p->next)
				{
				}
				q= new Unit;
				q->count=result[j][i];
				q->next=p->next;
				q->str="";
				num=i;
				for (k=0;k<=B-1;k++)
				{
					r[k]='0';
				}
				k=0;
				for (;num>0;num/=2)
				{
					r[k++]=num%2+'0';
				}
				for (k=j-1;k>=0;k--)
				{
					q->str+=r[k];
				}
				p->next=q;
			}
		}
	}
	//end sort
	//output
	head=head->next;
	int temp=head->count;
	out<<temp<<endl;
	int count=0;
	for (p=head;p!=NULL;p=p->next)
	{
		if (p->count<temp)
		{
			temp=p->count;
			N--;
			if (N==0)
				break;
			if (count!=0)
			{
				out<<endl;
			}
			else
			{
				//out<<endl;
			}
			out<<temp<<endl;
			count=0;
		}
		if (count==0)
		{
			out<<p->str;
			count++;
		}
		else
		{
			out<<" "<<p->str;
			count++;
		}
		if (count==6)
		{
			out<<endl;
			count=0;
		}
	}
	if (count!=0)
	{
		out<<endl;
	}
	//system("pause");
	return 0;
}