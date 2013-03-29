/*
ID: haohanw
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin ("beads.in");
    ofstream fout ("beads.out");
    
    char Beads[701];
    int N, i, l=0, r=0, Lmax=0, Rmax=0, Tmax=0, TempMax=0, MaxWhiteL=0, MaxWhiteR=0, LeftMost=0, LeftMostWhite=0;
    
    fin>>N;
    
	Beads[0]='o';
	for (i=1;i<=N;i++)
	{
		fin>>Beads[i];
	}

	for (i=1;i<=N;i++)
	{
		Beads[N+i]=Beads[i];
	}
	Beads[N*2+1]='\0';

    for (l=1;l<=2*N-1;l++)
    {
        Lmax+=1;
        char Lcolor=Beads[1];
        if (Beads[l+1]=='w')
        {
           MaxWhiteL+=1;
           }
        else if (Lcolor==Beads[l+1])
        {
           MaxWhiteL=0;
           }
        else
        {
            break;
        } 
    }
    
    while (r<2*N)
    {
		Rmax=0;
		MaxWhiteR=0;
          char Rcolor=Beads[l+1];
          for (r=l+1;r<=2*N-1;r++)
          {
              Rmax+=1;
              if (Beads[r+1]=='w')
              {
                 MaxWhiteR+=1;
              }
              else if (Rcolor==Beads[r+1])
              {
                   MaxWhiteR=0;
              }
              else
              {
                  break;
              } 
          }
		  if (r==(2*N)&&Beads[2*N]==Rcolor)
			  Rmax+=1;
          TempMax=Lmax+Rmax;
          if (TempMax>Tmax)
             Tmax=TempMax;
		  
		  /*cout<<Beads<<endl;
		  cout<<l<<"\t"<<r<<endl;
		  cout<<TempMax<<"\t"<<Tmax<<endl;*/

          Lmax=Rmax+MaxWhiteL;
          MaxWhiteL=MaxWhiteR;
          l=r;
    }
	if (Tmax<N)
		fout<<Tmax<<endl;
	else
		fout<<N<<endl;
	//system("pause");
    return 0;
}
