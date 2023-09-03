#include <bits/stdc++.h>
using namespace std;

const int N=2e3,mod=998244353;

int n,l,c,f;

int g[N][N];

int T,id;int u[N];						





int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d %d",&T,&id);
	while (T--)
	{
		scanf("%d %d %d %d",&n,&l,&c,&f);
		for (int i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			for (int j=1;j<=l;j++)
			{
				g[i][j]=(s[j-1]-'0');
			}
		}
	
		int ansc=0,ansf=0; 
		for (int j=1;j<=l;j++)
		{
			for (int i=1;i<=n;i++)
			{
				int te=j+1;
				if (u[i]>0) continue;
				u[i]=0;
				while (te<=l && g[i][te]!=1) u[i]++,te++;
			}
			int res=0;
			for (int k=n-2;k>=1;k--)
			{
				if (g[k][j]==1 || g[k+1][j]==1 || g[k+2][j]==1)
				{
					res=0;
					continue;
				}
				res+=u[k+2];
				ansc=(1ll*ansc+1ll*res*u[k])%mod;
			}
			for (int i=1;i<=n;i++) u[i]--;
		}
		memset(u,0,sizeof u);
		for (int j=1;j<=l;j++)
		{
			for (int i=1;i<=n;i++)
			{
				int te=j+1;
				if (u[i]>0) continue;
				u[i]=0;
				while (te<=l && g[i][te]!=1) u[i]++,te++;
			}
			long long res=0,res2=0;
			for (int k=n-3;k>=1;k--)
			{
				if (g[k][j]==1 || g[k+1][j]==1 || g[k+2][j]==1 || g[k+3][j]==1)
				{
					res=0,res2=0;
					continue;
				}
				res2++,res=(res+res2*u[k+2])%mod;
				ansf=(1ll*ansf+1ll*res*u[k])%mod;
			}
			for (int i=1;i<=n;i++) u[i]--;
		}
		cout<<(1ll*c*ansc)%mod<<" "<<(1ll*f*ansf)%mod<<endl;
	}
	return 0;
}