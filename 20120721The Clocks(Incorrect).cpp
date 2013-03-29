/*
ID: haohanw
PROG: clocks
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int way[10];
int index=0;

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

bool TurnClock(int Clock[], int count)
{
	//cout<<"TC"<<endl;
	int tIndex=index;
	int i;
	if (count==0)
	{
		for (i=1;i<=9;i++)
		{
			Turn(Clock, i);
			way[index]=i;
			if (Check(Clock))
			{
				return true;
			}
			else
			{
				UnTurn(Clock,i);
			}
		}
		return false;
	}
	else
	{
		for (i=1;i<=9;i++)
		{
			Turn(Clock, i);
			way[index]=i;
			index++;
			if(TurnClock(Clock,count-1))
			{
				return true;
			}
			else
			{
				index--;
				UnTurn(Clock,i);
			}
		}
		return false;
	}
}

int main()
{
	ifstream fin ("clocks.in");
	ofstream fout ("clocks.out");
	int Clock[9];
	int count=0;
	int i, j;
	for (i=0;i<=8;i++)
	{
		fin>>Clock[i];
		if (Clock[i]==12)
		{
			Clock[i]=0;
		}
	}
	while(1)
	{
		if (TurnClock(Clock, count))
		{
			fout<<way[0];
			for (j=1;j<=index;j++)
			{
				fout<<" "<<way[j];
			}
			fout<<endl;
			return 0;
		}
		//cout<<count<<endl;
		count+=1;
	}
}