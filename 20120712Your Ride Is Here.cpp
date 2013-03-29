/*
ID: haohanw
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    
    int num1=1, num2=1, p=0;
    string str, str1;
    const char *ch;
    fin>>str;
    
    while (p<str.size())
    {
          str1=str.substr(p,1);
          ch=str1.c_str();
          num1*=((int)(*ch)-64);
          p++;
    }
    
    p=0;
    fin>>str;
    while (p<str.size())
    {
          str1=str.substr(p,1);
          ch=str1.c_str();
          num2*=((int)(*ch)-64);
          p++;
    }
    
    if ((num1%47)==(num2%47))
       fout<<"GO"<<endl;
    else
       fout<<"STAY"<<endl;
       
    return 0;     
}
