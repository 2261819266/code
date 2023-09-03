#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long n,m,he[1000001],nxt[1000001],vtx[1000001],idx;
bool fl;
void add(long long x,long long y)
{
	idx++;
	nxt[idx]=he[x];
	he[x]=idx;
	vtx[idx]=y;
}
long long pow(long long x)
{
	if(x==0)
	{
		return 1;
	}
	long long num=1;
	while(x--)
	{
		num*=2;
		num%=mod;
	}
	return num%mod;
}
long long dfs(long long u)
{
	long long num=1;
	for(long long i=he[u];~i;i=nxt[i])
	{
		long long j=vtx[i];
		num*=(dfs(j)+1);
		num%=mod;
	}
	return num;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=m;i++)
	{
		long long x,y;
		cin>>x>>y;
		if(abs(x-y)!=1)
		{
			fl=1;
		}
		add(x,y);
		add(y,x);
	}
	if(n==1)
	{
		cout<<1<<endl;
	}
	else if(n==2)
	{
		cout<<5<<endl;
	}
	else
	{
		if(!fl)
		{
			long long x=pow(n-3),y=n+3;
			x=x*(n%mod);
			x%=mod;
			x=x*(y%mod);
			x%=mod;
			cout<<x<<endl;
		}
		else
		{
			cout<<dfs(1)<<endl;
		}
	}
	return 0;
}
