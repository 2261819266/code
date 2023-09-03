#include<bits/stdc++.h>
using namespace std;
const int N=1005,mod=998244353;
int n,m,c,f,h[N][N],l[N][N],cnt[N][N];
char a[N][N];
void work_CF()
{
	if(!c&&!f)
	{
		puts("0 0");
		return;
	}
	int res1=0,res2=0;
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=j+1;k<=m;k++)
			{
				if(!(h[i][k]-h[i][j-1]))cnt[i][j]++;
				else break;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=j+2;k<=n;k++)
			{
				if(!(l[i][k]-l[i][j-1]))
				{
					if(c)res1=(res1+(cnt[j][i]*cnt[k][i]%mod))%mod;
					if(f)
					{
						int ans=0;
						for(int p=k+1;p<=n;p++)
						{
							if(!(l[i][p]-l[i][k-1]))ans++;
							else break;
						}
						res2=(res2+ans*cnt[j][i]%mod*cnt[k][i]%mod)%mod;
					}
				}
				else break;
			}
		}
	}
	printf("%d %d\n",res1,res2);
}
void work()
{
	scanf("%d%d%d%d",&n,&m,&c,&f);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)h[i][j]=h[i][j-1]+a[i][j]-'0';
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)l[i][j]=l[i][j-1]+a[j][i]-'0';
	}
	work_CF();
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	scanf("%d%d",&T,&id);
	while(T--)work();
	return 0;
}
