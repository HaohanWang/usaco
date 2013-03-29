/*
ID: haohanw
PROG: packrec
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef struct resultarea
{
	int area;
	int l;
	int w;
} resultarea;

int index=0;

int cmp(const void *va, const void *vb)
{
	resultarea *a=(resultarea*)va;
	resultarea *b=(resultarea*)vb;
	if (a->area==b->area)
	{
		return a->w-b->w;
	}
	else
		return a->area-b->area;
}

void AddRect(resultarea A[], int Rect[][2], int i, int a1, int a2, int a3, int a4)
{
	switch(i)
	{
	case 1:	A[index].l=Rect[a1][0]+Rect[a2][0]+Rect[a3][0]+Rect[a4][0];
			A[index].w=max(max(Rect[a1][1],Rect[a2][1]),max(Rect[a3][1],Rect[a4][1]));
			break;
	case 2:	A[index].l=max(Rect[a1][1],Rect[a2][0]+Rect[a3][0]+Rect[a4][0]);
			A[index].w=Rect[a1][0]+max(max(Rect[a2][1],Rect[a3][1]),Rect[a4][1]);
			break;
	case 3:	A[index].l=max(Rect[a1][1],Rect[a2][0]+Rect[a3][0])+Rect[a4][0];
			A[index].w=max(Rect[a4][1],Rect[a1][0]+max(Rect[a2][1],Rect[a3][1]));
			break;
	case 4:	
	case 5:	A[index].l=max(Rect[a2][0],Rect[a3][0])+Rect[a1][0]+Rect[a4][0];
			A[index].w=max(Rect[a2][1]+Rect[a3][1],max(Rect[a1][1],Rect[a4][1]));
			break;
	case 6:	A[index].l=max(Rect[a1][0],Rect[a3][0])+max(Rect[a2][0],Rect[a4][0]);
			A[index].w=max(Rect[a1][1]+Rect[a3][1],Rect[a2][1]+Rect[a4][1]);
			if (Rect[a1][0]>=Rect[a3][0]&&Rect[a2][0]>=Rect[a4][0]&&Rect[a1][1]+Rect[a2][1]<=A[index].w)
			{
				A[index].l=max(Rect[a1][0]+Rect[a4][0],Rect[a3][0]+Rect[a2][0]);
			}
			break;
	}
	if (A[index].l<A[index].w)
	{
		int temp=A[index].l;
		A[index].l=A[index].w;
		A[index].w=temp;
	}
	A[index].area=A[index].l*A[index].w;
	index++;
}

void ChangeRect(int Rect[][2], int NewRect[][2], int count)
{
	int i;
	for (i=0;i<=3;i++)
	{
		if (count%2==1)
		{
			NewRect[i][0]=Rect[i][1];
			NewRect[i][1]=Rect[i][0];
		}
		else
		{
			NewRect[i][1]=Rect[i][1];
			NewRect[i][0]=Rect[i][0];
		}
		count=count/2;
	}
}

int main()
{
	ifstream fin ("packrec.in");
	ofstream fout ("packrec.out");

	int Rect[4][2];
	int NewRect[4][2];
	int count=0;
	resultarea A[2500];
	int i, temp;
	int r1, r2, r3, r4;
	for (i=0;i<=2499;i++)
	{
		A[i].area=0;
		A[i].l=0;
		A[i].w=0;
	}
	for (i=0;i<=3;i++)
	{
		fin>>Rect[i][0]>>Rect[i][1];
		if (Rect[i][0]>Rect[i][1])
		{
			temp=Rect[i][0];
			Rect[i][0]=Rect[i][1];
			Rect[i][1]=temp;
		}
	}
	for (i=1;i<=6;i++)
	{
		for (r1=0;r1<=3;r1++)
		{
			for (r2=0;r2<=3;r2++)
			{
				if (r1!=r2)
				{
					for (r3=0;r3<=3;r3++)
					{
						if (r1!=r3&&r2!=r3)
						{
							for (r4=0;r4<=3;r4++)
							{
								if (r4!=r1&&r4!=r2&&r4!=r3)
								{
									for (count=0;count<=15;count++)
									{
										ChangeRect(Rect,NewRect,count);
										AddRect(A,NewRect,i,r1,r2,r3,r4);
										//fout<<index-1<<"\t"<<A[index-1].area<<" "<<A[index-1].l<<" "<<A[index-1].w<<endl;
										//fout<<i<<" "<<r1<<" "<<r2<<" "<<r3<<" "<<r4<<" "<<count<<endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	qsort(A,index,sizeof(resultarea),cmp);
	fout<<A[0].area<<endl;
	fout<<A[0].w<<" "<<A[0].l<<endl;
	for (i=1;i<=index;i++)
	{
		if (A[i].area!=A[i-1].area)
		{
			break;
		}
		else if (A[i].l!=A[i-1].l)
		{
			fout<<A[i].w<<" "<<A[i].l<<endl;
		}
	}
	return 0;
}