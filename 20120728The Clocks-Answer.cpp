/*
ID: haohanw
PROG: clocks
LANG: C++
*/

/*
Notice that the order in which we apply moves is irrelevant, 
and that applying a move four times is the same as applying it not at all.
Thus there are only 49 = 262144 move sequences that need to be tried,
 so we might as well just try them all.
We don't generate them shortest first, but looking at sequences of the same length, 
we generate the lesser ones before the greater ones, 
so we only need to keep track of the shortest working sequence we've found.
*/

#include<cstdio>
#include<cstring>

using namespace std;

const int INF=0x3f3f3f3f;
int clock[10],zx[10];

void add(char ch)
{
     int aa;
     aa=ch-'A'+1;
     clock[aa]+=3;
     if(clock[aa]>12) clock[aa]-=12;
}

void cut(char ch)
{
     int aa;
     aa=ch-'A'+1;
     clock[aa]-=3;
     if(clock[aa]<3) clock[aa]=12;
}

void a_change(int methon,int m_num)
{
	for(int i=1;i<=m_num;i++)
	{
		switch(methon)
		{
			case 1: add('A'); add('B'); add('D'); add('E'); break;
            case 2: add('A'); add('B'); add('C'); break;
            case 3: add('B'); add('C'); add('E'); add('F'); break;
            case 4: add('A'); add('D'); add('G'); break;
            case 5: add('B'); add('D'); add('E'); add('F'); add('H'); break;
            case 6: add('C'); add('F'); add('I'); break;
            case 7: add('D'); add('E'); add('G'); add('H'); break;
            case 8: add('G'); add('H'); add('I'); break;
            case 9: add('E'); add('F'); add('H'); add('I'); break;
        }
	}
}

void a_renew(int methon,int m_num)
{
	for(int i=1;i<=m_num;i++)
	{
		switch(methon)
		{
			case 1: cut('A'); cut('B'); cut('D'); cut('E'); break;
			case 2: cut('A'); cut('B'); cut('C'); break;
			case 3: cut('B'); cut('C'); cut('E'); cut('F'); break;
			case 4: cut('A'); cut('D'); cut('G'); break;
			case 5: cut('B'); cut('D'); cut('E'); cut('F'); cut('H'); break;
			case 6: cut('C'); cut('F'); cut('I'); break;
			case 7: cut('D'); cut('E'); cut('G'); cut('H'); break;
			case 8: cut('G'); cut('H'); cut('I'); break;
			case 9: cut('E'); cut('F'); cut('H'); cut('I'); break;
		}
	}
}

bool is_ok()
{
	for(int i=1;i<=9;i++)
		if(clock[i]!=12) return false;
	return true;
}

void work()
{
	int minn=INF,ans=0;
	for(int i9=0;i9<4;i9++)
	{
		a_change(9,i9);
		ans+=i9;
		for(int i8=0;i8<4;i8++)
		{
			a_change(8,i8);
			ans+=i8;
			for(int i7=0;i7<4;i7++)
			{
				a_change(7,i7);
				ans+=i7;
				for(int i6=0;i6<4;i6++)
				{
					a_change(6,i6);
					ans+=i6;
					for(int i5=0;i5<4;i5++)
					{
						a_change(5,i5);
						ans+=i5;
						for(int i4=0;i4<4;i4++)
						{
							a_change(4,i4);
							ans+=i4;
							for(int i3=0;i3<4;i3++)
							{
								a_change(3,i3);
								ans+=i3;
								for(int i2=0;i2<4;i2++)
								{
									a_change(2,i2);
									ans+=i2;
									for(int i1=0;i1<4;i1++)
									{
										a_change(1,i1);
										ans+=i1;
										if(is_ok())
										{
											if(ans<minn) minn=ans;
											zx[1]=i1;
											zx[2]=i2;
											zx[3]=i3;
											zx[4]=i4;
											zx[5]=i5;
											zx[6]=i6;
											zx[7]=i7;
											zx[8]=i8;
											zx[9]=i9;
										}
										a_renew(1,i1);
										ans-=i1;
									}
									a_renew(2,i2);
									ans-=i2;
								}
								a_renew(3,i3);
								ans-=i3;
							}
							a_renew(4,i4);
							ans-=i4;
						}
						a_renew(5,i5);
						ans-=i5;
					}
					a_renew(6,i6);
					ans-=i6;
				}
				a_renew(7,i7);
				ans-=i7;
			}
			a_renew(8,i8);
			ans-=i8;
		}
		a_renew(9,i9);
		ans-=i9;
	}
	int flag=0;
	for(int i=1;i<=9;i++)
		for(int j=1;j<=zx[i];j++)
		{
			flag++;
			if(flag<minn) printf("%d ",i);
			else printf("%d\n",i);
		}
}

int main()
{
	freopen("clocks.in","r",stdin); freopen("clocks.out","w",stdout);
	for(int i=1;i<=9;i++) scanf("%d",&clock[i]);
	work();
	return 0;
}
