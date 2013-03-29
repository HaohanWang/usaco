/*
ID:haohanw1
PROG: fracdec
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

string convertInt(int number)
{
    if (number == 0)
        return "0";
    string temp="";
    string returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0;i<temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}

typedef struct cc
{
	bool v;
	int p;
	char r[10];
} Pattern;

int cmp(const void *va, const void *vb)
{
	cc* a=(cc*)va;
	cc* b=(cc*)vb;
	return a->p-b->p;
}


int main()
{
	ifstream in ("fracdec.in");
	ofstream out ("fracdec.out");
	string Result="";
	int position=0;
	int brack=0;
	bool repeat=false;
	Pattern* P=(Pattern*)malloc(100001*sizeof(Pattern));
	int i;
	int r=0;
	int N, D;
	in>>N>>D;
	r=N/D;
	Result+=convertInt(r);
	Result+=".";
	for (i=0;i<=D;i++)
	{
		P[i].v=false;
		P[i].p=D+1;
		strcpy(P[i].r,"");
	}
	N%=D;
	if (N==0)
	{
		out<<Result<<"0"<<endl;
	}
	else
	{
		while (N!=0)
		{
			if (P[N].v==false)
			{
				P[N].v=true;
				P[N].p=position++;
				N*=10;
				strcpy(P[N/10].r,convertInt(N/D).c_str());
				N%=D;
			}
			else
			{
				brack=P[N].p;
				repeat=true;
				break;
			}
		}
		qsort(P,D,sizeof(cc),cmp);
		for (i=0;i<=D-1;i++)
		{
			if (brack==P[i].p&&repeat)
			{
				Result+="(";
			}
			Result+=P[i].r;
		}
		if (repeat)
		{
			Result+=")";
		}
		for (i=0;i<=Result.length()-1;i++)
		{
			if (i%76==0&&i>1)
				out<<endl;
			out<<Result[i];
		}
		out<<endl;
	}
	return 0;
}