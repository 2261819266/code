#include<bits/stdc++.h>
#define mod 998244353
#define N 1010
using namespace std;
int T,n,m,jy,ans;
int cnt,vis[N],f[N],p[N][N],x[N],y[N];
vector<int> g[N];
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
void dfs(int x)
{
	if(f[x]==1)cnt++;
	vis[x]=1;
	for(auto y:g[x])
	{
//		cout<<x<<" "<<y<<endl;
		if(p[x][y]==1&&vis[y]==0)dfs(y);
	}
}
int judge()
{
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]==1)
		{
			cnt=0;
			dfs(i);
//			cout<<cnt<<endl;
			if(cnt==jy)return 1;
			else return 0;
		}
	}
	return 1;
}
void dfs(int a,int b)
{
	ans+=judge();
//	for(int i=1;i<=n;i++)cout<<p[1][2]<<" ";
	if(a==n&&b==m)return;
	for(int i=a+1;i<=n;i++)
	{	
		for(int j=b+1;j<=m;j++)
		{
			p[x[j]][y[j]]=1,p[y[j]][x[j]]=1,f[i]=1,jy++,dfs(i,j),p[x[j]][y[j]]=0,p[y[j]][x[j]]=0,f[i]=0,jy--;
		}
		
	}
	for(int i=a+1;i<=n;i++) f[i]=1,jy++,dfs(i,b),f[i]=0,jy--;
	for(int j=b+1;j<=m;j++) p[x[j]][y[j]]=1,p[y[j]][x[j]]=1,dfs(a,j),p[x[j]][y[j]]=0,p[y[j]][x[j]]=0;
}
signed main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int u,v,i=1;i<=m;i++)
	{
		cin>>u>>v;
		x[i]=u,y[i]=v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			p[x[j]][y[j]]=1,p[y[j]][x[j]]=1,f[i]=1,jy++,dfs(i,j),p[x[j]][y[j]]=0,p[y[j]][x[j]]=0,f[i]=0,jy--;
	}
	cout<<ans+n;
	
}
