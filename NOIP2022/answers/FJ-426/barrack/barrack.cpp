#include<bits/stdc++.h>
using namespace std;
int n,m;
struct data
{
    int l,r,lcut,rcut;
    bool b;
    bool open;
}mapp[1000010];
bool hadps[500010];
long long sum;
bool s;
void findr(int a,int b)
{
	if(a==b)
	{
		s=1;
		return;
	}
	for(int i=1;i<=m;i++)
	{
		if((mapp[i].l==a||mapp[i].r==a)&&mapp[i].open==1)
		{
			mapp[i].open=0;
			int t;
			if(mapp[i].l==a)
			{   
			    t=hadps[mapp[i].r];
				if(t==0)
				{
				    hadps[mapp[i].r]=1;
				    sum++;
				}
				findr(mapp[i].r,b);
				hadps[mapp[i].r]=t;
				if(t==0)
				{
				    sum--;
				}
			}
			else
			{
				t=hadps[mapp[i].l];
				if(t==0)
				{
				    hadps[mapp[i].l]=1;
				    sum++;
				}
				findr(mapp[i].l,b);
				hadps[mapp[i].l]=t;
				if(t==0)
				{
				    sum--;
				}
			}
			mapp[i].open=1;
		}
	}
	return;
}
int mmmm(long long k)
{
	long long oo=1;
	for(int i=0;i<k;i++)
	{
		oo*=2;
		oo%=1000000007;
	}
	return oo;
}
int mmm(long long k1,long long k2)
{
	for(long long i=1;i<=k2;i++)
	{
		k1+=k1;
		k1%=1000000007;
	}
	return k1;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>mapp[i].l>>mapp[i].r;
	}
	for(int i=1;i<=m;i++)
	{
		mapp[i].open=0;
		findr(mapp[i].l,mapp[i].r);
		mapp[i].b=s;
		mapp[i].lcut=sum;
		mapp[i].rcut=n-sum;
		mapp[i].open=1;
	}
	for(int i=1;i<=m;i++)
	{
		if(mapp[i].lcut!=0)
		{
			sum+=(long long)(mmm(mmm((mmmm(mapp[i].lcut)-1),(mmmm(mapp[i].rcut)-1)),mmmm(n-1)));
			sum%=1000000007;
		}
	}
	sum=(mmm(mmmm(n),mmmm(m))+1000000007-sum)%1000000007;
	cout<<sum;
 	return 0;
}
//omg i cant finish it
