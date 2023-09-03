#include<cstdio>
#include<algorithm>
using namespace std;
#define isDigit(ch) ('0'<=ch&&ch<='9')
#define i64 long long
inline int read()
{
	int num=0;
	char ch=getchar();
	while(!isDigit(ch))
		ch=getchar();
	while(isDigit(ch))
	{
		num=num*10+(ch-'0');
		ch=getchar();
	}
	return num;
}

inline int gmin(int x,int y){return x<y?x:y;}

const int mod=1000000007;
inline int Mod(int x){return x>=mod?x-mod:x;}
inline void Add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
inline int qPow(i64 val,int p=mod-2)
{
	i64 res=1;
	while(p)
	{
		if(p&1)res=res*val%mod;
		val=val*val%mod;p>>=1;
	}
	return res;
}
const int inv2=qPow(2);

#define N 500010
#define M 1000010

int pw[N];

int n,m;

int x[M],y[M];bool isC[M];

int first[N],nxt[M<<1],v[M<<1],tot=1;

int dfn[N],low[N],cur=0;

int gid[N],gn=0;
int sz[N];

int F[N];
int G[N];

int Ans=0;

inline void ins(int u0,int v0)
{
	tot++;
	nxt[tot]=first[u0];
	first[u0]=tot;
	v[tot]=v0;
}

inline void dfs1(int pre,int u)
{
	dfn[u]=low[u]=++cur;
	for(int i=first[u];i;i=nxt[i])
	{
		if(!dfn[v[i]])
		{
			dfs1(i,v[i]);
			low[u]=gmin(low[u],low[v[i]]);
			if(low[v[i]]>dfn[u])isC[i>>1]=1;
		}
		else if(pre!=(i^1))low[u]=gmin(low[u],dfn[v[i]]);
	}
}

inline void dfs2(int u)
{
	gid[u]=gn;sz[gn]++;
	for(int i=first[u];i;i=nxt[i])
	{
		if(gid[v[i]]||isC[i>>1])
			continue;
		dfs2(v[i]);
	}
}

//inline void dfs3(int fa,int u)
//{
//	int mul=1,sum=1;
//	for(int i=first[u];i;i=nxt[i])
//	{
//		if(fa==v[i])continue;
//		dfs3(u,v[i]);
//		mul=1ll*mul*(F[v[i]]+1)%mod;
//		Add(sum,F[v[i]]);
//	}
//	F[u]=(1ll*(pw[sz[u]]-1+mod)*mul+mul-1+mod)%mod*inv2%mod;
//	Ans=(Ans+F[u]*2ll+mul-sum+mod)%mod;
//}

inline void dfs3(int fa,int u)
{
	int mul=1,sum=1;
	for(int i=first[u];i;i=nxt[i])
	{
		if(fa==v[i])continue;
		dfs3(u,v[i]);
		mul=1ll*mul*(F[v[i]]+G[v[i]]+1)%mod;
		sum=(1ll*sum+F[v[i]]+G[v[i]])%mod;
	}
	F[u]=1ll*(pw[sz[u]]-1+mod)*mul%mod;
	G[u]=Mod(mul+mod-1);
	
	Ans=(1ll*Ans+F[u]+mul-sum+mod)%mod;
	F[u]=1ll*F[u]*inv2%mod;
	G[u]=1ll*G[u]*inv2%mod;
}

int main()
{
	#define NAME "barrack"
	freopen(NAME ".in","r",stdin);
	freopen(NAME ".out","w",stdout);
	
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		x[i]=read(),y[i]=read();
		ins(x[i],y[i]),ins(y[i],x[i]);
	}
	//preDone
	pw[0]=1;
	for(int i=1;i<=n;i++)
		pw[i]=Mod(pw[i-1]+pw[i-1]);
	//do 1
	dfs1(0,1);
	//do 2
	for(int i=1;i<=n;i++)
		if(!gid[i])gn++,dfs2(i);
	//do 3
	tot=1;
	for(int i=1;i<=n;i++)
		first[i]=0;
	for(int i=1;i<=m;i++)
		if(isC[i])
			ins(gid[x[i]],gid[y[i]]),
			ins(gid[y[i]],gid[x[i]]);
	dfs3(1,1);
	Ans=1ll*Ans*qPow(2,m)%mod;
	printf("%d",Ans);
	return 0;
}
//Never gonna give you up.
