#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int T,id,n,m,cc,ff,a[1010][1010];
ll f1[1010][1010],f2[1010][1010];
ll temp,Vc,Vf;
vector<int> q[1010];
void solve()
{
	for(int j=1;j<m;j++)
	{
		temp=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][j]==1)
			{
				Vc=(Vc+temp)%mod;
				temp=0;
				q[j].clear();
			}
			if(f1[i][j]>=3&&f2[i][j]>1)
			{
				for(auto op:q[j])
				{
					if(op+1<i)
					{
						//printf("i=%d j=%d ",i,j);
						//printf("%lld %lld\n",f2[op][j]-1,f2[i][j]-1);
						temp=(temp+(f2[op][j]-1)*(f2[i][j]-1)%mod)%mod;
					}
				}
			}
			if(f2[i][j]>1)
			q[j].push_back(i);
			if(f1[i][j]>=3&&f1[i+1][j]>f1[i][j])
			Vf=(Vf+temp)%mod;
		}
		Vc=(Vc+temp)%mod;
	}
}
int main()
{
	char s[1010];
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d %d",&T,&id);
	while(T--)
	{
		cin>>n>>m>>cc>>ff;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)
			a[i][j]=s[j]-'0';
		}
		for(int i=1;i<=n;i++)
		for(int j=m;j>0;j--)
		{
			if(a[i][j]==0)
			{
				f1[i][j]=f1[i-1][j]+1;
				f2[i][j]=f2[i][j+1]+1;
			}
		}
		solve();
		printf("%lld %lld\n",(cc*Vc)%mod,(ff*Vf)%mod);
	}
	return 0;
}
