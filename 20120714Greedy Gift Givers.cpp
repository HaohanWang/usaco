/*
ID: haohanw
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int FindPerson(string person, string* Name, int Num)
{
    for (int i=1;i<=Num;i++)
    {
        if (person==Name[i])
           return i;
    }
}

int main()
{
    ifstream fin ("gift1.in");
    ofstream fout ("gift1.out");
    
    string Name[11];
    string Person;
    int Num, Money, i, j, p, q, r;
    int Profit[11]={0};
    
    fin>>Num;
    for (i=1;i<=Num;i++)
    {
        fin>>Name[i];
    }
    
    for (i=1;i<=Num;i++)
    {
        fin>>Person;
        p=FindPerson(Person, Name, Num);
        fin>>Money;
        fin>>r;
        if (r==0)
        {
            Profit[p]+=Money;     
        }
        else
        {
            for (j=1;j<=r;j++)
            {
                fin>>Person;
                q=FindPerson(Person, Name, Num);
                Profit[q]+=Money/r;
            }
            Profit[p]-=Money;
            Profit[p]+=Money%r;
        }
    }
    
    for (i=1;i<=Num;i++)
    {
        fout<<Name[i]<<" "<<Profit[i]<<endl;
    }
    
    return 0; 
}
