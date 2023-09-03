#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int read()
{
	int ret=0;
	char c=0;
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9') ret=ret*10-'0'+c,c=getchar();
	return ret;
}

const int N=5e5+5,M=2e6+5;
const long long mod=1e9+7;

int n,m,u,v,ans,mt;
int oto[M],onxt[M],ohead[M];
int to[M],nxt[M],head[M];
int dfn[N],mi[N],tot;
int stack[N],top,col[N],ct;
int siz[N],gsiz[N];
long long dp[N],dp2[N],tans;

long long pow2(long long x)
{
	long long ans=1,tmp=2;
	while (x>0)
	{
		if (x&1) ans=(ans*tmp)%mod;
		tmp=(tmp*tmp)%mod;
		x>>=1;
	}
	return ans;
}

void tarjan(int x,int fa)
{
//	cout<<"tar"<<x<<'(';
	dfn[x]=mi[x]=++tot;
	stack[top++]=x;
	for (int p=head[x]; p; p=nxt[p]) if (to[p]!=fa)
		if (dfn[to[p]])
		{
			mi[x]=min(mi[x],dfn[to[p]]);
		}
		else
		{
			tarjan(to[p],x);
			mi[x]=min(mi[x],mi[to[p]]);
		} else ;
	if (mi[x]>=dfn[x])
	{
		ct++;
		while (stack[top]!=x)
			col[stack[--top]]=ct;
	}
//	cout<<')';
}

void suodian()
{
	mt=0,m=0;
	memcpy(oto,to,sizeof(to));
	memcpy(onxt,nxt,sizeof(nxt));
	memcpy(ohead,head,sizeof(head));
	memset(head,0,sizeof(head));
	for (int i=1; i<=n; i++)
	{
		gsiz[col[i]]++;
		for (int p=ohead[i]; p; p=onxt[p])
		{
			if (col[oto[p]]!=col[i])
				to[++m]=col[oto[p]],nxt[m]=head[col[i]],head[col[i]]=m;
			else mt++;
		}
	}
	mt/=2;
}

long long treedp(int x,int fa)
{
	if (dp[x]) return dp[x];
	long long ret=pow2(gsiz[x]),ret2=0;
	siz[x]=1;
	for (int p=head[x]; p; p=nxt[p]) if (to[p]!=fa)
	{
		ret=ret*(treedp(to[p],x)+pow2(siz[to[p]]))%mod;
		ret2+=dp2[to[p]];
		siz[x]+=siz[to[p]];
	}
	dp[x]=(ret-pow2(siz[x]-1)+mod)%mod;
	dp2[x]=dp[x]+ret2;
	//if (x!=fa)
	 tans=(tans+ret2)%mod;
//	if (x==fa) dp[x]=(dp[x]+ret2)%mod;
	return dp[x];
}

int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	for (int i=1; i<=m; i++)
	{
		u=read(),v=read();
		to[i*2-1]=u,nxt[i*2-1]=head[v],head[v]=i*2-1;
		to[i*2]=v,nxt[i*2]=head[u],head[u]=i*2;
	}
	tarjan(1,1);
	suodian();
	treedp(1,1);
	long long ans=0;
	for (int i=1; i<=ct; i++)
		ans+=dp[i];
	cout<<((dp[1]+tans)*pow2(mt)+mod)%mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
