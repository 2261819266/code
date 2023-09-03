#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,res,st[N],par[N];
pair<int,int>edge[N];
int find(int x)
{
	if(par[x]==x)return x;
	else return par[x]=find(par[x]);
}
void dfs(int u)
{
	if(u>n)
	{
		int ans=0,flag=0;
		for(int i=1;i<=n;i++)
		{
			par[i]=i;
			if(st[i])flag=1;
		}
		if(!flag)return;
		for(int i=1;i<=m;i++)
		{
			int a=edge[i].first,b=edge[i].second;
			if(st[a]&&st[b])
			{
				a=find(a);
				b=find(b);
				if(a==b)continue;
				par[a]=b;
				ans++;
			}
		}
		res+=1<<(m-ans);
		return;
	}
	st[u]=1;
	dfs(u+1);
	st[u]=0;
	dfs(u+1);
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&edge[i].first,&edge[i].second);
	dfs(1);
	printf("%d",res);
	return 0;
}
