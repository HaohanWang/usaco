/*
ID: haohanw
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

bool DualPalindrome(int);

int main()
{
	ifstream fin ("dualpal.in");
	ofstream fout ("dualpal.out");

	int N, S, i, j, count=0;
	fin>>N>>S;
	
	i=S;
	while(1)
	{
		i+=1;
		//cout<<endl<<i;
		if(DualPalindrome(i))
		{
			fout<<i<<endl;
			count+=1;
		}
		/*else
		{
			count=0;
		}*/
		if (count==N)
		{
			/*for (j=i-N+1;j<=i;j++)
			{
				fout<<j<<endl;
			}*/
			break;
		}
	}
	//system("pause");
	return 0;
}

bool DualPalindrome(int num)
{
	int CountFlag=0;
	bool Flag=false;
	int p[32];
	int i,j, N,count=0;
	
	for (j=2;j<=10;j++)
	{
		for (i=0;i<=31;i++)
		{
			p[i]=0;
		}
		N=num;
		Flag=true;
		for (i=0;N>=j&&i<=31;i++)
		{
			p[i]=N%j;
			N=N/j;
			//count++;
		}
		if (N<j&&N!=0)
		{
			p[i]=N;
			//count++;
		}
		for (count=0;count<=i/2;count++)
		{
			if (p[count]!=p[i-count])
			{
				Flag=false;
				break;
			}
		}
		if (Flag==true)
		{
			//cout<<"\t"<<j;
			CountFlag++;
			if (CountFlag==2)
			{
				return true;
			}
		}
	}
	return false;
}