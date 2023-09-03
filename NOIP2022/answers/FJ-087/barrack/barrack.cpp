#include<bits/stdc++.h>
#define R register
#define int long long
const int maxn=5*100005;
const int mod=1000000007;
using namespace std;
int n,m;
int u[maxn],v[maxn];
int ans;
inline int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
inline int ksm(int x,int y)
{
	int sum=1;
	while(y!=0)
	{
		if(y&1)
		sum=(sum*x)%mod;
		x=x*x%mod;
		y>>=1;
	}
	return sum%mod;
}
signed main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	for(R int i=1;i<=m;i++)
	u[i]=read(),v[i]=read();
	for(R int i=0;i<=n-1;i++)
	ans=(ans+((n-i)*ksm(2,n-i-1)%mod)*i%mod)%mod;
	printf("%lld\n",ans%mod);
	return 0;
}
/*
2 1
1 2
*/
