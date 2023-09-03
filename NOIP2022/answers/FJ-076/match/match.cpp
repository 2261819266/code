#include<iostream>
#include<cstdio>

typedef unsigned long long ll;
const int N = 3005;

ll ans,a[N],b[N];
ll dp[N][N];
int n;

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int Tase;
	scanf("%d %d",&Tase,&n);
	for(int i = 1;i <= n;++i)scanf("%llu",a+i);
	for(int j = 1;j <= n;++j)scanf("%llu",b+j);
	for(int i = 1;i <= n;++i)
	{
		ll m1=a[i],m2=b[i];
		for(int j = i;j <= n;++j)
		{
			m1 = std::max(m1,a[j]);
			m2 = std::max(m2,b[j]);
			dp[i][j] = m1 * m2;
		}
	}
	for(int i = 1;i <= n;++i)
	{
		for(int j = 1;j <=n;++j)
			dp[i][j] = dp[i][j] + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
	}
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%llu\n",dp[r][r] - dp[l-1][r] - dp[r][l-1] + dp[l-1][l-1]);
	}
}
/*
0 2
2 1
1 2
1
1 2
*/
