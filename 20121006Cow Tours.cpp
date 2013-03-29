/*
ID: haohanw
PROG: cowtour
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	ifstream in ("cowtour.in");
	ofstream out ("cowtour.out");

	int N;
	double P[150][4];
	double M[150][150];
	in>>N;
	int i, j, k, n, t;
	int group=1;
	//bool finish=false;
	char read[160]="";
	double MaxD[150]={0};
	int queue[160];
	int head;
	int tail;
	for (i=0;i<=N-1;i++)
	{
		in>>P[i][1]>>P[i][2];
		P[i][0]=0;
		P[i][3]=0;
	}
	for (i=0;i<=N-1;i++)
	{
		in>>read;
		for (j=0;j<=N-1;j++)
		{
			M[i][j]=read[j]-'0';
		}
	}
	for (i=0;i<=N-1;i++)
	{
		for (j=0;j<=N-1;j++)
		{
			if (M[i][j]==1)
			{
				M[i][j]=sqrt(double((P[i][1]-P[j][1])*(P[i][1]-P[j][1])+(P[i][2]-P[j][2])*(P[i][2]-P[j][2])));
			}
		}
	}
	for (t=0;t<=N-1;t++)
	{
		for (i=0;i<=N-1;i++)
		{
			for (j=0;j<=N-1;j++)
			{
				if (M[i][t]!=0&&M[t][j]!=0&&j!=i)
				{
					if ((M[i][j]==0)||(M[i][j]>M[i][t]+M[t][j]))
					{
						M[i][j]=M[i][t]+M[t][j];
					}
				}
			}
		}
	}
	for (k=0;k<=N-1;k++)
	{
		if (P[k][0]==0)
		{
			P[k][0]=group;
			//finish=false;
			queue[0]=k;
			head=0;
			tail=1;
			while (head!=tail)
			{
				n=queue[head];
				head++;
				for (i=n;i<=N-1;i++)
				{
					if (M[n][i]!=0&&P[i][0]==0)
					{
						queue[tail]=i;
						P[i][0]=group;
						tail++;
					}
				}
			}
			group++;
		}
	}
	for (i=0;i<=N-1;i++)
	{
		for (j=0;j<=N-1;j++)
		{
			if (M[i][j]>P[i][3])
			{
				P[i][3]=M[i][j];
				MaxD[(int)P[i][0]]=max(P[i][3],MaxD[(int)P[i][0]]);
			}
		}
	}
	//int g1, g2;
	double temp1=0;
	double temp2=999999;
	//double M1[150][150];
	for (k=0;k<=N-1;k++)
	{
		for (n=k+1;n<=N-1;n++)
		{
			//if (k==2&&n==6)
			//	k=2;
			if (P[k][0]!=P[n][0])
			{
				//temp1=0;
				/*g1=P[k][0];
				g2=P[n][0];
				for (i=0;i<=N-1;i++)
				{
					for (j=0;j<=N-1;j++)
					{
						M1[i][j]=M[i][j];
					}
				}
				M1[k][n]=sqrt(double((P[k][1]-P[n][1])*(P[k][1]-P[n][1])+(P[k][2]-P[n][2])*(P[k][2]-P[n][2])));
				for (t=0;t<=N-1;t++)
				{
					for (i=0;i<=N-1;i++)
					{
						for (j=0;j<=N-1;j++)
						{
							if (M1[i][t]!=0&&M1[t][j]!=0)
							{
							if ((M1[i][j]==0)||(M1[i][j]>M1[i][t]+M1[t][j]))
							{
								M1[i][j]=M1[i][t]+M1[t][j];
							}
							}
						}
					}
				}*/
				//for (i=0;i<=N-1;i++)
				//{
				//	for (j=0;j<=N-1;j++)
				//	{
				//		if ((P[i][0]==g1&&P[j][0]==g2)||(P[i][0]==g2&&P[j][0]==g1)||(P[i][0]==g1&&P[j][0]==g1)||(P[i][0]==g2&&P[j][0]==g2))
				//		{
				//		if(temp1<M1[i][j]&&M1[i][j]!=0)
				//		{
				//			temp1=M1[i][j];
				//			//cout<<i<<" "<<j<<" "<<temp1<<"--"<<k<<" "<<n<<endl;
				//		}
				//		}
				//	}
				//}
				//M[k][n]=0;
				/*if (temp1<P[k][3]+P[n][3]+sqrt(double((P[k][1]-P[n][1])*(P[k][1]-P[n][1])+(P[k][2]-P[n][2])*(P[k][2]-P[n][2]))))
				{
					temp1=P[k][3]+P[n][3]+sqrt(double((P[k][1]-P[n][1])*(P[k][1]-P[n][1])+(P[k][2]-P[n][2])*(P[k][2]-P[n][2])));
					cout<<temp1<<"\t"<<k<<"\t"<<n<<endl;
				}*/
				temp2=min(temp2,P[k][3]+P[n][3]+sqrt(double((P[k][1]-P[n][1])*(P[k][1]-P[n][1])+(P[k][2]-P[n][2])*(P[k][2]-P[n][2]))));
				if (temp2<MaxD[(int)P[k][0]])
				{
					temp2=MaxD[(int)P[k][0]];
				}
				if (temp2<MaxD[(int)P[n][0]])
				{
					temp2=MaxD[(int)P[n][0]];
				}
			}
			/*if (k%10==0&&n%10==0)
				cout<<k<<" "<<n<<endl;*/
			/*if (temp2>temp1&&temp1!=0)
				temp2=temp1;*/
		}
	}
	out<<setiosflags(ios::fixed);
	out<<setprecision(6)<<temp2<<endl;
	//system("pause");
	return 0;
}