#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int MOD=998244353;
int n,m,c,f;
char s[N][N];
int p[N][N],q[N][N];
int pre[N][N],prep[N][N];
int ansc,ansf;
void init()
{
	for (int i=1;i<=n;++i)
	{
		for (int j=m;j>=1;--j)
		{
			if (s[i][j]=='1') continue;
			int sum=0;
			while (s[i][j]=='0' && j>=1) p[i][j]=sum++,j--;
		}
	}
	for (int j=1;j<=m;++j)
		for (int i=1;i<=n;++i)
			pre[i][j]=pre[i-1][j]+p[i][j];
	for (int j=1;j<=m;++j)
		for (int i=1;i<=n;++i)
			prep[i][j]=prep[i-1][j]+pre[i][j];
	for (int j=1;j<=m;++j)
	{
		for (int i=n;i>=1;--i)
		{
			if (s[i][j]=='1') continue;
			int sum=0;
			while (s[i][j]=='0' && i>=1) q[i][j]=sum++,i--;
		}
	}
}
void solve()
{
	if (c!=0)
	{
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=m;++j)
			{
				if (q[i][j]<1 || p[i][j]<=0) continue;
				ansc=(ansc+1ll*p[i][j]*(pre[i+q[i][j]][j]-pre[i+1][j])%MOD)%MOD;
			}
		}
	}
	if (f!=0)
	{
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=m;++j)
			{
				if (q[i][j]<2 || p[i][j]<=0) continue;
				int s=q[i][j]-1;
				int sum=(1ll*pre[i+s][j]*s%MOD+MOD-(prep[i+s-1][j]-prep[i][j])-pre[i+1][j])%MOD;
				ansf=(ansf+1ll*p[i][j]*((pre[i+s][j]-pre[i+1][j]+MOD)%MOD*q[i][j]%MOD-sum+MOD))%MOD;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	cin>>T>>id;
	while (T--)
	{
		ansc=ansf=0;
		cin>>n>>m>>c>>f;
		for (int i=1;i<=n;++i) cin>>(s[i]+1);
		init();
		solve();
		cout<<1ll*c*ansc%MOD<<' '<<1ll*f*ansf%MOD<<endl;
	}
	return 0;
}
