/*
ID: haohanw1
PROG: maze1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int W, H;
int M(int, int);


int main()
{
	ifstream in ("maze1.in");
	ofstream out ("maze1.out");
	FILE *stream=fopen("maze1.in","r");
	char Map[201][77];
	in>>W>>H;
	int i, j, k;
	int count=0;
	int e[2];
	string str;
	char str1[38]={};
	int tM=0;
	int ** R=(int**)malloc(3800*sizeof(int*));
	for (i=1;i<=3800;i++)   //数组过大
	{
		R[i]=(int*)malloc(3800*sizeof(int));
		for (j=1;j<=3800;j++)
		{
			//R[i][j]=(int)malloc(sizeof(int));
			R[i][j]=0;
		}
	}
	for (i=0;i<=200;i++)
	{
		for (j=0;j<=76;j++)
		{
			Map[i][j]=' ';
		}
	}
	fgets(str1,5,stream);
	for (i=0;i<=H*2;i++)
	{
		//getline(in, str, '\n');
		fgets(str1,2*W+3,stream);
		for (j=0;j<=W*2;j++)
		{
			Map[i][j]=str1[j];
		}
	}
	for (i=1;i<=2*H-1;i+=2)
	{
		for (j=1;j<=2*W-1;j+=2)
		{
			if (Map[i-1][j]==' ')
			{
				if (i-1==0)
				{
					e[count]=M(i,j);
					count++;
				}
				else
				{
					R[M(i,j)][M(i-2,j)]=1;
				}
			}
			if (Map[i+1][j]==' ')
			{
				if (i+1==2*H)
				{
					e[count]=M(i,j);
					count++;
				}
				else
				{
					R[M(i,j)][M(i+2,j)]=1;
				}
			}
			if (Map[i][j-1]=' ')
			{
				if (j-1==0)
				{
					e[count]=M(i,j);
					count++;
				}
				else
				{
					R[M(i,j)][M(i,j-2)]=1;
				}
			}
			if (Map[i][j+1]=' ')
			{
				if (j+1==2*W)
				{
					e[count]=M(i,j);
					count++;
				}
				else
				{
					R[M(i,j)][M(i,j+2)]=1;
				}
			}
		}
	}
	for (k=0;k<=H*W-1;k++)
	{
		for (i=0;i<=H*W-1;i++)
		{
			for (j=0;j<=H*W-1;j++)
			{
				if (R[i][k]+R[k][j]<=R[i][j])
				{
					R[i][j]=R[i][k]+R[k][j];
				}
			}
		}
	}
	for (count=0;count<=1;count++)
	{
		for (i=0;i<=H*W-1;i++)
		{
			if(R[e[count]][i]>tM)
			{
				tM=R[e[count]][i];
			}
		}
	}
	out<<tM<<endl;
	return 0;
}

int M(int i, int j)
{
	return i/2*W+j/2;
}