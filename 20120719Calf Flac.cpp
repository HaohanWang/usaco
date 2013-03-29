/*
ID: haohanw
PROG: calfflac
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

typedef struct alterstring
{
	char c;
	int i;
} alterstring;

bool CheckPalindrome(alterstring *, int, int);

int main()
{
	ifstream fin ("calfflac.in");
	ofstream fout ("calfflac.out");

	//char IString[20000];
	string in, istring;
	alterstring Astring[20000];
	int length, i, j=0, window=2000;

	while (getline(fin,in))
	{
		istring+=in;
		istring+='\n';
	}
	length=istring.length();
	const char * Istring=istring.c_str();

	for (i=0;i<=length-1;i++)
	{		
		if (Istring[i]>='a'&&Istring[i]<='z')
		{
			Astring[j].c=Istring[i];
			Astring[j].i=i;
			j++;
		}
		else if (Istring[i]>='A'&&Istring[i]<='Z')
		{
			Astring[j].c=Istring[i]+'a'-'A';
			Astring[j].i=i;
			j++;
		}
	}

	if (window>j-1)
		window=j-1;
	for (;window>=1;window--)
	{
		for (i=0;i+window<=j-1;i++)
		{
			if (CheckPalindrome(Astring,i,window))
			{
				fout<<window+1<<endl;
				for (int t=Astring[i].i;t<=Astring[window+i].i;t++)
				{
					fout<<Istring[t];
				}
				fout<<endl;
				return 0;
			}
		}
	}
}

bool CheckPalindrome(alterstring Astring[],int i, int window)
{
	int first=i, last=i+window;
	int j;
	for (j=first;j<=(last+first)/2+1;j++)
	{
		if (Astring[j].c!=Astring[last+first-j].c)
		{
			return false;
		}
	}
	return true;
}