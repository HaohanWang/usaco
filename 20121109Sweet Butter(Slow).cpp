/*
ID: haohanw1
PROG: butter
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in ("butter.in");
	ofstream out ("butter.out");
	int N, P, C;
	//int Pasture[801][801];
	int ** Pasture;
	Pasture=(int **)malloc(801*sizeof(int *));
	for(int i=0;i<=800;i++)
		Pasture[i]=(int *)malloc(sizeof(*Pasture)*801);
	int Cow [801]={0};
	in>>N>>P>>C;
	int i, j, k;
	int a, b, c;
	int length;
	int min=1000000;
	int minI=0;
	for (i=0;i<=800;i++)
	{
		for (j=0;j<=800;j++)
		{
			Pasture[i][j]=0;
		}
	}
	for (i=1;i<=N;i++)
	{
		in>>j;
		Cow[j]+=1;
	}
	for (i=1;i<=C;i++)
	{
		in>>a>>b>>c;
		Pasture[a][b]=c;
		Pasture[b][a]=c;
	}
	/*for (i=1;i<=P;i++)
	{
		for (j=1;j<=P;j++)
		{
			out<<Pasture[i][j]<<"\t"; 
		}
		out<<endl;
	}
	out<<"----------------"<<endl;*/
	for (k=1;k<=P;k++)
	{
		for (i=1;i<=P;i++)
		{
			for (j=1;j<=P;j++)
			{
				if (Pasture[i][k]+Pasture[k][j]<=Pasture[i][j]&&Pasture[i][k]!=0&&Pasture[k][j]!=0)
				{
					Pasture[i][j]=Pasture[i][k]+Pasture[k][j];
				}
				else if (Pasture[i][j]==0&&Pasture[i][k]!=0&&Pasture[k][j]!=0&&i!=j)
				{
					Pasture[i][j]=Pasture[i][k]+Pasture[k][j];
				}
			}
		}
	}
	/*for (i=1;i<=P;i++)
	{
		for (j=1;j<=P;j++)
		{
			out<<Pasture[i][j]<<"\t"; 
		}
		out<<endl;
	}*/
	for (i=1;i<=P;i++)
	{
		length=0;
		for (j=1;j<=P;j++)
		{
			if (Cow[j]!=0)
			{
				length+=Pasture[j][i]*Cow[j];
				if (Pasture[j][i]==0&&i!=j)
				{
					length+=min;
					break;
				}
				//cout<<i<<" "<<j<<" "<<Pasture[j][i]<<endl;
			}
		}
		if (length<min)
		{
			min=length;
			minI=i;
		}
	}
	/*cout<<min<<endl;
	cout<<minI<<endl;*/
	out<<min<<endl;
	//system("pause");
	return 0;
}