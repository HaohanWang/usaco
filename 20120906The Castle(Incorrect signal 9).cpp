/*
ID: haohanw
PROG: castle
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int M=0, N=0;
int C[2501][2501]={0};
int Com[2501]={0};
int Weight[2501]={0};
ofstream out("castle.out");

void West(int m)
{
	if (m-1>=0)
	{
		C[m][m-1]=1;
		C[m-1][m]=1;
	}
}

void East(int m)
{
	C[m][m+1]=1;
	C[m+1][m]=1;
}

void South(int m)
{
	C[m][m+M]=1;
	C[m+M][m]=1;
}

void North(int m)
{
	if (m>=M)
	{
		C[m][m-M]=1;
		C[m-M][m]=1;
	}
}

void FindConnected();
void RemoveWall();
bool Adjacent(int, int);

int main()
{
	//cout<<"1"<<endl;
	ifstream in ("castle.in");
	
	in>>M>>N;
	
	int i=0;
	int w=0;
	int m=0;
	//cout<<"go"<<endl;
	for (i=1;i<=M*N;i++)
	{
		in>>w;
		m=i;
		switch (w)
		{
		case 1: North(m);
				East(m);
				South(m);
				break;
		case 2: West(m);
				East(m);
				South(m);
				break;
		case 3: East(m);
				South(m);
				break;
		case 4: North(m);
				South(m);
				West(m);
				break;
		case 5: North(m);
				South(m);
				break;
		case 6: South(m);
				West(m);
				break;
		case 7: South(m);
				break;
		case 8: North(m);
				East(m);
				West(m);
				break;
		case 9: North(m);
				East(m);
				break;
		case 10:East(m);
				West(m);
				break;
		case 11:East(m);
				break;
		case 12:North(m);
				West(m);
				break;
		case 13:North(m);
				break;
		case 14:West(m);
				break;
		case 0: West(m);
				North(m);
				East(m);
				South(m);
				break;
		default:break;
		}
	}
	//cout<<"1"<<endl;
	FindConnected();
	//cout<<"2"<<endl;
	RemoveWall();
	//system("pause");
	return 0;
}

void FindConnected(void)
{
	int visited=0;
	//int V[2501]={0};
	int count=0;
	int tempmax=0;
	bool flag=true;
	bool Goon=false;
	int i=0, j=0;
	do
	{
		Goon=false;
		flag=true;
		for (j=1;j<=M*N;j++)
		{
			if (Com[j]==-2)
			{
				flag=false;
				Goon=true;
				break;
			}
		}
		if (flag)
		{
			for (j=1;j<=M*N;j++)
			{
				if (Com[j]==0)
				{
					count+=1;
					Com[j]=-2;
					visited=0;
					Goon=true;
					break;
				}
			}
		}
		for (i=1;i<=M*N;i++)
		{
			if (Com[i]==-2)
			{
				Com[i]=count;
				visited+=1;
				for (j=1;j<=M*N;j++)
				{
					if (C[i][j]==1)
					{
						if (Com[j]==0)
						{
							Com[j]=-2;
						}
						//Com[j]=count;
						//visited+=1;
					}
				}
			}
		}
		for (int a=1;a<=M*N;a++)
		{
			if (Com[a]==count)
			{
				Weight[a]=visited;
			}
		}
		if (tempmax<visited)
			tempmax=visited;
	} while (Goon);
	out<<count<<endl;
	out<<tempmax<<endl;
}

void RemoveWall(void)
{
	int i=0, j=0;
	int Max=0;
	int a=0;
	int Modulm=M;
	int Moduln=N;
	int Wall=-1;   //0 for north 1 for east
	int tempwall=-1;
	for (i=1;i<=M*N;i++)
	{
		for (j=i+1;j<=M*N;j++)
		{
			if (Com[i]!=Com[j]&&Adjacent(i,j))
			{
				if (Max<=Weight[i]+Weight[j])
				{
					Max=Weight[i]+Weight[j];
					if (i==j-1)
					{
						a=i;
						tempwall=1;
					}
					else
					{
						a=j;
						tempwall=0;
					}
					if (Modulm>(a%M))
					{
						Modulm=a%M;
						Moduln=a/M+1;
						Wall=tempwall;
					}
					else if (Modulm==(a%M)&&Moduln<(a/M+1))
					{
						Moduln=(a/M+1);
						Wall=tempwall;
					}
					else if (Wall==1&&tempwall==0)
					{
						Wall=0;
					}
				}
			}
		}
	}
	out<<Max<<endl;
	out<<Moduln<<" "<<Modulm<<" ";
	if (Wall==0)
	{
		out<<"N"<<endl;
	}
	else
	{
		out<<"E"<<endl;
	}
}

bool Adjacent(int i, int j)
{
	if (j/M==(i/M+1)&&j%M==i%M)
	{
		return true;
	}
	else if (j%M!=1)
	{
		if (i==j-1)
		{
			return true;
		}
		else
			return false;
	}
	else
	{
		return false;
	}
	
}
