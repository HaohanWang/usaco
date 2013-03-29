/*
ID: haohanw
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin ("milk2.in");
    ofstream fout ("milk2.out");

	int N, i;
	int Start=0, End=0, Unmilk=0, tempUn=0, Milk=0, tempM=0,counter=0, minus=-1;
	int Farmer[5000][2];
	int *time=(int *)malloc(1000000*sizeof(int));//大数组的方法
	for (i=0;i<=1000000-1;i++)
	{
		time[i]=0;
	}
	fin>>N;
	for (i=0;i<=N-1;i++)
	{
		fin>>Farmer[i][0]>>Farmer[i][1];
	}

	Start=Farmer[0][0];
	for (i=0;i<=N-1;i++)
	{
		time[Farmer[i][0]]+=1;                //比较好的记录开始和结束的方法
		time[Farmer[i][1]]-=1;
		
		if (Start>Farmer[i][0])
			Start=Farmer[i][0];
		if (End<Farmer[i][1])
			End=Farmer[i][1];
	}

	for (i=Start;i<=End;i++)
	{
		counter+=time[i];
		if (counter!=0)
		{
			tempM+=1;
			if (tempUn>Unmilk)
				Unmilk=tempUn;
			tempUn=0;
		}
		else
		{
			tempUn+=1;
			if (tempM>Milk)
				Milk=tempM;
			tempM=0;
		}
		
	}

	fout<<Milk<<" "<<Unmilk<<endl;
	return 0;
}
