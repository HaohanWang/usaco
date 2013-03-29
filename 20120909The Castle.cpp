/*
ID: haohanw
PROG: castle
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

typedef struct cass
{
	bool visit;
	int com;
	//int i;
	//int j;
	//bool visit2;
	cass* north;
	cass* south;
	cass* east;
	cass* west;
} castle;

castle C[51][51];
int area[2501];
int M, N;
ofstream out ("castle.out");

void West(int i,int j)
{
	C[i][j].west=&C[i][j-1];
}
void East(int i,int j)
{
	C[i][j].east=&C[i][j+1];
}
void South(int i,int j)
{
	C[i][j].south=&C[i+1][j];
}
void North(int i, int j)
{
	C[i][j].north=&C[i-1][j];
}
void travel();
void removewall();

int main()
{
	ifstream in ("castle.in");
	int i, j;
	int m;
	in>>N>>M;
	for (i=1;i<=M;i++)
	{
		for (j=1;j<=N;j++)
		{
			C[i][j].com=0;
			//C[i][j].i=i;
			//C[i][j].j=j;
			C[i][j].visit=0;
			C[i][j].north=NULL;
			C[i][j].south=NULL;
			C[i][j].east=NULL;
			C[i][j].west=NULL;
			//C[i][j].visit2=0;
			in>>m;
			switch (m)
			{
			case 1: North(i,j);
					East(i,j);
					South(i,j);
					break;
			case 2: West(i,j);
					East(i,j);
					South(i,j);
					break;
			case 3: East(i,j);
					South(i,j);
					break;
			case 4: North(i,j);
					South(i,j);
					West(i,j);
					break;
			case 5: North(i,j);
					South(i,j);
					break;
			case 6: South(i,j);
					West(i,j);
					break;
			case 7: South(i,j);
					break;
			case 8: North(i,j);
					East(i,j);
					West(i,j);
					break;
			case 9: North(i,j);
					East(i,j);
					break;
			case 10:East(i,j);
					West(i,j);
					break;
			case 11:East(i,j);
					break;
			case 12:North(i,j);
					West(i,j);
					break;
			case 13:North(i,j);
					break;
			case 14:West(i,j);
					break;
			case 0: West(i,j);
					North(i,j);
					East(i,j);
					South(i,j);
					break;
			default:break;
			}
		}
	}
	//cout<<"0"<<endl;
	travel();
	//cout<<"1"<<endl;
	removewall();
	//system("pause");
	return 0;
}

void travel()
{
	int Compound=1;
	int Area=0;
	int tempMax=0;
	castle * queue[2501];
	int h=0, t=0;
	int i, j;
	bool flag=true;
	while (flag)
	{
		h=0;
		t=0;
		Area=0;
		flag=false;
		for (i=1;i<=M&&!flag;i++)
		{
			for (j=1;j<=N&&!flag;j++)
			{
				if (C[i][j].visit==0)
				{
					flag=true;
				}
			}
		}
		if (flag==true)
		{
		queue[h]=&C[i-1][j-1];
		t=t+1;
		//cout<<"---------"<<endl;
		while(t!=h)
		{
			//cout<<queue[h]->i<<"\t"<<queue[h]->j<<endl;
			if (queue[h]->visit==0)
			{
			queue[h]->com=Compound;
			queue[h]->visit=1;
			Area++;
			if (queue[h]->north!=NULL&&queue[h]->north->visit==0)
			{
				queue[t]=queue[h]->north;
				t++;
			}
			if (queue[h]->south!=NULL&&queue[h]->south->visit==0)
			{
				queue[t]=queue[h]->south;
				t++;
			}
			if (queue[h]->east!=NULL&&queue[h]->east->visit==0)
			{
				queue[t]=queue[h]->east;
				t++;
			}
			if (queue[h]->west!=NULL&&queue[h]->west->visit==0)
			{
				queue[t]=queue[h]->west;
				t++;
			}
			}
			h++;
		}
		area[Compound]=Area;
		if(tempMax<Area)
		{
			tempMax=Area;
		}
		Compound+=1;
		}
	}
	out<<Compound-1<<endl;
	out<<tempMax<<endl;
}

void removewall()
{
	int i, j;
	int minM=M, maxN=N;
	int MaxArea=0;
	int Area;
	bool Door=0;   //0 for E, 1 for N;
	for (i=1;i<=M;i++)
	{
		for (j=1;j<=N;j++)
		{
			//if (C[i][j].visit2==0)
			//{
				//C[i][j].visit2=1;
				if (C[i][j].south==NULL&&i!=M)
				{
					if (C[i][j].com!=C[i+1][j].com)
					{
					//C[i][j+1].visit2=1;
					Area=area[C[i][j].com]+area[C[i+1][j].com];
					if (Area>MaxArea)
					{
						MaxArea=Area;
						minM=j;
						maxN=i+1;
						Door=1;
					}
					if (Area==MaxArea)
					{
						MaxArea=Area;
						if (minM>j)
						{
							minM=j;
							maxN=i+1;
							Door=1;
						}
						else if (minM==j&&maxN<i+1)
						{
							maxN=i+1;
							Door=1;
						}
						else if (minM==j&&maxN==i+1)
						{
							Door=1;
						}
					}
					}
				}
				if (C[i][j].east==NULL&&j!=N)
				{
					if (C[i][j].com!=C[i][j+1].com)
					{
					Area=area[C[i][j].com]+area[C[i][j+1].com];
					if (Area>MaxArea)
					{
						MaxArea=Area;
						minM=j;
						maxN=i;
						Door=0;
					}
					if (Area==MaxArea)
					{
						MaxArea=Area;
						if (minM>j)
						{
							minM=j;
							maxN=i;
							Door=0;
						}
						else if (minM==j&&maxN<i)
						{
							maxN=i;
							Door=0;
						}
					}
					}
				}
			//}
		}
	}
	out<<MaxArea<<endl;
	out<<maxN<<" "<<minM<<" ";
	if (Door)
		out<<"N"<<endl;
	else
		out<<"E"<<endl;
}