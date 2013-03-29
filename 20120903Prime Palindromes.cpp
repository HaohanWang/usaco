/*
ID: haohanw
PROG: pprime
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

bool Palindrome(int);
bool Prime(int);

int main()
{
	ifstream in("pprime.in");
	ofstream out("pprime.out");

	int a, b;
	in>>a>>b;
	if (a%2==0)
		a+=1;
	int i;
	int jump=10;
	int count=0;
	int c=a;
	while (c>=10)
	{
		c/=10;
		jump*=10;
	}
	for (i=a;i<=b;i+=2)
	{
		//cout<<i<<endl;
		if (Palindrome(i))
		{
			if (Prime(i))
			{
				out<<i<<endl;
			}
		}
		if (i%jump==1)
		{
			count+=1;
		}
		if (count==1)
		{
			if (i==1001)
			{
				i=10001;
				jump*=10;
			}
			else if (i==100001)
			{
				i=1000001;
				jump*=10;
			}
			else if (i==10000001)
			{
				i=100000001;
			}
		}
		else if	(count==2||count==6||count==8)
		{
			i+=jump;
			i-=2;
		}
		else if(count==4)
		{
			i+=3*jump;
			count+=2;
			i-=2;
		}
		else if (count==9)
		{
			count=0;
			jump*=10;
		}
	}
	return 0;
}

bool Palindrome(int a)
{
	if (a==100000000)
		return false;
	else
	{
		int i=0, j=0;
		int d[8];
		while (a>=10)
		{
			d[i]=a%10;
			a/=10;
			i++;
		}
		d[i]=a;
		for (j=0;j<=i/2;j++)
		{
			if (d[j]!=d[i-j])
			{
				return false;
			}
		}
		return true;
	}
}

bool Prime(int a)
{
	int i=(int)sqrt((double)a);

	int j=3;
	for (;j<=i;j+=2)
	{
		if (a%j==0)
			return false;
	}
	return true;
}