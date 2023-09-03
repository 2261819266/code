#include<bits/stdc++.h>
using namespace std;
const int N=1010,P=998244353;
int G[N][N];
int F[N][N];
long long dp[N][3];
char s[N];
int n,m,c,f;
long long qpow(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%P;
		a=a*a%P,b>>=1;
	}
	
	return ans;
}
int solve()
{
	long long inv2=qpow(2,P-2);
	memset(G,0,sizeof G);
	memset(F,0,sizeof F);
	scanf("%d%d%d%d",&n,&m,&c,&f);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;++j)G[i][j]=s[j]-48;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=m;j;--j)
			if(G[i][j])F[i][j]=0;
			else F[i][j]=F[i][j+1]+1;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			--F[i][j];
//	for(int i=1;i<=n;++i,puts(""))
//		for(int j=1;j<=m;++j)
//			printf("%3d",F[i][j]);
	long long ans=0;
	for(int j=1;j<=m;++j)
	{
		long long s=0,s2=0;
		for(int i=1;i<=n;++i)
		if(G[i][j])
		{
			ans=(ans+(s*s%P-s2+P)%P*inv2)%P;
			s=0,s2=0;
//			cerr<<i<<" "<<j<<endl;
		}
		else s=(s+F[i][j])%P,s2=(s2+1ll*F[i][j]*F[i][j])%P;
			ans=(ans+(s*s%P-s2+P)%P*inv2)%P;
	}
	for(int i=1;i<n;++i)
		for(int j=1;j<=m;++j)	
			if(!G[i][j]&&!G[i+1][j])ans=(ans-1ll*F[i][j]*F[i+1][j]%P+P)%P;
	long long ans2=0;
	dp[0][0]=1;
	for(int j=1;j<=m;++j)
	{
		for(int i=1,top=0;i<=n;++i)
			if(G[i][j])
			{
				top=0;
			}
			else
			{
				++top;
				dp[top][0]=dp[top-1][0];
				dp[top][1]=(dp[top-1][1]+dp[top-1][0]*F[i][j])%P;
				dp[top][2]=(dp[top-1][2]+dp[top-1][1]*F[i][j])%P;
				ans2=(ans2+dp[top][2])%P;
			}
	}
//	cerr<<ans2<<endl;
	for(int j=1;j<=m;++j)
		for(int i=n,w=0;i;--i)
		{
			if(G[i][j])w=0;
			else ++w;
			if(w>=2)ans2=(ans2-1ll*F[i][j]*F[i+1][j]%P*(w-1)%P+P)%P;
		}
	printf("%lld %lld\n",ans*c%P,(ans2-ans+P)%P*f%P);
	return 0;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,testid;
	scanf("%d%d",&T,&testid);
	while(T--)solve();
	return 0;
}
