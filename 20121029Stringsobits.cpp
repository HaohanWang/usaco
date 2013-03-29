/*
ID: haohanw1
PROG: kimbits
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

long Growth(long t, long e);
long C(long, long);

int main()
{
	ifstream in ("kimbits.in");
	ofstream out ("kimbits.out");
	long long N, L, I;
	in>>N>>L>>I;
	long i, k;
	long r[32]={0};
	I=I-1;
	long n=N;
	long g=0;
	long consume=0;
	for (i=32-N;i<=31;i++)
	{
		g=Growth(n,L-consume);
		cout<<n<<" "<<g<<" "<<I<<endl;
		if (g<I)
		{
			cout<<"in: "<<n<<" "<<g<<" "<<I<<endl;
			n--;
			r[i]=1;
			consume++;
			I=I-g;
		}
		else if (g==I)
		{
			cout<<"final: "<<n<<" "<<g<<" "<<I<<endl;
			r[i]=1;
			break;
		}
		else
		{
			n--;
		}
	}
	for (i=32-N;i<=31;i++)
	{
		out<<r[i];
	}
	out<<endl;
	//system("pause");
	return 0;
}

long Growth(long t, long e)
{
	int r=0;
	int i=0;
	if (t<=e)
	{
		return pow((double)2,t-1);
	}
	else
	{
		for (i=0;i<=t-1-(e+1);i++)
		{
			r+=C(i,t-1);
		}
		return pow((double)2,t-1)-r;
	}
}

long C(long m, long n)
{
	long long de=1, nu=1;
	if (m==8&&n==20)
		m=8;
	if (m==0)
		return 1;
	else
	{
		for (int i=1;i<=m;i++)
		{
			de*=i;
			nu*=(n-i+1);
		}
		cout<<"\t"<<m<<" "<<n<<" "<<nu/de<<endl;
		return nu/de;
	}
}