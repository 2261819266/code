#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll n,m,x,y,ans,p[1000000];
ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	return f*x;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read();m=read();ans=1;
	p[1]=2;
	for(int i=2;i<=n;++i)p[i]=p[i-1]*2,p[i]%=mod;
	for(int i=1;i<=m;++i)x=read();y=read();
	for(int i=1;i<=n;++i)
	{
		ans+=(n-i+1)*p[n-i],ans%=mod;
	}
	printf("%lld",ans);
	return 0;
}
