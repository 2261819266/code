#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll; 
inline int read()
{
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		g*=10;
		g+=ch-'0';
		ch=getchar();
	}
	return f*g;
}
vector<int > e[500005];
ll lgg[500005];
int dis[500005];
int fa[500005][25];


int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n=read(),m=read();
	if(m==n-1)
	{
		int flg=1;
		for(int i=1;i<=m;i++)
		{
			int u=read(),v=read();
			if(v!=u+1)flg=0;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(flg==1)
		{
			lgg[0]=1;
			for(int i=1;i<=n;i++)
			{
				lgg[i]=lgg[i-1]*2;
				lgg[i]%=mod;
			}
			if(n==1)
			{
				printf("1\n");
				return 0;
			}
			if(n==2)
			{
				printf("5\n");
				return 0;
			}
			else
			{
				ll ans=0;
				ans+=n*lgg[n-1];
				ans%=mod;
				ans+=n*(n-1)%mod*lgg[n-3]%mod;
				ans%=mod;
				printf("%lld",ans);
				return 0;
			}
		//	ll ans=n;
		}
		else
		{
	//		dfs(1,0);
		}
	}
	
	
	return 0;
 } 
