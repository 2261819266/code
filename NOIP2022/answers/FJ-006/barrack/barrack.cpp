#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
typedef long long ll;
const int p=1e9+7;
const int MAXN=5e5+5;
const int MAXM=1e6+5;
int n,m,t,cnt,ans;
int head[MAXN],dfn[MAXN],low[MAXN],c[MAXN],d[MAXN],s[MAXN];
ll f[MAXN][2][2];//子节点有无军营；有军营且未与父节点相连 
bool vis[MAXN];
struct edge
{
	int to,next;
	bool b;
}e[MAXM*2];
vector<int> edcc[MAXN],v[MAXN];
int read()
{
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		s=s*10+c-'0';
		c=getchar();
	}
	return f*s;
}
void insertt(int u,int v,int num)
{
	e[num].to=v;
	e[num].next=head[u];
	head[u]=num;
}
ll qpow(int x,int k)
{
	if(k==0)
		return 1;
	ll s=qpow(x,k/2);
	s=s*s%p;
	if(k&1)
		s=s*x%p;
	return s;
}
void tarjan(int x,int in_e)
{
	dfn[x]=low[x]=++t;
	for(int i=head[x];i;i=e[i].next)
	{
		if((i^1)==in_e)
			continue;
		int y=e[i].to;
		if(!dfn[y])
		{
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(low[y]>dfn[x])
				e[i].b=e[i^1].b=true;
		}
		else
			low[x]=min(low[x],dfn[y]);
	}
}
void dfs(int rt,int x)
{//cout<<rt<<endl;
	edcc[x].push_back(rt);
	c[rt]=x;
	vis[rt]=true;
	for(int i=head[rt];i;i=e[i].next)
	{
		if(e[i].b)
			continue;
		d[x]++;
		if(!vis[e[i].to])
			dfs(e[i].to,x);
	}
}//f[i][0]=2^(e[i]+1)*pi(f(son,0)) f[i][1]=2^e[i]*(2^v[i]*pi(f(son,0)+f(son,1))-pi(f(son,0)))
void dp(int rt,int fa)
{//cout<<rt;
	int ss=v[rt].size();
	ll x=1,y=1;
	for(int i=0;i<ss;i++)
	{ 
		int u=v[rt][i];
		if(u==fa)
			continue;
		dp(u,rt);
		x=f[u][0][1]*x%p;
		y=(f[u][0][1]+f[u][1][1])%p*y%p;//cout<<i<<endl;
	}
	if(rt^1)
		f[rt][1][0]=(qpow(2,s[rt])-1+p)%p*y%p;
	for(int i=0;i<ss;i++)
	{
		int u=v[rt][i];
		f[rt][1][0]=(f[rt][1][0]+f[u][1][0]*x%p*qpow(f[u][0][1],p-2)%p)%p;
	}
	f[rt][1][0]=f[rt][1][0]*qpow(2,d[rt])%p;
	f[rt][0][1]=x*qpow(2,d[rt]+1)%p;
	f[rt][1][1]=((y*qpow(2,s[rt])%p-x)%p+p)%p*qpow(2,d[rt])%p;//cout<<rt<<" "<<x<<" "<<y<<endl;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		insertt(x,y,i*2);
		insertt(y,x,i*2+1);
	}
	tarjan(1,0);
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			dfs(i,++cnt);
			d[cnt]/=2;
	//		cout<<d[cnt]<<endl;
		}
	for(int i=1;i<=cnt;i++)
	{
		s[i]=edcc[i].size();
		for(int j=0;j<s[i];j++)
		{
			int x=edcc[i][j];//cout<<x<<" ";
			for(int k=head[x];k;k=e[k].next)
			{
				int y=e[k].to;
				if(c[y]!=i)
				//{
					v[i].push_back(c[y]);//cout<<c[y]<<" ";
				//}cout<<" ";
			}
		}//cout<<endl;
	}
	dp(1,0);
 	ans=(f[1][1][1]+f[1][1][0])%p; 
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
