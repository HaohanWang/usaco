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

void AddRect(int Rect[][2], resultarea A[], bool Horizon, int count, int l, int w)
{
	if(Horizon)
	{
		l=max(l,Rect[count][1]);
		w+=Rect[count][0];
		if (count!=3)
		{
			AddRect(Rect,A,Horizon,count+1, l, w);
			AddRect(Rect,A,!Horizon,count+1, l, w);
		}
		else
		{
			if (l<w)
			{
				int temp;
				temp=l;
				l=w;
				w=temp;
			}
			A[index].l=l;
			A[index].w=w;
			A[index].area=A[index].l*A[index].w;
			index++;
		}
	}
	else
	{
		l+=Rect[count][0];
		w=max(w,Rect[count][1]);
		if (count!=3)
		{
			AddRect(Rect,A,Horizon,count+1, l, w);
			AddRect(Rect,A,!Horizon,count+1, l, w);
		}
		else
		{
			if (l<w)
			{
				int temp;
				temp=l;
				l=w;
				w=temp;
			}
			A[index].l=l;
			A[index].w=w;
			A[index].area=A[index].l*A[index].w;
			index++;
		}
	}
}

int main()
{
	ifstream fin ("packrec.in");
	ofstream fout ("packrec.out");

	int Rect[4][2];
	resultarea A[20];
	bool Horizon=true;
	int i, temp, j, count=0, identical=0;
	for (i=0;i<=19;i++)
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

	for (i=0;i<=3;i++)
	{
		for (j=i;j<=3;j++)
		{
			if (Rect[i][0]>Rect[j][0])
			{
				temp=Rect[i][0];
				Rect[i][0]=Rect[j][0];
				Rect[j][0]=temp;
				temp=Rect[i][1];
				Rect[i][1]=Rect[j][1];
				Rect[j][1]=Rect[i][1];
			}
			else if (Rect[i][0]==Rect[j][0]&&Rect[i][1]>Rect[j][1])
			{
				temp=Rect[i][1];
				Rect[i][1]=Rect[j][1];
				Rect[j][1]=Rect[i][1];
			}
		}
	}
	for (i=0;i<=2;i++)
	{
		if (Rect[i][0]==Rect[i+1][0]&&Rect[i+1][1]==Rect[i][1])
		{
			count+=1;
		}
	}
	if (identical==3)
	{
		fout<<(Rect[0][0]+Rect[0][0])*(Rect[0][1]+Rect[0][1])<<endl;
		fout<<Rect[0][1]*2<<" "<<Rect[0][0]*2<<endl;
		return 0;
	}
	AddRect(Rect,A,Horizon,count,0,0);
	AddRect(Rect,A,!Horizon,count,0,0);
	qsort(A,index,sizeof(resultarea),cmp);
	fout<<A[0].area<<endl;
	fout<<A[0].l<<" "<<A[0].w<<endl;
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