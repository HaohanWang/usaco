/*
ID: haohanw
PROG: preface
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in ("preface.in");
	ofstream out ("preface.out");

	int N;
	in>>N;
	int ch[7]={0};
	int i, j, k;
	int d;
	for (k=1;k<=N;k++)
	{
		i=k;
		j=0;
		while (i!=0)
		{
			d=i%10;
			switch(d)
			{
			case 1:
			case 2:
			case 3: 
				ch[j]+=d;
				break;
			case 4: 
				ch[j]+=1;
				ch[j+1]+=1;
				break;
			case 5:
			case 6:
			case 7:
			case 8:
				ch[j]+=(d-5);
				ch[j+1]+=1;
				break;
			case 9:
				ch[j]+=1;
				ch[j+2]+=1;
				break;
			case 0:
			default:
				break;
			}
			i=i/10;
			j+=2;
		}
	}
	if (ch[0]!=0)
		out<<"I "<<ch[0]<<endl;
	if (ch[1]!=0)
		out<<"V "<<ch[1]<<endl;
	if (ch[2]!=0)
		out<<"X "<<ch[2]<<endl;
	if (ch[3]!=0)
		out<<"L "<<ch[3]<<endl;
	if (ch[4]!=0)
		out<<"C "<<ch[4]<<endl;
	if (ch[5]!=0)
		out<<"D "<<ch[5]<<endl;
	if (ch[6]!=0)
		out<<"M "<<ch[6]<<endl;

	return 0;
}