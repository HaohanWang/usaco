/*
ID: haohanw
PROG: crypt1
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

bool CheckExist(int, int[], int);

int main()
{
	ifstream fin ("crypt1.in");
	ofstream fout ("crypt1.out");

	int num, i, m1, count, p1, p2, r;
	int i1, i2, i3, j1, j2;
	int N[9];
	fin>>num;
	for (i=0;i<=num-1;i++)
	{
		fin>>N[i];
	}
	count=0;
	for (i1=0;i1<=num-1;i1++)
	{
		m1=0;
		m1+=N[i1]*100;
		for (i2=0;i2<=num-1;i2++)
		{
			m1+=N[i2]*10;
			for (i3=0;i3<=num-1;i3++)
			{
				m1+=N[i3];
				for (j1=0;j1<=num-1;j1++)
				{
					p1=m1*N[j1];
					if (p1<=999&&CheckExist(p1,N, num))
					{
						for (j2=0;j2<=num-1;j2++)
						{
							p2=m1*N[j2];
							if (p2<=999&&CheckExist(p2,N, num))
							{
								r=p1*10+p2;
								if (r<=9999&&CheckExist(r,N, num))
								{
									count+=1;
									/*cout<<m1<<endl;
									cout<<N[j1]*10+N[j2]<<endl;*/
								}
							}
						}
					}
				}
				m1-=N[i3];
			}
			m1-=N[i2]*10;
		}
	}
	fout<<count<<endl;
	//system("pause");
	return 0;
}

bool CheckExist(int m, int *N, int num)
{
	int exist=0, count=0;
	int n, i;
	while (m!=0)
	{
		exist+=1;
		n=m%10;
		for (i=0;i<=num-1;i++)
		{
			if (n==N[i])
			{
				count+=1;
				break;
			}
		}
		m=m/10;
	}
	if (count==exist)
		return true;
	else
		return false;
}