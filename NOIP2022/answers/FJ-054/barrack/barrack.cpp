#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;
typedef long long LL;
const int N=5e5+10,M=2e6+10,MOD=1e9+7;
struct str
{
	int u,to;
	str(int u=0,int to=0)
	{
		this->u=u;
		this->to=to;
	}
}edge[M];
int head[N],cnt;
void m_insert(int m_from,int m_to)
{
	edge[cnt].u=head[m_from];
	edge[cnt].to=m_to;
	head[m_from]=cnt++;
	return ;
}
int dfn[N],low[N],tot;
int m_stack[N],top;
int ct,m_p[N];
int m_bridge[M];
int sz[N],tp[N];
void tarjan(int x,int from)
{
	dfn[x]=low[x]=++tot;
	m_stack[++top]=x;
	for(int i=head[x];i!=-1;i=edge[i].u)
	{
		if(i==(from^1))
			continue;
		if(!dfn[edge[i].to])
		{
			tarjan(edge[i].to,i);
			low[x]=min(low[x],low[edge[i].to]);
			if(low[edge[i].to]>dfn[x])
			{
				ct++;
				m_bridge[i]=m_bridge[i^1]=true;
				do
				{
					int t=m_stack[top--];
					sz[ct]++;
					m_p[t]=ct;
				}while(m_stack[top+1]!=edge[i].to);
			}
		}
		else
		{
			low[x]=min(low[x],dfn[edge[i].to]);
		}
	}
	return ;
}
int qmi(int a,int b)
{
	if(b==0)
		return 1;
	else if(b==1)
		return a;
	int k=qmi(a,b>>1);
	k=(LL)k*k%MOD;
	if(b&1)
		k=(LL)k*a%MOD;
	return k;
}
LL inv(LL x)
{
	return qmi(x,MOD-2);
}
int tmod(int x)
{
	return (x%MOD+MOD)%MOD;
}
int dp[N][2];
int tot_v[N],tot_l[N];
void dfs_c(int x,int fa)
{
	dp[x][0]=dp[x][1]=1;
	for(int i=head[x];i!=-1;i=edge[i].u)
	{
		if(edge[i].to==fa)
			continue;
		dfs_c(edge[i].to,x);
		dp[x][0]=(LL)dp[x][0]*dp[edge[i].to][0]*2%MOD;
		dp[x][1]=((LL)dp[x][1]*(dp[edge[i].to][0]*2+dp[edge[i].to][1]))%MOD;
	}
	dp[x][0]=(LL)dp[x][0]*qmi(2,tp[x])%MOD;
	dp[x][1]=(LL)dp[x][1]*qmi(2,sz[x])%MOD*qmi(2,tp[x])%MOD;
	dp[x][1]=tmod(dp[x][1]-dp[x][0]);
	return ;
}
int dis[N][2];
int ans=0;
void dfs_s(int x,int fa)
{
	int p=dis[x][1];
	for(int i=head[x];i!=-1;i=edge[i].u)
	{
		if(edge[i].to!=fa)
		{
			
			int p2=(LL)dp[x][0]*inv(dp[edge[i].to][0]*2)%MOD;
			int p1=tmod((LL)(dp[x][1]+dp[x][0])%MOD*inv(dp[edge[i].to][0]*2%MOD+dp[edge[i].to][1])%MOD-p2);
			ans=((LL)ans+(LL)dis[x][0]*p2%MOD*dp[edge[i].to][1]%MOD*2+(LL)dis[x][1]*p1%MOD*dp[edge[i].to][0]*2%MOD)%MOD;
			if(x==1)
				dis[x][1]=0;
			dis[edge[i].to][0]=p1*dis[x][0]%MOD*2;
			dis[edge[i].to][1]=((LL)p2*dis[x][1]%MOD+p1*dis[x][0]%MOD+p1*dis[x][1]%MOD)%MOD;
			if(x==1)
				dis[x][1]=p;
			dfs_s(edge[i].to,x);
		}
	}
	return ;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	memset(head,-1,sizeof(head));
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		m_insert(x,y);
		m_insert(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
		{
			tarjan(i,-1);
			ct++;
			do
			{
				int t=m_stack[top--];
				sz[ct]++;
				m_p[t]=ct;
			}while(m_stack[top+1]!=i);
		}
	int p=cnt;
	memset(head,-1,sizeof(head));
	cnt=0;
	int tl=1;
	for(int i=0;i<p;i+=2)
	{
		int x=edge[i].to,y=edge[i^1].to;
		if(m_p[x]==m_p[y])
		{
			tp[m_p[x]]++;
		}
		else
		{
			x=m_p[x],y=m_p[y];
			m_insert(x,y);
		}
	}
	dfs_c(1,-1);
	dis[1][0]=1;
	dis[1][1]=1;
	dfs_s(1,-1);
	int len=m-(ct-1);
	for(int i=1;i<=ct;i++)
		tl=(LL)tl*(qmi(2,sz[i])-1)%MOD;
	tl=(LL)tl*qmi(2,len)%MOD;
	printf("%d",tmod(ans+tl));
	return 0;
}
