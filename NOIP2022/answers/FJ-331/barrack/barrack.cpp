#include<cstdio>
#include<iostream>
#define int long long
using namespace std;

const int N=500010,M=1000010,mod=1000000007;
struct edge{int to,next;}e[M<<1],e2[M<<1];
int n,m,idx=1,head[N],idx2,head2[N];
int cnt,dfn[N],low[N],top,st[N],lc,c[N],sz[N],sze[N];
bool cut[M<<1];
int pow2[M],f[N][4];

int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while('0'<=ch&&ch<='9'){x=(x<<3)+(x<<1)+(ch-'0');ch=getchar();}
	return x;
}

void add(int u,int v){
	e[++idx]=(edge){v,head[u]};
	head[u]=idx;
}

void add2(int u,int v){
	e2[++idx2]=(edge){v,head2[u]};
	head2[u]=idx2;
}

void tarjan(int k,int fa){
	dfn[k]=low[k]=++cnt;st[++top]=k;
	for(int i=head[k];i;i=e[i].next){
		int t=e[i].to;
		if(!dfn[t]){
			tarjan(t,k);
			if(low[t]>dfn[k]){cut[i]=cut[i^1]=true;}
			low[k]=min(low[k],low[t]);
		}else if(t!=fa){low[k]=min(low[k],dfn[t]);}
	}
	if(dfn[k]==low[k]){
		lc++;
		while(st[top]!=k){c[st[top--]]=lc;}
		c[st[top--]]=lc;
	}
}

void dfs(int k,int fa){
	f[k][0]=pow2[sze[k]];
	f[k][1]=pow2[sz[k]]%mod*pow2[sze[k]]%mod;
	f[k][2]=0;
	int tmp=1;
	for(int i=head2[k];i;i=e2[i].next){
		int t=e2[i].to;
		if(t==fa)continue;
		dfs(t,k);
		f[k][0]=f[k][0]*2ll%mod*f[t][0]%mod;
		f[k][1]=f[k][1]*((2ll*f[t][0]%mod+f[t][1])%mod)%mod;
		f[k][2]=(f[k][2]+((f[t][1]+2ll*f[t][2])%mod)%mod)%mod;
		tmp=tmp*((2ll*f[t][0])%mod)%mod;
	}
	f[k][1]=(f[k][1]-pow2[sze[k]]*tmp%mod+mod)%mod;
	f[k][2]=f[k][2]*pow2[sze[k]]%mod;
}

signed main(){
	freopen("barrack.in","r",stdin);freopen("barrack.out","w",stdout);
	pow2[0]=1ll;
	for(int i=1;i<M;i++){pow2[i]=pow2[i-1]*2ll%mod;}
	n=read();m=read();
	for(int i=1,u,v;i<=m;i++){
		u=read();v=read();
		add(u,v);add(v,u);
	}
	tarjan(1,0);
	for(int i=1;i<=n;i++){
		sz[c[i]]++;
		for(int j=head[i];j;j=e[j].next){
			int t=e[j].to;
			if(c[i]==c[t]){sze[c[i]]++;}
			else{add2(c[i],c[t]);}
		}
	}
	for(int i=1;i<=lc;i++)sze[i]/=2;
	dfs(1,0);
	printf("%lld\n",(f[1][1]+f[1][2])%mod);
	return 0;
}
//noip2022rp++
