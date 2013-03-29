/*
ID: haohanw
PROG: hamming
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int Hamming(int, int);

int main()
{
	ifstream in ("hamming.in");
	ofstream out ("hamming.out");

	int N, B, D;
	in>>N>>B>>D;
	int i, j;
	int result[64];
	int index=0;
	result[0]=0;
	bool finish=false;
	bool qualify=true;
	if (N==1)
	{
		out<<"0"<<endl;
	}
	else
	{
		for (i=1;!finish;i++)
		{
			qualify=true;
			for (j=0;j<=index;j++)
			{
				if (Hamming(i,result[j])<D)
				{
					qualify=false;
					break;
				}
			}
			if (qualify==true)
			{
				index++;
				result[index]=i;
				if ((index+1)==N)
				{
					finish=true;
				}
			}
		}
		for (i=0;i<=index;i++)
		{
			if (i%10!=9&&i!=index)
			{
				out<<result[i]<<" ";
			}
			else if(i%10!=9&&i==index)
			{
				out<<result[i];
			}
			else
			{
				out<<result[i]<<endl;
			}
		}
		if (index%10!=9)
		{
			out<<endl;
		}
	}
	return 0;
}

int Hamming(int i, int j)
{
	int h=0;
	while(i!=0||j!=0)
	{
		h+=fabs((double)(i%2)-(j%2));
		i/=2;
		j/=2;
	}
	return h;
}
