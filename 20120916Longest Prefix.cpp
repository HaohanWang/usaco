/*
ID: haohanw1
PROG: prefix
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string Dict[201];
int d=0;
string S="";

bool CheckMatch(int, int);

int main()
{
	ifstream in ("prefix.in");
	ofstream out ("prefix.out");
	string rin;
	int result[200001]={0};
	int p=0, q, l;
	int i, j;
	in>>Dict[d];
	while (Dict[d]!=".")
	{
		d++;
		in>>Dict[d];
	}
	while (in>>rin)
	{
		S+=rin;
	}
	q=S.length();
	for (i=q-1;i>=0;i--)
	{
		for (j=0;j<=d-1;j++)
		{
			if (CheckMatch(i,j))
			{
				l=Dict[j].length()+result[i+Dict[j].length()];
				if (result[i]<l)
				{
					result[i]=l;
				}
			}

		}
	}
	out<<result[0]<<endl;
	return 0;
}

bool CheckMatch(int p, int j)
{
	if (S.length()-p<Dict[j].length())
	{
		return false;
	}
	else
	{
		for (int i=0;i<=Dict[j].length()-1;i++)
		{
			if (S[p+i]!=Dict[j][i])
			{
				return false;
			}
		}
	}
	return true;
}