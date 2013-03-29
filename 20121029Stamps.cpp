/*
ID: haohanw1
PROG: stamps
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in ("stamps.in");
	ofstream out ("stamps.out");

	int K, N;
	int * r=(int*) malloc(2000001*sizeof(int));
	int i=0,j=0;
	for (i=0;i<=2000001;i++)
	{
		r[i]=0;
	}
	int s[50];
	in>>K>>N;
	for (;N>=1;N--)
	{
		in>>i;
		r[i]=1;
		s[j++]=i;
	}
	int number=j-1;
	int min;
	int result;
	for (i=1;i<=2000001;i++)
	{
		min=K+1;
		if (r[i]!=1)
		{
			for (j=0;j<=number;j++)
			{
				if (i-s[j]>0)
				{
					if (1+r[i-s[j]]<min)
					{
						min=r[i-s[j]]+1;
					}
				}
			}
			r[i]=min;
		}
		if (r[i]>K)
		{
			result=i-1;
			break;
		}
	}
	out<<result<<endl;
	return 0;
}