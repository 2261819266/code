#include<bits/stdc++.h>
//#define int long long
#define rint register int
#define f(X,Y,Z) for(int X=Y;X<=Z;++X)
using namespace std;
const int maxn=5e5+2,mod=1e9+7;
int n,m,u[maxn<<1],v[maxn<<1];
int fa[maxn],vis[maxn];
int A[maxn]={0,2};
int ans;
int find(int x)
{
	return fa[x]==x? x:find(fa[x]);
}
void dfs(int sf,int p,int city,bool flag)
{
	if(p>m)
	{
		if(flag) ans=(ans+A[city]-1+n-city)%mod;
		return ;
	}
	
	dfs(sf,p+1,city,flag);
	
	rint fu=fa[u[p]],fv=fa[v[p]];
	if(sf==fa[v[p]]||sf==fa[u[p]])
	{
		flag=true;
	}
	fa[v[p]]=fa[u[p]]=0;
	
	city+=(!vis[u[p]])+(!vis[v[p]]);
	rint tvu=vis[u[p]],tvv=vis[v[p]];
	vis[u[p]]=vis[v[p]]==true;
	
	dfs(sf,p+1,city,flag);
	
//	fa[find(fa[v[p]])]=v[p],
	vis[u[p]]=tvu,vis[v[p]]=tvv;
	fa[v[p]]=fv,fa[u[p]]=fu;
	
	return ;
}
signed main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	f(i,1,n) fa[i]=i;
	f(i,2,n) A[i]=(A[i-1]<<1)%mod;
	f(i,1,m)
	{
		cin>>u[i]>>v[i];
	}
	dfs(0,2,0,false);
	
	fa[v[1]]=fa[u[1]]=0,
	vis[u[1]]=vis[v[1]]=true,
	dfs(u[1],2,2,true);
	
	cout<<ans+n<<"\n";
	return 0;
}
/*
4 4
1 2
2 3
3 1
1 4

3 2
1 2
2 3

0:
1
2
3

1:
1
2
3
1 2

2:
1
2
3
2 3

1 2:
1
2
3
1 2
2 3
1 3
1 2 3
*/
