/*
ID: haohanw
PROG: sort3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
	ifstream in ("sort3.in");
	ofstream out ("sort3.out");

	int O[1000]={0};
	int G[1000]={0};
	int change[6]={0};
	int s1=0;
	int s2=0;
	int N;
	in>>N;
	int i, j, a=0, b=0, c=0;
	for (i=0;i<=N-1;i++)
	{
		in>>O[i];
		switch(O[i])
		{
		case 1:
			a++;
			break;
		case 2:
			b++;
			break;
		case 3:
			c++;
			break;
		}
	}
	j=-1;
	for (i=1;i<=a;i++)
	{
		G[i+j]=1;
	}
	j=a-1;
	for (i=1;i<=b;i++)
	{
		G[i+j]=2;
	}
	j=a+b-1;
	for (i=1;i<=c;i++)
	{
		G[i+j]=3;
	}
	for (i=0;i<=N-1;i++)
	{
		if (O[i]==G[i])
		{
		}
		else if (O[i]==1&&G[i]==2)
		{
			change[0]+=1;
		}
		else if (O[i]==1&&G[i]==3)
		{
			change[1]+=1;
		}
		else if (O[i]==2&&G[i]==3)
		{
			change[2]+=1;
		}
		else if (O[i]==2&&G[i]==1)
		{
			change[3]+=1;
		}
		else if (O[i]==3&&G[i]==1)
		{
			change[4]+=1;
		}
		else if (O[i]==3&&G[i]==2)
		{
			change[5]+=1;
		}
	}
	for (i=0;i<=2;i++)
	{
		s1+=min(change[i],change[i+3]);
		s2+=fabs((double)change[i]-change[i+3]);
	}
	s1+=s2*2/3;
	out<<s1<<endl;
	return 0;
}