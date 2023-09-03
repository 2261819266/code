#include<bits/stdc++.h>
using namespace std;
long long a,b,m=1e9+7,c,d,e,g,out;
vector<long long>bs;

struct dsu
{
	long long jh[500001],si[500001],dsi;
	dsu()
	{
		dsi=500000;
		remake();
		return;
	}
	void remake()
	{
		for(long long i=1;i<=dsi;i++)
		{
			jh[i]=i;
			si[i]=1;
		}
		return;
	}
	long long find(long long a)
	{
		if(jh[a]==a)return a;
		return jh[a]=find(jh[a]);
	}
	long long same(long long a,long long b)
	{
		return find(a)==find(b);
	}
	void unio(long long a,long long b)
	{
		a=find(a);b=find(b);
		if(a==b)return;
		if(si[a]>si[b])swap(a,b);
		si[b]+=si[a];
		jh[a]=b; 
	}
}cs;

struct edge
{
	long long l,r;
}as[500001];

long long fpow(long long a,long long b,long long m)
{
	if(!b)return 1;
	if(b&1)return fpow(a,b-1,m)*a%m;
	long long c=fpow(a,b>>1,m);
	return c*c%m;
}

int main()
{
	ios::sync_with_stdio(0);
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>a>>b;
	for(long long i=1;i<=b;i++)
	{
		cin>>as[i].l>>as[i].r;
	}
	for(long long i=1;i<fpow(2,a,m);i++,g=0)
	{
		for(;bs.size();)bs.pop_back();
		for(long long j=i,k=1;j;j>>=1,k++)
		{
			if(j&1)bs.push_back(k);
		}
		for(long long j=1,can=1;j<=b;j++,cs.remake(),can=1)
		{
			for(long long k=1;k<=b;k++)
			{
				if(k!=j)cs.unio(as[k].l,as[k].r);
			}
			for(int k=1;k<bs.size();k++)
			{
				if(!cs.same(bs[0],bs[k]))
				{
					can=0;
					break;
				}
			}
			g+=can;
		}
		out+=fpow(2,g,m);
		out%=m;
	}
	cout<<out;
	return 0;
}
