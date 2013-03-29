/*
ID: haohanw
PROG: palsquare
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");

	int base, S, count, i, num=1, NUM;
	char p[100000];
	char n[10];
	int N[10];
	bool palindrome=true;
	int *Square=(int *)malloc(100000*sizeof(int));
	fin>>base;
	for (i=0;i<=99999;i++)
	{
		Square[i]=0;
	}

	while (num<=300)
	{
		palindrome=true;
		S=num*num;
		count=0;
		for (count=0;S>=base&&count<=99999;count++)
		{
			Square[count]=S%base;
			S=S/base;
		}
		if (S!=0)
		{
			//count++;
			Square[count]=S%base;
		}
		for (i=0;i<=count/2;i++)
		{
			if (Square[i]!=Square[count-i])
			{
				palindrome=false;
				break;
			}
		}
		if (palindrome)
		{
			for (i=count;i>=0;i--)
			{
				if (Square[i]<=9)
				{
					p[count-i]=Square[i]+'0';
				}
				else
				{
					p[count-i]=Square[i]-10+'A';
				}
			}
			p[count+1]='\0';
			NUM=num;
			for (count=0;NUM>=base&&count<=10;count++)
			{
				N[count]=NUM%base;
				NUM=NUM/base;
			}
			if (NUM!=0)
			{
				N[count]=NUM%base;
			}
			for (i=count;i>=0;i--)
			{
				if (N[i]<=9)
				{
					n[count-i]=N[i]+'0';
				}
				else
				{
					n[count-i]=N[i]-10+'A';
				}
			}
			n[count+1]='\0';
			fout<<n<<" "<<p<<endl;
		}
		num++;
		//cout<<num<<endl;
	}
	return 0;
}