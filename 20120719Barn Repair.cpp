/*
ID: haohanw
PROG: barn1
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int cmp(const void *a, const void *b)
{
	return *(int*)b-*(int*)a;
}

int main()
{
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");

	int M, S, C, i, j;
	int first=200, last=0, count=0;
	int ostall[200];
	int unstall[200];

	for (i=0;i<=199;i++)
	{
		ostall[i]=0;
		unstall[i]=0;
	}
	fin>>M>>S>>C;
	for (i=0;i<=C-1;i++)
	{
		fin>>j;
		ostall[j]=1;
		if (j<first)
			first=j;
		if (j>last)
			last=j;
	}

	j=0;
	for (i=first;i<=last;i++)
	{
		if (ostall[i]==0)
		{
			count+=1;
		}
		else
		{
			unstall[j]=count;
			count=0;
			j++;
		}
	}

	qsort(unstall,200,sizeof(int),cmp);
	count=last-first+1;
	if (M>1)
	{
		for (i=0;i<=M-2;i++)
		{
			count-=unstall[i];
		}
	}
	fout<<count<<endl;
	return 0;
}