#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll T,id,n,m,c,f;
ll a[1010][1010],lc[1010][1010],dc[1010][1010],pres[1010][1010],prem[1010][1010];
char s[1010];
void work()
{
	for(ll i=1;i<=n;i++)
		{
			if(a[i][m]==0) lc[i][m]=1;
			else lc[i][m]=0; 
			for(ll j=m-1;j>=1;j--)
			{
				if(a[i][j]==0) lc[i][j]=lc[i][j+1]+1;
				else lc[i][j]=0;
			}
		}
	for(ll j=1;j<=m;j++)
		{
			if(a[n][j]==0) dc[n][j]=1;
			else dc[n][j]=0;
			for(ll i=n-1;i>=1;i--)
			{
				if(a[i][j]==0) dc[i][j]=dc[i+1][j]+1;
				else dc[i][j]=0;
			}
		}
	for(int j=1;j<=m;j++)
	{
		prem[0][j]=0;
		pres[0][j]=0;
		for(int i=1;i<=n;i++)
		{
			pres[i][j]=(pres[i-1][j]+lc[i][j]-1)%mod;
			prem[i][j]=(prem[i-1][j]+(((lc[i][j]-1)*(dc[i][j]-1))%mod))%mod;
		}
			
	}
	return;
}
void solve()
{
	ll ansc=0,ansf=0;
	for(ll j=1;j<=m;j++)
		for(ll i=1;i<=n;i++)
			if(dc[i][j]>=3&&lc[i][j]>=2)
			{
				ansc=(ansc+(((lc[i][j]-1)*(pres[i+dc[i][j]-1][j]-pres[i+1][j]))%mod))%mod;
				ansf=(ansf+(((lc[i][j]-1)*(prem[i+dc[i][j]-1][j]-prem[i+1][j]))%mod))%mod;
			}
	ansc=(ansc*c)%mod;
	ansf=(ansf*f)%mod;
	printf("%lld %lld\n",ansc,ansf);
	return;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%lld%lld",&T,&id);
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&c,&f);
		if(c==0&&f==0)
		{
			printf("0 0\n");
			continue;
		}
		memset(a,0,sizeof(a));
		memset(lc,0,sizeof(lc));
		for(ll i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(ll j=1;j<=m;j++)
				a[i][j]=(s[j]-'0');
		}
		work();
		solve();
	}
	return 0;
}
