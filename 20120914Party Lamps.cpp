/*
ID: haohanw1
PROG: lamps
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int Lamps[100]={0};
int FLamps[100];
int N;

typedef struct cc
{
	int l[100];
} lamp;

lamp Result[10000];
int index=0;
ofstream out ("lamps.out");

int cmp(const void *va, const void *vb)
{
	lamp *a;
	lamp *b;
	a=(lamp*)va;
	b=(lamp*)vb;
	for (int i=0;i<=N-1;i++)
	{
		if (a->l[i]>b->l[i])
		{
			return 1;
		}
		else if (a->l[i]<b->l[i])
		{
			return -1;
		}
	}
	return 0;
}

void TurnLight(int);
bool CompareLight();
void Turn(int);
void Add();
void OutPut();
bool Exist();

int main()
{
	ifstream in ("lamps.in");
	int C;
	in>>N;
	in>>C;
	int i, d;
	for (i=0;i<=N-1;i++)
	{
		Lamps[i]=1;
		FLamps[i]=-1;
	}
	int state;
	in>>state;
	while (state!=-1)
	{
		FLamps[state-1]=1;
		in>>state;
	}
	in>>state;
	while (state!=-1)
	{
		FLamps[state-1]=0;
		in>>state;
	}
	if (C<=2&&C>=1)
	{
		TurnLight(C);
		OutPut();
	}
	else if (C==0)
	{
		if (CompareLight())
		{
			for (i=0;i<=N-1;i++)
			{
				out<<Lamps[i];
			}
			out<<endl;
		}
		else
		{
			out<<"IMPOSSIBLE"<<endl;
		}
	}
	else if (C%2==0)
	{
		d=C%3;
		if (d!=0)
		{
			TurnLight(d);
		}
		TurnLight(0);
		TurnLight(2);
		TurnLight(4);
		OutPut();
	}
	else
	{
		d=C%3;
		if (d!=0)
		{
			TurnLight(d);
		}
		TurnLight(1);
		TurnLight(3);
		OutPut();
	}
	return 0;
}

void TurnLight(int C)
{
	//cout<<"tl"<<endl;
	Turn(0);
	if (C==0)
	{
		if (CompareLight())
		{
			Add();
		}
	}
	else if (C==4)
	{
		Turn(1);
		Turn(2);
		Turn(3);
		Turn(4);
		if (CompareLight())
		{
			Add();
		}
	}
	else
	{
		int i1, i2, i3;
		for (i1=1;i1<=4;i1++)
		{
			Turn(i1);
			if (C==1)
			{
				if (CompareLight())
				{
					Add();
				}
			}
			else
			{
				for (i2=1;i2<=4;i2++)
				{
					if (i2!=i1)
					{
						Turn(i2);
						if (C==2)
						{
							if (CompareLight())
							{
								Add();
							}
						}
						else
						{
							for (i3=1;i3<=4;i3++)
							{
								if (i3!=i2&&i3!=i1)
								{
									Turn(i3);
									if (CompareLight())
									{
										Add();
									}
									Turn(i3);
								}
								
							}
						}
						Turn(i2);
					}
				}
			}
			Turn(i1);
		}
	}
}

bool CompareLight()
{
	//cout<<"cl"<<endl;
	int i;
	for (i=0;i<=N-1;i++)
	{
		if (FLamps[i]==0&&Lamps[i]==1)
			return false;
		else if (FLamps[i]==1&&Lamps[i]==0)
			return false;
	}
	return true;
}

void Turn(int w)
{
	//cout<<"t"<<w<<endl;
	int i;
	for (i=0;i<=N-1;i++)
	{
		switch (w)
		{
		case 0:
			Lamps[i]=1;
			break;
		case 1:
			Lamps[i]=(Lamps[i]+1)%2;
			break;
		case 2:
			if (i%2==0)    //for odd numbers but index different from number
			{
				Lamps[i]=(Lamps[i]+1)%2;
			}
			break;
		case 3:
			if (i%2==1)
			{
				Lamps[i]=(Lamps[i]+1)%2;
			}
			break;
		case 4:
			if (i%3==0)
			{
				Lamps[i]=(Lamps[i]+1)%2;
			}
			break;
		default:
			cout<<"wrong!"<<endl;
			break;
		}
	}
}

void Add()
{
	//cout<<"add"<<endl;
	int i;
	if (!Exist())
	{
		for (i=0;i<=N-1;i++)
		{
			Result[index].l[i]=Lamps[i];
		}
		index++;
	}
}

void OutPut()
{
	//cout<<"op"<<endl;
	if (index>0)
	{
	qsort(Result,index,sizeof(lamp),cmp);
	int i, j;
	for (i=0;i<=index-1;i++)
	{
		for (j=0;j<=N-1;j++)
		{
			out<<Result[i].l[j];
		}
		out<<endl;
	}
	}
	else
	{
		out<<"IMPOSSIBLE"<<endl;
	}
}

bool Exist()
{
	int i, j;
	bool d=false;
	for (i=0;i<=index-1;i++)
	{
		d=false;
		for(j=0;j<=N-1;j++)
		{
			if (Lamps[j]!=Result[i].l[j])
			{
				d=true;
				break;
			}
		}
		if (d==false)
		{
			return true;
		}
	}
	return false;
}