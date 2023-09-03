#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const int N=5e5+100,M=1e6+100;
int n,m;
int h[N],nxt[M*2],to[M*2],cnt=1;
int dh[N],dnxt[M*2],dto[M*2],dcnt;
int dfn[N],tot,low[N],biao[N],btot,num[N],bian[N];
int siz[N],zong;
bool flg[M*2];
ll dp[N]/*LCA*/,f[N][5],res[N]/*yanshen*/;
ll ans;
ll ksm(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1)
		res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
void add(int x,int y)
{
	++cnt;
	to[cnt]=y;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
void dadd(int x,int y)
{
	++dcnt;
	dto[dcnt]=y;
	dnxt[dcnt]=dh[x];
	dh[x]=dcnt;
}
void dd(int &v)
{
	v=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		v=v*10+ch-48;
		ch=getchar();
	}
}
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++tot;
	for(int i=h[x];i!=-1;i=nxt[i])
	{
		if(i==fa||(i^1)==fa)
		continue ;
		if(!dfn[to[i]])
		{
			tarjan(to[i],i);
			low[x]=min(low[x],low[to[i]]);
			if(low[to[i]]>dfn[x])
			{
				flg[i]=flg[i^1]=1;
			}
		}
		else
		{
			low[x]=min(low[x],dfn[to[i]]);
		}
	}
}
void dfs_biao(int x)
{
	biao[x]=btot;
	++num[btot];
	for(int i=h[x];i!=-1;i=nxt[i])
	{
		if(flg[i]||biao[to[i]])
		continue ;
		dfs_biao(to[i]);
	}
}
void dfs(int x,int fa)
{
	//cout<<x<<""
	f[x][0]=1;
	siz[x]=1;
	for(int i=dh[x];i!=-1;i=dnxt[i])
	{
		int zi=dto[i];
		if(zi==fa)
		continue ;
		dfs(zi,x);
		siz[x]+=siz[zi];
		ll qres=ksm(2,siz[zi]);
		f[x][2]=(f[x][2]*qres%mod+f[x][1]*res[zi])%mod;
		f[x][1]=(f[x][1]*qres%mod+f[x][0]*res[zi])%mod;
		f[x][0]=(f[x][0]*qres)%mod;
	}
	//cout<<f[x][0]<<" "<<f[x][1]<<" "<<f[x][2]<<endl;
	dp[x]=(    (ksm(2,num[x])-1)*(f[x][0]+f[x][1]+f[x][2])%mod + 1*f[x][2]      )%mod;
	
	for(int i=dh[x];i!=-1;i=dnxt[i])
	{
		int zi=dto[i];
		if(zi==fa)
		continue ;
		res[x]=(res[x]+res[zi]*ksm(2,siz[x]-siz[zi]-1))%mod;
	}
	res[x]=(res[x]+dp[x])%mod;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	memset(h,0xff,sizeof(h));
	memset(dh,0xff,sizeof(dh));
	dd(n);
	dd(m);
	for(int i=1,x,y;i<=m;++i)
	{
		dd(x);
		dd(y);
		add(x,y);
		add(y,x);
	}
	tarjan(1,0);
	for(int i=1;i<=n;++i)
	{
		if(!biao[i])
		{
			++btot;
			dfs_biao(i);
		}
		//cout<<biao[i]<<" ";
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=h[i];j!=-1;j=nxt[j])
		{
			if(biao[i]!=biao[to[j]])
			{
				dadd(biao[i],biao[to[j]]);
			}
			else
			{
				++bian[biao[i]];
			}
		}
	}
	for(int i=1;i<=btot;++i)
	{
		bian[i]/=2;	
		zong+=bian[i];
	}
	dfs(1,0);
	for(int i=1;i<=btot;++i)
	{
		ans=(ans+dp[i]*ksm(2,siz[1]-siz[i]))%mod;
		//cout<<dp[i]<<endl;
	}
	printf("%lld",(ans*ksm(2,zong))%mod);
	return 0;
}


/*
2 1
1 2
*/
















