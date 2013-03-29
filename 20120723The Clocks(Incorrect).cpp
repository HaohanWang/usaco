/*
ID: haohanw
PROG: clocks
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

typedef struct clocks
{
	int t[9];
}clocks;

int t(int a)
{
	return (a+3)%12;
}

int u(int a)
{
	return (a+9)%12;
}

void Turn(int Clock[],int i)
{
	//cout<<"Turn"<<endl;
	switch(i)
	{
	case 1:	Clock[0]=t(Clock[0]);
			Clock[1]=t(Clock[1]);
			Clock[3]=t(Clock[3]);
			Clock[4]=t(Clock[4]);
			break;
	case 2:	Clock[0]=t(Clock[0]);
			Clock[1]=t(Clock[1]);
			Clock[2]=t(Clock[2]);
			break;
	case 3:	Clock[1]=t(Clock[1]);
			Clock[2]=t(Clock[2]);
			Clock[4]=t(Clock[4]);
			Clock[5]=t(Clock[5]);
			break;
	case 4:	Clock[0]=t(Clock[0]);
			Clock[3]=t(Clock[3]);
			Clock[6]=t(Clock[6]);
			break;
	case 5:	Clock[1]=t(Clock[1]);
			Clock[3]=t(Clock[3]);
			Clock[4]=t(Clock[4]);
			Clock[5]=t(Clock[5]);
			Clock[7]=t(Clock[7]);
			break;
	case 6:	Clock[2]=t(Clock[2]);
			Clock[5]=t(Clock[5]);
			Clock[8]=t(Clock[8]);
			break;
	case 7:	Clock[3]=t(Clock[3]);
			Clock[4]=t(Clock[4]);
			Clock[6]=t(Clock[6]);
			Clock[7]=t(Clock[7]);
			break;
	case 8:	Clock[6]=t(Clock[6]);
			Clock[7]=t(Clock[7]);
			Clock[8]=t(Clock[8]);
			break;
	case 9:	Clock[4]=t(Clock[4]);
			Clock[5]=t(Clock[5]);
			Clock[7]=t(Clock[7]);
			Clock[8]=t(Clock[8]);
			break;
	}
}

void UnTurn(int Clock[],int i)
{
	//cout<<"Turn"<<endl;
	switch(i)
	{
	case 1:	Clock[0]=u(Clock[0]);
			Clock[1]=u(Clock[1]);
			Clock[3]=u(Clock[3]);
			Clock[4]=u(Clock[4]);
			break;
	case 2:	Clock[0]=u(Clock[0]);
			Clock[1]=u(Clock[1]);
			Clock[2]=u(Clock[2]);
			break;
	case 3:	Clock[1]=u(Clock[1]);
			Clock[2]=u(Clock[2]);
			Clock[4]=u(Clock[4]);
			Clock[5]=u(Clock[5]);
			break;
	case 4:	Clock[0]=u(Clock[0]);
			Clock[3]=u(Clock[3]);
			Clock[6]=u(Clock[6]);
			break;
	case 5:	Clock[1]=u(Clock[1]);
			Clock[3]=u(Clock[3]);
			Clock[4]=u(Clock[4]);
			Clock[5]=u(Clock[5]);
			Clock[7]=u(Clock[7]);
			break;
	case 6:	Clock[2]=u(Clock[2]);
			Clock[5]=u(Clock[5]);
			Clock[8]=u(Clock[8]);
			break;
	case 7:	Clock[3]=u(Clock[3]);
			Clock[4]=u(Clock[4]);
			Clock[6]=u(Clock[6]);
			Clock[7]=u(Clock[7]);
			break;
	case 8:	Clock[6]=u(Clock[6]);
			Clock[7]=u(Clock[7]);
			Clock[8]=u(Clock[8]);
			break;
	case 9:	Clock[4]=u(Clock[4]);
			Clock[5]=u(Clock[5]);
			Clock[7]=u(Clock[7]);
			Clock[8]=u(Clock[8]);
			break;
	}
}

bool Check(int Clock[])
{
	//cout<<"Check"<<endl;
	for (int i=0;i<=8;i++)
	{
		if (Clock[i]!=0)
		{
			return false;
		}
	}
	return true;
}

clocks Assign(int Clock[], clocks Clocks)
{
	for (int i=0;i<=8;i++)
	{
		Clocks.t[i]=Clock[i];
	}
	return Clocks;
}

int main()
{
	ifstream fin ("clocks.in");
	ofstream fout ("clocks.out");
	int Clock[9];
	int way[100];
	clocks* Clocks=(clocks*)malloc(100000*sizeof(clocks));
	int count=0;
	int i, j, m;
	for (i=0;i<=8;i++)
	{
		fin>>Clock[i];
		if (Clock[i]==12)
		{
			Clock[i]=0;
		}
	}
	count=0;
	while (count<=100000000000)
	{
		//cout<<count<<endl;
		i=0;
		m=count;
		if (count<=99999)
		{
			while (m>=10)
			{
				way[i]=m%10;
				m/=10;
				i++;
			}
			way[i]=m;
			for (j=i;j>=0;j--)
			{
				Turn(Clock,way[j]);
			}
			if (Check(Clock))
			{
				fout<<way[i];
				for (j=i-1;j>=0;j--)
				{
					fout<<" "<<way[j];
				}
				fout<<endl;
				return 0;
			}
			else
			{
				Clocks[count]=Assign(Clock,Clocks[count]);
				for (j=i;j>=0;j--)
				{
					UnTurn(Clock,way[j]);
				}
			}
			count++;
		}
		else
		{
			while (m>=10)
			{
				way[i]=m%10;
				m/=10;
				i++;
			}
			way[i]=m;
			for (j=i;j>=5;j--)
			{
				Turn(Clocks[count%100000].t,way[j]);
			}
			if (Check(Clocks[count%100000].t))
			{
				fout<<way[i];
				for (j=i-1;j>=0;j--)
				{
					fout<<" "<<way[j];
				}
				fout<<endl;
				return 0;
			}
			else
			{
				//Clocks[count]=Assign(Clocks[count%100000].t,Clocks[count]);
				for (j=i;j>=5;j--)
				{
					UnTurn(Clocks[count%100000].t,way[j]);
				}
			}
			count+=1;
		}
	}
	return 0;
}