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

typedef struct cc
{
	int x;
	int y;
	bool v;
	int way;
	int num;
	cc* link[4];
}mazeunit;


int main()
{
	ifstream in ("maze1.in");
	ofstream out ("maze1.out");
	FILE *stream=fopen("maze1.in","r");
	char Map[201][77];
	mazeunit Maze[100][38];
	int queue[3800][2];
	int head=0;
	int tail=0;
	in>>W>>H;
	int i, j;
	int count=0;
	int ex[2];
	int ey[2];
	//string str;
	char str1[90]={};
	int tM=0;
	for (i=0;i<=200;i++)
	{
		for (j=0;j<=76;j++)
		{
			Map[i][j]=' ';
		}
	}
	for (i=0;i<=H-1;i++)
	{
		for (j=0;j<=W-1;j++)
		{
			if (i==99&&j==35)
				j=35;
			Maze[i][j].num=0;
			Maze[i][j].x=i;
			Maze[i][j].y=j;
			//Maze[i][j].v=false;
			Maze[i][j].way=0;
		}
	}
	fgets(str1,25,stream);
	for (i=0;i<=H*2;i++)
	{
		//getline(in, str, '\n');
		fgets(str1,2*W+3,stream);
		for (j=0;j<=W*2;j++)
		{
			Map[i][j]=str1[j];
		}
		//cout<<i<<" "<<j<<endl;
	}
	in.close();
	for (i=0;i<=H-1;i++)
	{
		for (j=0;j<=W-1;j++)
		{
			cout<<i<<" "<<j<<" "<<Maze[i][j].num<<endl;
		}
	}
	for (i=1;i<=2*H-1;i+=2)
	{
		for (j=1;j<=2*W-1;j+=2)
		{
			if (i==199&&j==71)
				j=71;
			if (Map[i-1][j]==' ')
			{
				if (i-1==0)
				{
					ex[count]=i/2;
					ey[count]=j/2;
					//cout<<i<<" "<<j<<endl;
					count++;
				}
				else
				{
					Maze[i/2][j/2].link[Maze[i/2][j/2].num]=&Maze[i/2-1][j/2];
					Maze[i/2][j/2].num++;
				}
			}
			if (Map[i+1][j]==' ')
			{
				if (i+1==2*H)
				{
					ex[count]=i/2;
					ey[count]=j/2;
					//cout<<i<<" "<<j<<endl;
					count++;
				}
				else
				{
					Maze[i/2][j/2].link[Maze[i/2][j/2].num]=&Maze[i/2+1][j/2];
					Maze[i/2][j/2].num++;
				}
			}
			if (Map[i][j-1]==' ')
			{
				if (j-1==0)
				{
					ex[count]=i/2;
					ey[count]=j/2;
					//cout<<i<<" "<<j<<endl;
					count++;
				}
				else
				{
					Maze[i/2][j/2].link[Maze[i/2][j/2].num]=&Maze[i/2][j/2-1];
					Maze[i/2][j/2].num++;
				}
			}
			if (Map[i][j+1]==' ')
			{
				if (j+1==2*W)
				{
					ex[count]=i/2;
					ey[count]=j/2;
					//cout<<i<<" "<<j<<endl;
					count++;
				}
				else
				{
					Maze[i/2][j/2].link[Maze[i/2][j/2].num]=&Maze[i/2][j/2+1];
					Maze[i/2][j/2].num++;
				}
			}
		}
	}
	for (count=count-1;count>=0;count--)
	{
		int x=ex[count], y=ey[count];
		int index=0;
		for (i=0;i<=H-1;i++)
		{
			for (j=0;j<=W-1;j++)
			{
				Maze[i][j].v=false;
			}
		}
		head=0;
		tail=0;
		queue[tail][0]=x;
		queue[tail][1]=y;
		Maze[x][y].way=1;
		Maze[x][y].v=true;
		tail++;
		while (head!=tail)
		{
			//cout<<head<<" "<<tail<<endl;
			x=queue[head][0];
			y=queue[head][1];
			head++;
			//out<<"----"<<x<<" "<<y<<endl;
			
			index=Maze[x][y].num-1;
			//cout<<x<<" "<<y<<" "<<index<<endl;
			for (;index>=0;index--)
			{
				if (Maze[x][y].link[index]->v==true)
				{
				}
				else
				{
					if (Maze[x][y].link[index]->way!=0&&Maze[x][y].link[index]->way<Maze[x][y].way+1)
					{
					}
					else
					{ 
						Maze[x][y].link[index]->v=true;
						Maze[x][y].link[index]->way=Maze[x][y].way+1;
						queue[tail][0]=Maze[x][y].link[index]->x;
						queue[tail][1]=Maze[x][y].link[index]->y;
						tail++;
					}
				}
			}
		}
	}
	for (i=0;i<=H-1;i++)
	{
		for (j=0;j<=W-1;j++)
		{
			if (tM<Maze[i][j].way)
				tM=Maze[i][j].way;
		}
	}
	out<<tM<<endl;
	out.close();
	return 0;
}
