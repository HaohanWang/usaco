/*
ID: haohanw
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin ("friday.in");
    ofstream fout ("friday.out");
    
    int Week[7]={0};//Day[0] is for Sunday
    int N, i, days;
    int MonthDays[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
    int ThirteenthDay[13]={0};
    
    fin>>N;
    
    for (i=0;i<=N-1;i++)
    {
        //days=365*i+(i+1900)/4-(i+1900)/100+(i+1900)/400-(1900/4-1990/100+1900/400);
		if (i<=4)
			days=365*i;
		else if (i<=100)
			days=365*i+(i-1)/4;//-(i+300)/100+(i+300)/400+3;
		else
			days=365*i+(i-1)/4-(i+299)/100+(i+299)/400+3;
        
        if ((i+300)%400==0)
        {
           MonthDays[2]=29;
        }
        else if ((i+300)%100!=0&&i%4==0)
        {
                MonthDays[2]=29;
         }
         else 
               MonthDays[2]=28;
        
        ThirteenthDay[1]=(days%7+6)%7;
        Week[ThirteenthDay[1]]+=1;
        for (int j=2;j<=12;j++)
        {
            ThirteenthDay[j]=(ThirteenthDay[j-1]+MonthDays[j-1]%7)%7;
            Week[ThirteenthDay[j]]+=1;
        }                         
    }
    
	fout<<Week[6];
    for (i=0;i<=5;i++)
    {
        fout<<" "<<Week[i];
    }
	fout<<endl;
    
    return 0;
    
}

