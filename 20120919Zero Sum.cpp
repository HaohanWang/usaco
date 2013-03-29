/*
ID: haohanw1
PROG: zerosum
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int N;
int M[10]={0};
bool DONE=false;
ofstream out ("zerosum.out");

void AdjustM(int);
void Output();

int main()
{
	ifstream in ("zerosum.in");
	in>>N;
	M[N]=1;
	int sum=0;
	int digit[10]={0};
	int i;
	while (!DONE)
	{
		for (i=1;i<=N;i++)
		{
			digit[i]=i;
		}
		sum=0;
		for (i=1;i<=N-1;i++)
		{
			if (M[i+1]==0)
			{
				digit[i+1]=digit[i]*10+digit[i+1];
			}
		}
		for (i=N;i>=2;i--)
		{
			if (M[i]==0)
			{
				digit[i-1]=digit[i];
			}
			else if (M[i]==1)
			{
				sum+=digit[i];
			}
			else
			{
				sum-=digit[i];
			}
		}
		sum+=digit[1];
		if (sum==0)
		{
			Output();
		}
		AdjustM(N);
	}
}

void AdjustM(int n)
{
	if (n==1)
		DONE=true;
	else
	{
		if (M[n]==0)
		{
			M[n]=1;
		}
		else if (M[n]==1)
		{
			M[n]=2;
		}
		else
		{
			M[n]=0;
			AdjustM(n-1);
		}
	}
}

void Output()
{
	out<<"1";
	int i;
	for (i=2;i<=N;i++)
	{
		if (M[i]==0)
		{
			out<<" ";
		}
		else if (M[i]==1)
		{
			out<<"+";
		}
		else
		{
			out<<"-";
		}
		out<<i;
	}
	out<<endl;
}