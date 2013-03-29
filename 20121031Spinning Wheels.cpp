/*
ID: haohanw1
PROG: spin
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in ("spin.in");
	ofstream out ("spin.out");
	int S[5];
	int W[5][360];
	int B=0;
	int index[5]={0};
	int time=0;
	int i, j, k, span, start;
	for (i=0;i<=4;i++)
	{
		for (j=0;j<=359;j++)
		{
			W[i][j]=0;
		}
	}
	for (i=0;i<=4;i++)
	{
		in>>S[i];
		in>>k;
		for (;k>=1;k--)
		{
			in>>start>>span;
			for (j=0;j<=span;j++)
			{
				W[i][(start+j)%360]=1;
			}
		}
	}
	int total=20000;
	/*
	for (i=0;i<=4;i++)
	{
		total*=(360/S[i])+1;
	}*/
	bool find=false;
	while (time<360&&!find)
	{
		B=0;
		//cout<<"--------"<<endl;
		for (i=0;i<=359;i++)
		{
			B=0;
			for (j=0;j<=4;j++)
			{
				B+=W[j][(i+index[j])%360];
			}
			if (B==5)
			{
				out<<time<<endl;
				find=true;
				break;
			}
		}
		time++;
		for (i=0;i<=4;i++)
		{
			index[i]=(index[i]-S[i]+360)%360;
		}
	}
	if (time==360)
	{
		out<<"none"<<endl;
	}
	//system("pause");
	return 0;
}