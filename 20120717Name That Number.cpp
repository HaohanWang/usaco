/*
ID: haohanw
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

void Mapping(char[], char[], int[], int);
int Compare(char[], string[], int);
void ChangeMap(int[], int);

ofstream fout("namenum.out");

int main()
{
	ifstream fin ("namenum.in");
	ifstream DictIn ("dict.txt");
	//ofstream fout ("namenum.out");

	string Dict[5000];
	string temp;
	char Num[12];
	char Name[12];
	bool ReadFlag=false, Finish=false;
	int i=0, Item, Length, Find=0;
	int MapNum[12]={1,1,1,1,1,1,1,1,1,1,1,1};

	//ReadFlag=DictIn>>Dict[i];
	while (getline(DictIn,temp))
	{
		Dict[i]=temp;
		i++;
		//ReadFlag=DictIn>>Dict[i];
	}
	Item=i;
	fin>>Num;
	Length=strlen(Num);

	while(!Finish)
	{
		Finish=true;
		Mapping(Name,Num,MapNum,Length);
		Find+=Compare(Name,Dict,Item);
		ChangeMap(MapNum,Length);
		for (i=0;i<=Length-1;i++)
		{
			if (MapNum[i]!=3)
			{
				Finish=false;
				break;
			}
		}
	}
	if (Find==0)
		fout<<"NONE"<<endl;

	fout.close();

	return 0;
}

void Mapping(char Name[], char Num[], int MapNum[], int Length)
{
	int i;
	for (i=0;i<=Length-1;i++)
	{
		Name[i]=61+(Num[i]-49)*3+MapNum[i];
		if (Name[i]>='Q')
			Name[i]+=1;
	}
	if (i<12)
	{
		//i++;
		Name[i]='\0';
	}
}

int Compare(char Name[], string Dict[],int Item)
{
	int h=0, t=Item-1;
	int mid=(h+t)/2;
	bool Find=false;
	string name=Name;
	
	while (h<=t)
	{
		mid=(h+t)/2;
		if (name<Dict[mid])
		{
			t=mid-1;
		}
		else if (name>Dict[mid])
		{
			h=mid+1;
		}
		else
		{
			fout<<name<<endl;
			Find=true;
			break;
		}
	}
	if(Find)
		return 1;
	else
		return 0;
}

void ChangeMap(int MapNum[], int Length)
{
	int i;
	for (i=Length-1;i>=0;i--)
	{
		if (MapNum[i]!=3)
		{
			break;
		}
	}
	MapNum[i]+=1;
	for (i=i+1;i<=Length-1;i++)
	{
		MapNum[i]=1;
	}
}

