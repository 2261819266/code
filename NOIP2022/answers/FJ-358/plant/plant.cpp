#include<bits/stdc++.h>
using namespace std;
int n,m,c,f;
int a[1001][1001];
int d[1001][1001],r[1001][1001];
long long cntC=0,cntF=0;
const int mod=998244353;
void work()
{
//	freopen("plant.in","r",stdin);
//	freopen("plant.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&f);
	cntC=cntF=0;
	if(c==0)
	{
		printf("0 0\n");
		return;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%1d",&a[i][j]);
		}
	for(int j=1;j<=m;j++)
	{
		int p=n+1;
		for(int i=n;i>=1;i--)
		{
			if(a[i][j]==1)
				p=i;
			d[i][j]=p;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int p=m+1;
		for(int j=m;j>=1;j--)
		{
			if(a[i][j]==1)
				p=j;
			r[i][j]=p;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=j+2;k<=n;k++)
			{
				if(k>=d[j][i])
				{
					break;
				}
				cntC=(cntC+(r[j][i]-1-i)*(r[k][i]-1-i)%mod)%mod;
				cntF=(cntF+(r[j][i]-1-i)*(r[k][i]-1-i)%mod*(d[k][i]-1-k)%mod)%mod;
			}
		}
	}
	printf("%lld %lld\n",cntC,cntF*f);
	return;
}
int main()
{
	int T,id;	
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	for(int i=1;i<=T;i++)
	{
		work();
	}
	return 0;
}
