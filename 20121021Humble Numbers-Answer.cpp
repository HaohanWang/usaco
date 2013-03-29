/*
ID:haohanw1
PROG:humble
LANG: C++
*/
#include<fstream>
using namespace std;
ifstream fin("humble.in");
ofstream cout("humble.out");
 
int a[101],b[101]={0},k,n;long long f[100001];
 
int Check(int t){
    if(t==1) return 1;
    if(f[t]!=-1) return f[t];
    int i;
    for(i=1;i<=k;i++)
    if(t%a[i]==0)
    return Check(t/a[i]);
    return 0;
    }
 
int main()
{
    int i,j;
    fin>>k>>n;
 
    for(i=1;i<=k;i++)
    fin>>a[i];
    for(i=2;i<=100000;i++)
    f[i]=-1;
    for(i=2;i<=100000;i++)
    if(Check(i))
    f[i]=1;
    else f[i]=0;
    j=1;
    for(i=2;i<=100000;i++)
    if(f[i]==1)
    f[j++]=i;
 
    i=j;
    for(j=1;j<=k;j++)
    while(a[j]*f[b[j]+1]<=f[i-1])
    b[j]++; 
 
    long long mi;
    for(;i<=n;i++)
    {
     mi=0xffffffff;
     for(j=1;j<=k;j++)
     if(a[j]*f[b[j]+1]>f[i-1]&&a[j]*f[b[j]+1]<mi)
     mi=a[j]*f[b[j]+1];
     f[i]=mi;  
     for(j=1;j<=k;j++)
     while(a[j]*f[b[j]+1]<=mi)
     b[j]++;
                     }
 
    cout<<f[n]<<endl;
 
    return 0;
    }