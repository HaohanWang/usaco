/*
ID: haohanw1
PROG: prefix
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string pri[202];
int num=0;
string sequence;
bool DONE=false;                        //不能使用find作为变量

int LongestPrefix(int);
bool CompareString(string, int);
int cmp(const void *va, const void *vb)
{
	string *a=(string*)va;
	string *b=(string*)vb;
	if (a>b)
		return -1;
	else if (a<b)
		return 1;
	else
		return 0;
}

int main()
{
	ifstream in("prefix.in");
	ofstream out("prefix.out");
	int q;
	int i;
	string str;
	int result=0;
	in>>pri[num];                                      //不能直接读入char*
	while(pri[num]!=".")
	{
		num++;
		in>>pri[num];
	}
	string strin;
	while(in>>strin)                                 //读入string受行的限制
	{
		sequence+=strin;
	}
	q=sequence.length();
	qsort(pri,num,sizeof(string),cmp);
	for (i=q-1;i>=0;i--)
	{
		cout<<i<<endl;
		result=LongestPrefix(i);
		if (DONE)
		{
			out<<result<<endl;
			return 0;
		}
	}
	if (!DONE)
	{
		out<<"0"<<endl;
	}
	return 0;
}

int LongestPrefix(int q)
{
	cout<<q<<"-----";
	int result=0;
	int r=0;
	int i;
	if (q==-1)                                     //数组的第0项仍然存在，不存在的是-1
	{
		DONE=true;
		return 0;
	}
	else if (q==0)
	{
		for (i=0;i<=num;i++)
		{
			if (CompareString(pri[i],q))
			{
				DONE=true;
				return 1;
			}
		}
		return 0;
	}
	else
	{
		for (i=0;i<=num;i++)
		{	
			if (CompareString(pri[i],q))
			{
				cout<<i<<endl;
				r=0;
				q=q-pri[i].length();
				r+=pri[i].length();
				r+=LongestPrefix(q);
				result+=r;
				if (DONE==true)
				{
					return result;
				}
				q=q+pri[i].length();     //递归之后要恢复值
				result-=r;
			}
		}
		return 0;
	}
}

bool CompareString(string a, int q)
{
	int p=q-a.length()+1;               //下标的移动不是简单的加减
	if (p<0)							//注意可能超出边界的情况
	{
		return false;
	}
	else
	{
	int i=0;
	//cout<<a<<endl;
	for (i=0;i<=a.length()-1;i++)
	{
		if (a[i]!=sequence[p+i])
			return false;
	}
	return true;
	}
}