/*
ID: haohanw1
PROG: msquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char A(int *a)
{
	int temp, i;
	for (i=0;i<=3;i++)
	{
		temp=a[i];
		a[i]=a[7-i];
		a[7-i]=temp;
	}
	return 'A';
}

char B(int *a)
{
	int temp[8];
	int i;
	for (i=0;i<=7;i++)
	{
		temp[i]=a[i];
	}
	for (i=0;i<=3;i++)
	{
		a[i]=temp[(i+3)%4];
	}
	for (i=4;i<=7;i++)
	{
		a[i]=temp[(i+1)%4+4];
	}
	return 'B';
}

char C(int *a)
{
	int temp;
	temp=a[1];
	a[1]=a[6];
	a[6]=a[5];
	a[5]=a[2];
	a[2]=temp;
	return 'C';
}

void Copy(int *a, int *b)
{
	for (int i=0;i<=7;i++)
	{
		b[i]=a[i];
	}
}

void CopyR(char *a, char *b, int num)
{
	for (int i=0;i<=num-1;i++)
	{
		b[i]=a[i];
	}
}

typedef struct cc
{
	char result[100];
	int index;
	int status;
} Unit;

Unit* u=(Unit*)malloc(40320*(sizeof(Unit)));
ofstream out ("msquare.out");

int Map(int *a)
{
	bool small[8]={0};
	int fac[7]={5040, 720, 120, 24, 6, 2, 1};
	int count=0;
	int result=0;
 	for (int i=0;i<=6;i++)
	{
		small[a[i]-1]=true;
		count=0;
		for (int j=0;j<=7;j++)
		{
			if (j+1<a[i]&&small[j]==false)
				count++;
		}
		result+=count*fac[i];
	}
	return result;
}

void Reverse(int n, int* a)
{
	bool small[8]={0};
	int fac[7]={5040, 720, 120, 24, 6, 2, 1};
	//int rem[7]={0};
	int q=0;
	int count=0;
	int j;
	int i;
	for(i=0;i<=6;i++)
	{
		q=n/fac[i];
		n=n%fac[i];
		count=0;
		for (j=0;j<=7;j++)
		{
			if (small[j]==false)
			{
				if (count==q)
				{
					j++;
					break;
				}
				count++;
			}
		}
		small[j-1]=true;
		a[i]=j;
	}
	for (i=0;i<=7;i++)
	{
		if (small[i]==false)
		{
			a[7]=i+1;
			break;
		}
	}
}

void Output(int map)
{
	int i;
	out<<u[map].index<<endl;
	for (i=0;i<=u[map].index-1;i++)
	{
		out<<u[map].result[i];
		if ((i+1)%60==0)
			out<<endl;
	}
	if (i%60!=0)
		out<<endl;
}

bool JudgeOrder(char * a, char c, char* b, int index)
{
	int i;
	for (i=0;i<=index-2;i++)
	{
		if (a[i]<b[i])
			return true;
		if (a[i]>b[i])
			return false;
	}
	if (c<b[index-1])
		return true;
	return false;
}

void DOP(int *a)
{
	for (int i=0;i<=7;i++)
	{
		out<<a[i]<<" ";
	}
	out<<endl;
}

int main()
{
	ifstream in ("msquare.in");
	char c;
	int map;
	int s[8]={1, 2, 3, 4, 5, 6, 7, 8};
	int g[8];
	int i;
	for (i=0;i<=7;i++)
	{
		in>>g[i];
	}
	int goal=Map(g);
	if (goal==0)
	{
		out<<0<<endl<<endl;
		return 0;
	}
	for (i=0;i<=40319;i++)
	{
		u[i].index=0;
		u[i].status=0;
	}
	u[0].status=1;
	bool finish=false;
	int tempI;
	while (!finish)
	{
		finish=true;
		for (i=0;i<=40319;i++)
		{
			if (u[i].status==0)
			{
				finish=false;
				break;
			}
		}
		for (i=0;i<=40319;i++)
		{
			if (u[i].status==1)
			{
				u[i].status=2;
				tempI=u[i].index+1;
				Reverse(i,s);
				if (i==25614||i==39752)
				{
					cout<<i<<endl;
					cout<<u[i].result<<endl;
				}
				//out<<"----------"<<endl<<i<<endl;
				//DOP(s);
				Copy(s, g);
				c=A(g);
				map=Map(g);
				if (map==25614)
				{
					cout<<i<<endl;
					cout<<u[i].result<<endl;
				}
				if (u[map].status==0)
				{
					CopyR(u[i].result,u[map].result,u[i].index);
					u[map].index=u[i].index+1;
					u[map].result[u[map].index-1]=c;
					/*if (map==goal)
					{
						Output(map);
						finish=true;
						break;
					}*/
					u[map].status=1;
				}
				else
				{
					if (tempI==u[map].index)
					{
						if (JudgeOrder(u[i].result,c,u[map].result,tempI))
						{
							CopyR(u[i].result,u[map].result,u[i].index);
							u[map].index=u[i].index+1;
							u[map].result[u[map].index-1]=c;
							/*if (map==goal)
							{
								Output(map);
								finish=true;
								break;
							}*/
							u[map].status=1;
						}
					}
				}
				Copy(s, g);
				c=B(g);
				map=Map(g);
				if (map==25614)
				{
					cout<<i<<endl;
					cout<<u[i].result<<endl;
				}
				if (u[map].status==0)
				{
					CopyR(u[i].result,u[map].result,u[i].index);
					u[map].index=u[i].index+1;
					u[map].result[u[map].index-1]=c;
					/*if (map==goal)
					{
						Output(map);
						finish=true;
						break;
					}*/
					u[map].status=1;
				}
				else
				{
					if (tempI==u[map].index)
					{
						if (JudgeOrder(u[i].result,c,u[map].result,tempI))
						{
							CopyR(u[i].result,u[map].result,u[i].index);
							u[map].index=u[i].index+1;
							u[map].result[u[map].index-1]=c;
							/*if (map==goal)
							{
								Output(map);
								finish=true;
								break;
							}*/
							u[map].status=1;
						}
					}
				}
				Copy(s, g);
				c=C(g);
				map=Map(g);
				if (map==25614)
				{
					cout<<i<<endl;
					cout<<u[i].result<<endl;
				}
				if (u[map].status==0)
				{
					CopyR(u[i].result,u[map].result,u[i].index);
					u[map].index=u[i].index+1;
					u[map].result[u[map].index-1]=c;
					/*if (map==goal)
					{
						Output(map);
						finish=true;
						break;
					}*/
					u[map].status=1;
				}
				else
				{
					if (tempI==u[map].index)
					{
						if (JudgeOrder(u[i].result,c,u[map].result,tempI))
						{
							CopyR(u[i].result,u[map].result,u[i].index);
							u[map].index=u[i].index+1;
							u[map].result[u[map].index-1]=c;
							/*if (map==goal)
							{
								Output(map);
								finish=true;
								break;
							}*/
							u[map].status=1;
						}
					}
				}
			}
		}
	}
	Output(goal);
	system("pause");
	return 0;
}