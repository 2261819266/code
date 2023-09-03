#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5;
const int mod=998244353;
int t,id;
int n,m,c,f;
int a[N][N];
int sum1[N][N],sum2[N][N];
int vc=0,vf=0;
void init()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			sum1[i][j]=sum1[i][j-1]+a[i][j];
		}
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
		{
			sum2[i][j]=sum2[i-1][j]+a[i][j];
		}
			
}


void solve2()
{
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=n-2;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				if(sum2[j][k]-sum2[i-1][k]==0)
				{
					int xt=0,yt=0;
					for(int o=k+1;o<=m;o++)
					{
						if(sum1[i][o]-sum1[i][k-1]==0) xt=(xt+1)%mod;
						if(sum1[j][o]-sum1[j][k-1]==0) yt=(yt+1)%mod;
					}
					vc=((vc%mod)+(xt%mod*yt%mod)%mod)%mod;
				}
			}
		}
	}
}

void solve3()
{
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=n-2;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				if(sum2[j][k]-sum2[i-1][k]==0)
				{
					int xt=0,yt=0,zt=0;
					for(int o=k+1;o<=m;o++)
					{
						if(sum1[i][o]-sum1[i][k-1]==0) xt=(xt+1)%mod;
						if(sum1[j][o]-sum1[j][k-1]==0) yt=(yt+1)%mod;
					}
					for(int o=j+1;o<=n;o++)
					{
						if(sum2[o][k]-sum2[j][k]==0) zt=(zt+1)%mod;
						else break;
					}
					vf=((vf%mod)+(xt%mod*yt%mod*zt%mod)%mod)%mod;
				}
			}
		}
	}
}


void solve()
{
	if(c==0 && f==0) { printf("0 0\n"); return; }
	if(n==3 && m==2)
	{
		if(!sum1[1][2] && !sum1[2][1] && !sum1[3][2]) printf("%d 0\n",c%mod);
		else printf("0 0\n");
		return;
	}
	if(n==4 && m==2)
	{
		if(!sum1[1][2] && !sum1[2][1] && !sum1[3][2]) vc=(vc+1)%mod;
		if(!sum1[1][2] && !sum1[2][1] && !sum1[3][1] && !sum1[4][2]) vc=(vc+1)%mod;
		if(!sum1[1][2] && !sum1[2][1] && !sum1[3][2] && !sum1[4][1]) vf=(vf+1)%mod;
		printf("%d %d\n",((c%mod)*(vc%mod))%mod,((f%mod)*(vf%mod))%mod);
		return;
	}
	
	solve2();
	solve3();
	printf("%d %d\n",((c%mod)*(vc%mod))%mod,((f%mod)*(vf%mod))%mod);
}
int main()
{
//	freopen("plant.in","r",stdin);
//	freopen("plant.out","w",stdout);
	
	scanf("%d%d",&t,&id);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++)
		{
			string s; cin>>s;
			for(int j=0;j<m;j++)
			{
				if(s[j]=='0') a[i][j+1]=0;
				else a[i][j+1]=1;
			}
		}
		init();
		solve();
	}
	
	return 0;
}
