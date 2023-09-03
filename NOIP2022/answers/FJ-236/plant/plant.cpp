#include<bits/stdc++.h>
using namespace std;
int read()
{
	char cc=getchar();
	int re=0;
	while(cc<'0' || cc>'9') cc=getchar();
	while(cc>='0' && cc<='9')
	{
		re=(re<<1)+(re<<3)+(cc^48);
		cc=getchar();
	}
	return re;
}
const int mod=998244353;
int n,m,ca,fa,a[1005][1005],id,T,h[1005][1005],flag,w[1005][1005],pl[1005],cu[1005][1005];
string s;
long long ans;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--)
	{
		n=read();
		m=read();
		ca=read();
		fa=read();
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			for(int j=1;j<=m;j++)
			{
				a[i][j]=s[j-1]-'0';
				h[i][j]+=a[i][j]+h[i-1][j];
				if(a[i][j]==1)
				{
					w[i][++pl[i]]=j;
					cu[i][j]=pl[i];
				}
				else
				{
					cu[i][j]=cu[i][j-1];
				}
				if(j==m) w[i][++pl[i]]=m+1;
			}
		}
		if(ca==0)
		{
			printf("0 ");
		}
		else
		{
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(a[j][i]==1) continue;
					for(int k=j+2;k<=n;k++)
					{
						if(h[k][i]-h[j][i]>=1)
						{
							flag=k;
							break;
						}
						int l=w[j][cu[j][i]+1]-i-1;
						int r=w[k][cu[k][i]+1]-i-1;
						ans+=l*r;
						ans%=mod;
					}
					if(flag)
					{
						j=flag-1;
						flag=0;
					}
				}
			}
			printf("%lld ",ans);
		}
		ans=0;
		if(fa==0)
		{
			printf("0\n");
			continue;
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j][i]==1) continue;
				for(int k=j+2;k<=n;k++)
				{
					for(int o=k+1;o<=n;o++)
					{
						if(h[o][i]-h[j][i]>=1)
						{
							flag=o;
							break;
						}
						int l=w[j][cu[j][i]+1]-i-1;
						int r=w[k][cu[k][i]+1]-i-1;
						ans+=l*r;
						ans%=mod;
					}
					if(flag) break;
				}
				if(flag)
				{
					j=flag-1;
					flag=0;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
