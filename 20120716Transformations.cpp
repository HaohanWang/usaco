/*
ID: haohanw
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

void AssignTemp(char[][10], char[][10],int);
bool CheckSame(char[][10], char[][10],int);
void Rotate90(char[][10], int);
void Reflection(char[][10], int);

int main()
{
	ifstream fin("transform.in");
	ofstream fout("transform.out");
	int N, i, j;
	bool finish=false;
	char P[10][10];
	char G[10][10];
	char T[10][10];

	fin>>N;
	for (i=0;i<=N-1;i++)
	{
		for (j=0;j<=N-1;j++)
		{
			fin>>P[i][j];
		}
	}
	for (i=0;i<=N-1;i++)
	{
		for (j=0;j<=N-1;j++)
		{
			fin>>G[i][j];
		}
	}

	/*if (CheckSame(P,G,N))
	{
		fout<<"6"<<endl;
		finish=true;
	}
	else
	{*/
		AssignTemp(T,P,N);
		Rotate90(T,N);
		if (CheckSame(T,G,N))
		{
			fout<<"1"<<endl;
			finish=true;
		}
		else
		{
			Rotate90(T,N);
			if (CheckSame(T,G,N))
			{
				fout<<"2"<<endl;
				finish=true;
			}
			else
			{
				Rotate90(T,N);
				if (CheckSame(T,G,N))
				{
					fout<<"3"<<endl;
					finish=true;
				}
			}
		}
		if (finish==false)
		{
			AssignTemp(T,P,N);
			Reflection(T,N);
			if (CheckSame(T,G,N))
			{
				fout<<"4"<<endl;
				finish=true;
			}
			else
			{
				Rotate90(T,N);
				if (CheckSame(T,G,N))
				{
					fout<<"5"<<endl;
					finish=true;
				}
				else
				{
					Rotate90(T,N);
					if (CheckSame(T,G,N))
					{
						fout<<"5"<<endl;
						finish=true;
					}
					else
					{
						Rotate90(T,N);
						if (CheckSame(T,G,N))
						{
							fout<<"5"<<endl;
							finish=true;
						}
					}
				}
			}
		}
	//}
	if (finish==false)
	{
		if (CheckSame(P,G,N))
		{
			fout<<"6"<<endl;
		}
		else
			fout<<"7"<<endl;
	}
	return 0;
}

void AssignTemp(char T[][10],char P[][10], int N)
{
	int i,j;
	for (i=0;i<=N-1;i++)
	{
		for (j=0;j<=N-1;j++)
		{
			T[i][j]=P[i][j];
		}
	}
}

bool CheckSame(char T[][10], char G[][10], int N)
{
	int i, j;
	for (i=0;i<=N-1;i++)
	{
		for (j=0;j<=N-1;j++)
		{
			if (T[i][j]!=G[i][j])
			{
				return false;
				break;
			}
		}
	}
	return true;
}

void Rotate90(char T[][10], int N)
{
	int i, j;
	char temp[10][10];
	AssignTemp(temp,T,N);
	for (i=0;i<=N-1;i++)
	{
		for (j=0;j<=N-1;j++)
		{
			T[i][j]=temp[N-1-j][i];
		}
	}
}

void Reflection(char T[][10], int N)
{
	int i, j;
	char temp[10][10];
	AssignTemp(temp,T,N);
	for (i=0;i<=N-1;i++)
	{
		for (j=0;j<=N-1;j++)
		{
			T[i][j]=temp[i][N-1-j];
		}
	}
}