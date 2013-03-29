/*
ID: haohanw1
PROG: ttwo
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

typedef struct ee
{
	int x;
	int y;
	int d;   //1 for N, 2 for N, 3 for S, 4 for W
} Position;

typedef struct aa
{
	bool f;
	bool c;
	bool o;
	bool df[4];
	bool dc[4];
} Grid;

Grid grid[10][10];

Position Move(Position);
void FootPrint(int, Position);
int Judge(Position, Position);

int main()
{
	ifstream in ("ttwo.in");
	ofstream out ("ttwo.out");
	int i, j, k;
	Position F, C;
	char c;
	int minute=0;
	bool finish=false;
	for (i=0;i<=9;i++)
	{
		for (j=0;j<=9;j++)
		{
			for (k=0;k<=3;k++)
			{
				grid[i][j].dc[k]=false;
				grid[i][j].df[k]=false;
			}
			in>>c;
			if (c=='.')
			{
				grid[i][j].o=false;
				grid[i][j].f=false;
				grid[i][j].c=false;
			}
			else if (c=='*')
			{
				grid[i][j].o=true;
			}
			else if (c=='C')
			{
				grid[i][j].o=false;
				grid[i][j].f=false;
				grid[i][j].c=true;
				grid[i][j].dc[0]=true;
				C.x=i;
				C.y=j;
				C.d=1;
			}
			else
			{
				grid[i][j].o=false;
				grid[i][j].c=false;
				grid[i][j].f=true;
				grid[i][j].df[0]=true;
				F.x=i;
				F.y=j;
				F.d=1;
			}
		}
	}
	while (!finish)
	{
		//cout<<minute<<endl;
		minute+=1;
		F=Move(F);
		C=Move(C);
		i=Judge(F, C);
		if (minute>=100000)
		{
			out<<"0"<<endl;
			finish=true;
		}
		else if (i==1)
		{
			out<<minute<<endl;
			finish=true;
		}
		FootPrint(0, C);
		FootPrint(1, F);
	}
	return 0;
}

Position Move(Position a)
{
	switch (a.d)
	{
	case 1:
		if (a.x==0)
		{
			a.d=2;
		}
		else if (grid[a.x-1][a.y].o)
		{
			a.d=2;
		}
		else
		{
			a.x-=1;
		}
		break;
	case 2:
		if (a.y==9)
		{
			a.d=3;
		}
		else if (grid[a.x][a.y+1].o)
		{
			a.d=3;
		}
		else
		{
			a.y+=1;
		}
		break;
	case 3:
		if (a.x==9)
		{
			a.d=4;
		}
		else if (grid[a.x+1][a.y].o)
		{
			a.d=4;
		}
		else
		{
			a.x+=1;
		}
		break;
	case 4:
		if (a.y==0)
		{
			a.d=1;
		}
		else if (grid[a.x][a.y-1].o)
		{
			a.d=1;
		}
		else
		{
			a.y-=1;
		}
		break;
	}
	return a;
}

int Judge(Position a, Position b)
{
	if (a.x==b.x&&a.y==b.y)
	{
		return 1;
	}
	else
	{
		if (grid[a.x][a.y].c&&grid[a.x][b.x].dc[a.d-1]&&grid[b.x][b.y].f&&grid[b.x][b.y].df[b.d-1])
			return -1;
		if (grid[a.x][a.y].f&&grid[a.x][b.x].df[a.d-1]&&grid[b.x][b.y].c&&grid[b.x][b.y].dc[b.d-1])
			return -1;
	}
	return -1;
}

void FootPrint(int i, Position a)
{
	if (i==0)
	{
		grid[a.x][a.y].c=true;
		grid[a.x][a.y].dc[a.d-1]=true;
	}
	else
	{
		grid[a.x][a.y].f=true;
		grid[a.x][a.y].df[a.d-1]=true;
	}
}