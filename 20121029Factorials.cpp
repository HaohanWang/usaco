/*
ID: haohanw1
PROG: fact4
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in ("fact4.in");
	ofstream out ("fact4.out");
	int N;
	in>>N;
	int i, num=1;
	for (i=2;i<=N;i++)
	{
		num=num*i;
		while (num%10==0)
		{
			num=num/10;
		}
		if (num>=10000)
		{
			num=num%10000;
		}
		//out<<i<<" "<<num<<endl;
	}
	out<<num%10<<endl;
	return 0;
}