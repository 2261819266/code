#include<bits/stdc++.h>
#define int long long
using namespace std;
long long read()
{
	long long res=0,f=0;char c;
	while(((c=getchar())<'0'||c>'9')&&c!='-');
	if(c=='-')f=1;else res=c-'0';
	while((c=getchar())>='0'&&c<='9')res=res*10+c-'0';
	return f?-res:res;
}
const int mod=1e9+7,N=2.5e5+10;
int s,n,m,ans,f[N],p[N],cnt,u[N],v[N],fl,S1,S2,t[N];
int pw(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod;b>>=1;
	}
	return res;
}
int fd(int x)
{
	return x==f[x]?x:f[x]=fd(f[x]);
}
bool check(int s1,int s2)
{
	cnt=0;
	for(int i=0;i<n;i++)if((1<<i)&s1)p[++cnt]=i+1;
	if(cnt<=1)return 1;
	for(int j=0;j<m;j++)
	{
		if(((s2>>j)&1)==1)continue;
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=0;i<m;i++)
		{
			if(i==j)continue;
			int fx=fd(u[i]),fy=fd(v[i]);
//			if(s1==3&&s2==1)printf("%d %d\n",fx,fy);
			if(fx^fy)f[fx]=fy;
		}
		for(int i=1;i<cnt;i++)
			if(fd(p[i])^fd(p[i+1]))
			{
//				printf("%d %d %d %d %d %d\n",s1,s2,p[i],p[i+1],f[p[i]],f[p[i+1]]);
				return 0;
			}
	}
	return 1;
}
signed main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read();m=read();
	for(int i=0;i<m;i++)
	{
		u[i]=read();v[i]=read();
		if(abs(u-v)!=1)fl=1;
	}
	if(m==n-1&&fl!=1)
	{
		s=pw(2,n-2);
		for(int i=1;i<=n-1;i++)ans=(ans+n-i)%mod;
		ans=ans*s%mod;
		ans=(ans+s+s)%mod;
		printf("%lld ",ans);
		return 0;
	}
	S1=(1<<n)-1;
	S2=(1<<m)-1;
	for(int i=1;i<=S1;i++)
	{
		for(int j=0;j<=S2;j++)
		{
			ans=(ans+check(i,j))%mod;
		}
	}
	printf("%d ",ans);
	return 0;
}
/*
4 4
1 2
2 3
3 1
1 4
*/
