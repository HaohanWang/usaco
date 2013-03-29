/*
ID:haohanw1
PROG: rect1
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

typedef struct cc
{
	int llx;
	int lly;
	int urx;
	int ury;
	int area;
	cc* next;
	bool pos;
} square;

square* Assign(square a, int llx, int lly, int urx, int ury, bool p)
{
	a.llx=llx;
	a.lly=lly;
	a.urx=urx;
	a.ury=ury;
	a.next=NULL;
	a.pos=p;
	a.area=(ury-lly)*(urx-llx);
	return &a;
}

int subJudge(int a1, int a2, int b1, int b2)
{
	if (a1<b1)
	{
		if (a2<b2)
			return 1;
		else
			return 2;
	}
	else
	{
		if (a2<b2)
			return 3;
		else
			return 4;
	}
}

int Judge(square a, square b)
{
	int allx=a.llx, ally=a.lly,aurx=a.urx,aury=a.ury;
	int bllx=b.llx, blly=b.lly,burx=b.urx,bury=b.ury;
	if (allx>burx||aurx<bllx||ally>bury||aury<blly)
		return 0;
	else 
		return (4-subJudge(allx,aurx,bllx,burx))*4+subJudge(ally,aury,blly,bury);
}

int main()
{
	ifstream in ("rect1.in");
	ofstream out ("rect1.out");
	int A, B, N;
	int llx, lly, urx, ury, color;
	square* Square[2501];
	square* Tail[2501];
	square *a;
	square *p;
	square *q;
	int i;
	for (i=0;i<=2500;i++)
	{
		Square[i]=NULL;
		Tail[i]=NULL;
	}
	in>>A>>B>>N;
	a=new square;
	Square[1]=Assign(*a,0,0,A,B,1);
	Tail[1]=Square[1];
	bool D=true;
	for (;N>=1;N--)
	{
		in>>llx>>lly>>urx>>ury>>color;
		a=new square;
		a=Assign(*a,llx,lly,urx,ury,1);
		for (i=1;i<=2500;i++)
		{
			//cout<<i<<endl;
			if (Square[i]!=NULL&&color!=i)
			{
				for (p=Square[i];p!=NULL&&p->pos==true;p=p->next)
				{
					//q=Square[i];
					if (p->pos==true)
					{
						int allx=a->llx, ally=a->lly,aurx=a->urx,aury=a->ury;
						int pllx=p->llx, plly=p->lly,purx=p->urx,pury=p->ury;
						D=true;
						//cout<<"-------"<<endl;
						switch(Judge(*a,*p))
						{
						case 0:
							//delete q;
							D=false;
							break;
						case 1:
							q=new square;
							q=Assign(*q,allx,plly,purx,aury,0);
							break;
						case 2:
							q=new square;
							q=Assign(*q,allx,plly,purx,pury,0);
							break;
						case 3:
							q=new square;
							q=Assign(*q,allx,ally,purx,aury,0);
							break;
						case 4:
							q=new square;
							q=Assign(*q,allx,ally,purx,pury,0);
							break;
						case 5:
							q=new square;
							q=Assign(*q,allx,plly,aurx,aury,0);
							break;
						case 6:
							q=new square;
							q=Assign(*q,allx,plly,aurx,pury,0);
							break;
						case 7:
							q=new square;
							q=Assign(*q,allx,ally,aurx,aury,0);
							break;
						case 8:
							q=new square;
							q=Assign(*q,allx,ally,aurx,pury,0);
							break;
						case 9:
							q=new square;
							q=Assign(*q,pllx,plly,purx,aury,0);
							break;
						case 10:
							q=new square;
							q=Assign(*q,pllx,ally,purx,aury,0);
							break;
						case 11:
							q=new square;
							q=Assign(*q,pllx,plly,purx,pury,0);
							break;
						case 12:
							q=new square;
							q=Assign(*q,pllx,ally,purx,pury,0);
							break;
						case 13:
							q=new square;
							q=Assign(*q,pllx,plly,aurx,aury,0);
							break;
						case 14:
							q=new square;
							q=Assign(*q,pllx,plly,aurx,pury,0);
							break;
						case 15:
							q=new square;
							q=Assign(*q,allx,plly,aurx,aury,0);
							break;
						case 16:
							q=new square;
							q=Assign(*q,allx,plly,aurx,pury,0);
							break;
						}
						if(D)
						{
							Tail[i]->next=q;
							Tail[i]=Tail[i]->next;
						}
					}
				}
			}
		}
		//a=Assign(*a,llx,lly,urx,ury,1);
		a->next=Square[color];
		Square[color]=a;
	}
	int area;
	for (i=1;i<=2500;i++)
	{
		area=0;
		if (Square[i]!=NULL)
		{
			for (p=Square[i];p!=NULL;p=p->next)
			{
				area+=p->area*p->pos;
			}
			out<<i<<" "<<area<<endl;
		}
	}
	//system("pause");
	return 0;
}