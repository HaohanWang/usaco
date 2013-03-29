/*
ID: haohanw1
PROG: ratios
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

bool Judge(int *a, int* b)
{
	int i;
	bool c[3]={false};
	int count=0;
	for (i=0;i<=2;i++)
	{
		if ((a[i]==0&&b[i]!=0)||(a[i]!=0&&b[i]==0))
			return false;
		else if (a[i]==0&&b[i]==0)
		{
			c[i]=true;
		}
	}
	for (i=0;i<=2;i++)
	{
		if (c[i]==true)
			count++;
	}
	if (count>=2)
		return true;
	for (i=0;i<=2;i++)
	{
		if (c[i]==false)
		{
			if (a[i]%b[i]!=0)
				return false;
		}
	}
	int result=0;
	for (i=0;i<=2;i++)
	{
		if (c[i]==false)
		{
			result=a[i]/b[i];
			break;
		}
	}
	for (i=0;i<=2;i++)
	{
		if (c[i]==false)
		{
			if (result!=a[i]/b[i])
				return false;
		}
	}
	return true;
}

int main()
{
	ifstream in ("ratios.in");
	ofstream out ("ratios.out");

	int g[3];
	int m[3][3];
	int goal, i, j;
	int r[3];
	int min=500;
	int tg[3];
	int re[3];
	for (i=0;i<=2;i++)
		in>>g[i];
	for (i=0;i<=2;i++)
	{
		for (j=0;j<=2;j++)
		{
			in>>m[i][j];
		}
	}
	for (r[0]=0;r[0]<=100;r[0]++)
	{
		for (r[1]=0;r[1]<=100;r[1]++)
		{
			for (r[2]=0;r[2]<=100;r[2]++)
			{
				for (i=0;i<=2;i++)
					tg[i]=0;
				for (i=0;i<=2;i++)
				{
					for (j=0;j<=2;j++)
					{
						tg[i]+=r[j]*m[j][i];
					}
				}
				if (Judge(tg,g))
				{
					if (min>r[0]+r[1]+r[2]&&(r[0]+r[1]+r[2])!=0)
					{
						goal=tg[1]/g[1];
						min=r[0]+r[1]+r[2];
						re[0]=r[0];
						re[1]=r[1];
						re[2]=r[2];
					}
				}
			}
		}
	}
	if (min!=500)
		out<<re[0]<<" "<<re[1]<<" "<<re[2]<<" "<<goal<<endl;
	else
		out<<"NONE"<<endl;
	return 0;
}