/*
ID:haohanw1
PROG: humble
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int cmp(const void *va, const void *vb)
{
	int* a=(int*)va;
	int* b=(int*)vb;
	if (*a>*b)
		return 1;
	else
		return -1;	
}
int cmpb(const void *va, const void *vb)
{
	long long* a=(long long*)va;
	long long* b=(long long*)vb;
	if (*a>*b)
		return 1;
	else
		return -1;	
}

int main()
{
	ifstream in ("humble.in");
	ofstream out ("humble.out");

	int K, N;
	int prime[1000];
	long long result[100001];
	//long long* result=(long long*)malloc(sizeof(long long*)*1000001);
	int i, j, k;
	long long num;
	in>>K>>N;
	for (i=0;i<=K-1;i++)
	{
		in>>prime[i];
	}
	qsort(prime,K,sizeof(int),cmp);
	i=0, j=0;
	int n;
	for (num=prime[0];num<=prime[K-1];num++)
	{
		n=num;
		for (i=0;i<=K-1&&n!=1;i++)
		{
			if (n%prime[i]!=0)
			{
			}
			else
			{
				n/=prime[i];
				i--;
			}
		}
		if (n==1)
		{
			result[j++]=num;
		}
	}
	int count=j;
	int end1=0, start1=0, middle1;
	int end2=0, start2=0, middle2;
	while (count<N)
	{
		end1=count-1;
		end2=count-1;
		start1=0;
		num=result[end1]*prime[K-1];
		while (start1<end1)
		{
			middle1=(start1+end1)/2;
			if (result[middle1]*prime[K-1]>result[count-1])
			{
				end1=middle1-1;
			}
			else if (result[middle1]*prime[K-1]<result[count-1])
			{
				start1=middle1+1;
			}
			else
			{
				break;
			}
		}
		/*while (start2<end2)
		{
			middle2=(start2+end2)/2;
			if (result[middle2]*prime[0]>result[count-1])
			{
				end2=middle2-1;
			}
			else if (result[middle2]*prime[0]<result[count-1])
			{
				start2=middle2+1;
			}
			else
			{
				break;
			}
		}*/
		//cout<<middle1<<" "<<middle2<<endl;
		for (i=0;i<=K-1;i++)
		{
			for (j=middle1;j<=end2;j++)
			{
				if (result[count-1]<result[j]*prime[i])
				{
					num=min(num,result[j]*prime[i]);
				}
			}
		}
		result[count++]=num;
	}
	out<<result[N-1]<<endl;
	return 0;
}