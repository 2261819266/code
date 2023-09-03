#include<iostream>
#include<cstring>
#include<cstdio>

const int P = 998244353;
const int N = 1005;
char s[N][N];
int dn[N][N],ri[N][N];
int dp[N][N];
int ansc,ansf;
int n,m,c,f,T,ID;

void init()
{
	memset(dp,0,sizeof(dp));
	ansc = ansf = 0;
}

int main()
{
	freopen("plant.in","r",stdin);
	freopen("palnt.out","w",stdout);
	scanf("%d %d",&T,&ID);
	while(T--)
	{
		init();
		scanf("%d %d %d %d",&n,&m,&c,&f);
		for(int i = 1;i <= n;++i)
			std::cin >> s[i] + 1;
		for(int i = 1;i <= n;++i)
			for(int j = 1;j <= m;++j)
				s[i][j] -= '0';
		for(int i = n;i;--i)
		{
			ri[i][m] =  s[i][m] ? m-1 : m;
			for(int j = m - 1;j;--j)
				ri[i][j] = s[i][j] ? j - 1 : ri[i][j+1];
		}
		for(int j = m;j;--j)
		{
			dn[n][j] = s[n][j] ? n-1 : n;
			for(int i = n - 1;i;--i)
				dn[i][j] = s[i][j] ? i - 1 : dn[i+1][j];
		}
		for(int i = 1;i <= n;++i)
		{
			for(int j = 1;j <= m;++j)
			{
				if(!s[i][j]) dp[i][j] = (dp[i-1][j] + ri[i][j] - j) % P;
				if(i > 2 && !s[i][j] && !s[i-1][j])
				{
					ansc = (ansc + 1ll * dp[i-2][j] * (ri[i][j] - j) % P) % P;
					ansf = (ansf + 1ll * dp[i-2][j] * (ri[i][j] - j) % P * (dn[i][j] - i) % P) % P;
				}
			}
		}
		printf("%d %d\n",ansc * c,ansf * f);
	}
}
