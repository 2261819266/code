#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e3+100;
const ll mod=998244353;
ll a[M][M],b[M][M],d[M][M],cnt,n,m,id,T,C,F,ansc,ansf;
char s[M];
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
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read();id=read();
	while(T--)
	{
		ansc=0;ansf=0;
		memset(d,0,sizeof(d));
		memset(b,0,sizeof(b));
		n=read();m=read();C=read();F=read();
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;++j)
			a[i][j]=s[j]-48;
		}
		for(int j=1;j<=m;++j)
		for(int i=n;i>=1;--i)
		if(!a[i][j]&&a[i+1][j]==0&&i!=n)
		b[i][j]=b[i+1][j]+1;
		else b[i][j]=0;
		for(int i=1;i<=n;++i)
		for(int j=m;j>=1;--j)
		if(!a[i][j]&&!a[i][j+1]&&j!=m)
		d[i][j]=d[i][j+1]+1;
		else d[i][j]=0;
		for(int j=1;j<=m;++j)
		{
			cnt=0;
			for(int i=3;i<=n;++i)
			{
				if(!a[i-2][j]&&!a[i-1][j]&&!a[i][j])cnt+=d[i-2][j],cnt%=mod;
				else cnt=0;
				ansc+=(cnt*d[i][j])%mod;ansc%=mod;
			}
		}
		for(int j=1;j<=m;++j)
		{
			cnt=0;
			for(int i=3;i<n;++i)
			{
				if(!a[i-2][j]&&!a[i-1][j]&&!a[i][j])cnt+=d[i-2][j],cnt%=mod;
				else cnt=0;
				ansf+=(cnt*d[i][j]%mod*b[i][j]%mod),ansf%=mod;
			}
		}
		ansc=(C*ansc+mod)%mod;ansf=(F*ansf+mod)%mod;
		printf("%lld %lld\n",ansc,ansf);
	}
	return 0;
}
