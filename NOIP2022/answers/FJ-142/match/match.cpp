#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll unsigned long long
using namespace std;
const ll maxn=2e5;
ll t,n,m,k,a[maxn],b[maxn];
ll Log[maxn],f[maxn][50],ff[maxn][50],q,ans,x,y;
ll g[3005][3005];
ll l,r;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	t=read();
	n=read();
	Log[0]=-1;
	for(ll i=1;i<=n;i++)Log[i]=Log[i/2]+1;
	for(ll i=1;i<=n;i++)a[i]=read(),f[i][0]=a[i];
	for(ll i=1;i<=n;i++)b[i]=read(),ff[i][0]=b[i];
    for(ll j=1;(ll)(1<<j)<=(ll)n;j++)
	  for(ll i=1;i<=n;i++) 
	  {
	  	f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	  	ff[i][j]=max(ff[i][j-1],ff[i+(1<<(j-1))][j-1]);
	  }
	q=read();
	memset(g,0,sizeof(g));
	while(q--)
	{
		l=read();r=read();ans=0;
		if(g[l][r])
		{
			printf("%llu",g[l][r]);
			continue;
		}
		for(ll i=l;i<=r;i++)
		  for(ll j=i;j<=r;j++)
		  {
		  	k=Log[j-i+1];
		  	ans+=max(f[i][k],f[j-(1<<k)+1][k])*max(ff[i][k],ff[j-(1<<k)+1][k]);
		  }
		 printf("%llu\n",ans);   
	}
	return 0;
}
