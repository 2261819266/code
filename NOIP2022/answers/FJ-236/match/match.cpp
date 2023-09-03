#include<bits/stdc++.h>
using namespace std;
int n,a[3005],b[3005],T,Q,mxa[3005][3005],mxb[3005][3005];
unsigned long long dp[3005][3005],w[3005][3005];
unsigned long long mod=0;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int j=1;j<=n;j++)
	{
		scanf("%d",&b[j]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			mxa[i][j]=max(mxa[i][j-1],a[j]);
			mxb[i][j]=max(mxb[i][j-1],b[j]);
		}
	}
	for(int j=n;j>=1;j--)
	{
		for(int i=j;i>=1;i--)
		{
			w[i][j]=w[i+1][j]+(unsigned long long)mxa[i][j]*1ll*mxb[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			dp[i][j]=dp[i][j-1];
			dp[i][j]+=w[i][j];
		}
	}
	scanf("%d",&Q);
	int l,r;
	while(Q--)
	{
		scanf("%d%d",&l,&r);
		printf("%lld\n",dp[l][r]);
	}
	return 0;
}

