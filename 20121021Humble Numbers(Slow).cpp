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

int main()
{
	ifstream in ("humble.in");
	ofstream out ("humble.out");

	int K, N;
	int prime[1000];
	bool* map=(bool*)malloc(sizeof(bool)*10000000);
	int i, j, num;
	in>>K>>N;
	for (i=0;i<=K-1;i++)
	{
		in>>prime[i];
	}
	for (i=0;i<=9999999;i++)
	{
		map[i]=false;
	}
	qsort(prime,K,sizeof(int),cmp);
	map[1]=true;
	map[prime[0]]=true;
	num=prime[0]+1;
	int n;
	int count=2;
	//bool humble=false;
	while(count!=N+1)
	{
		n=num;
		//humble=true;
		for (i=0;i<=K-1&&n!=1;i++)
		{
			if (n%prime[i]!=0)
			{
			}
			else
			{
				n/=prime[i];
				i--;
				//cout<<"------"<<endl;
				if (n<10000000)
				{
					//cout<<"******"<<endl;
					if (map[n])
					{
						//cout<<"**"<<endl;
						n=1;
						break;
					}
					else
					{
						//cout<<"**"<<endl;
						break;
					}
				}
			}
		}
		if (n==1)
		{
			//cout<<count<<" "<<num<<endl;
			if (num<10000000)
			{
				map[num]=true;
			}
			count++;
			num++;
		}
		else
		{
		num++;
		}
	}
	out<<num-1<<endl;
	//system("pause");
	return 0;
}