/*
ID: haohanw1
PROG: shopping
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

struct BASKET
{
	int item[6];
	int money;
	BASKET* next;
};

struct PACKET
{
	int item;
	int quantity;
	PACKET* next;
};

struct GOAL
{
	int item;
	int quantity;
	int price;
};

int Judge(BASKET* b, GOAL goal[], int max)
{
	int i;
	bool equal=true;
	for (i=1;i<=max;i++)
	{
		if (b->item[i]>goal[i].quantity)
			return 3;
		else if (b->item[i]<goal[i].quantity)
			equal = false;
	}
	if (equal)
		return 2;
	else
		return 1;
}

bool JudgeDuplicate(BASKET* basket, BASKET* bnew, int max)
{
	BASKET* p=basket;
	bool duplicate=false;
	for (;p!=NULL;p=p->next)
	{
		duplicate=true;
		for (int i=1;i<=max;i++)
		{
			if (bnew->item[i]!=p->item[i])
			{
				duplicate=false;
			}
		}
		if (bnew->money<p->money)
			duplicate=false;
		if (duplicate==true)
			return true;
	}
	return false;
}


int main()
{
	ifstream in ("shopping.in");
	ofstream out ("shopping.out");
	PACKET* offer[100];
	PACKET* p;
	int s, i, j, b;
	BASKET* basket=NULL;
	GOAL goal[6];
	for (i=0;i<=99;i++)
	{
		offer[i]=NULL;
	}
	int map[1000]={0};
	in>>s;
	for (i=1;i<=s;i++)  //read in offer[i]->{-1, reduced price}->{item, quantity}->{tiem, quantity}
	{
		in>>b;
		for (;b>=1;b--)
		{
			int m, n;
			in>>m>>n;
			p = new PACKET;
			p->item=m;
			p->quantity=n;
			p->next=offer[i];
			offer[i]=p;
		}
		in>>b;
		p=new PACKET;
		p->item=-1;
		p->quantity=b;
		p->next=offer[i];
		offer[i]=p;
	}
	in>>b;
	for (i=1;i<=b;i++)    //read in goal
	{
		int x, y, z;
		in>>x>>y>>z;
		goal[i].item=x;
		goal[i].price=z;
		goal[i].quantity=y;
		map[x]=i;
	}
	basket = new BASKET;
	for (i=1;i<=5;i++)
	{
		basket->item[i]=0;
	}
	basket->money=0;
	basket->next=NULL;
	BASKET* bt = basket;
	BASKET* bnew=NULL;
	bool finish=false;
	int minPrice=25000;
	if (b==0)
	{
		minPrice=0;
	}
	int count=0;
	while (basket!=NULL)
	{
		/*if (count%10000==0)
			cout<<count<<endl;
		count++;*/
		//////////////////////////////////////////
		/*for (i=1;i<=5;i++)
		{
			cout<<basket->item[i]<<"\t";
		}
		cout<<endl<<basket->money<<endl;
		cout<<"-----------------------"<<endl;*/
		//////////////////////////////////////////
		for (i=1;i<=s;i++)
		{
			bnew = new BASKET;
			for (j=1;j<=5;j++)
			{
				bnew->item[j]=basket->item[j];
			}
			bnew->money=basket->money;
			for (p=offer[i];p!=NULL;p=p->next)
			{
				if (p->item==-1)
				{
					bnew->money+=p->quantity;
				}
				else
				{
					bnew->item[map[p->item]]+=p->quantity;
				}
			}
			switch (Judge(bnew,goal, b))
			{
			case 1://add
				if (!JudgeDuplicate(basket,bnew,b))
				{
					bnew->next=bt->next;
					bt->next=bnew;
					bt=bt->next;
				}
				break;
			case 2://find
				if (minPrice>bnew->money)
				{
					minPrice=bnew->money;
				}
				delete bnew;
				break;
			case 3://drop
				delete bnew;
				break;
			}
		}
		for (i=1;i<=b;i++)
		{
			bnew = new BASKET;
			for (j=1;j<=5;j++)
			{
				bnew->item[j]=basket->item[j];
			}
			bnew->money=basket->money;
			bnew->item[i]+=1;
			bnew->money+=goal[i].price;
			switch (Judge(bnew,goal, b))
			{
			case 1://add
				if (!JudgeDuplicate(basket,bnew,b))
				{
					bnew->next=bt->next;
					bt->next=bnew;
					bt=bt->next;
				}
				break;
			case 2://find
				if (minPrice>bnew->money)
				{
					minPrice=bnew->money;
				}
				delete bnew;
				break;
			case 3://drop
				delete bnew;
				break;
			}
		}
		bnew = basket;
		basket=basket->next;
		delete bnew;
	}
	out<<minPrice<<endl;
	return 0;
}