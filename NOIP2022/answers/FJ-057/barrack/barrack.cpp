#include <cstdio>
#include <iostream>
#define MAXX 500050 
#define mod 1000000007
#define ll long long 
using namespace std;
struct side{
	int nxt=0;
	int to=0;
} G[MAXX*4],sG[MAXX*2];
int head[MAXX],iter=0;
inline void insert(int u,int v){
	G[++iter].nxt=head[u];
	G[iter].to=v;
	head[u]=iter;
}
int shead[MAXX],siter=0;
inline void _insert(int u,int v){
	sG[++siter].nxt=shead[u];
	sG[siter].to=v;
	shead[u]=siter;
}

int dfn[MAXX],low[MAXX],ite=0;
int sta[MAXX],it=0;
int cnt=0,bl[MAXX],siz1[MAXX];
inline void Tarjan(int node,int fa){
	dfn[node]=low[node]=++ite;
	sta[++it]=node;
	for(int i=head[node];i;i=G[i].nxt){
		int to=G[i].to;
		if(to!=fa){
			if(dfn[to]==0){
				Tarjan(to,node);
				low[node]=min(low[node],low[to]);
			}else low[node]=min(low[node],low[to]);
		}
	}
	if(low[node]==dfn[node]){
		cnt++;
		while(sta[it]!=node){
			bl[sta[it]]=cnt;
			siz1[cnt]++;
			it--;
		}
		bl[sta[it]]=cnt;
		siz1[cnt]++;
		it--;
	}
}
inline ll qui_pow(ll bs,int p){
	if(p<=0) return 1;
	if(p==1) return bs;
	ll o=qui_pow(bs,p>>1);
	if(p&1) return o*o%mod*bs%mod;
	else return o*o%mod;
}
ll dp[MAXX];
ll spe[MAXX];
ll s[MAXX];
ll ans=0;
inline void dfs(int node,int fa){
	spe[node]=1;
	dp[node]=qui_pow(2,siz1[node])-1;
	for(int i=shead[node];i;i=sG[i].nxt){
		int to=sG[i].to;
		if(to!=fa){
			dfs(to,node);
			s[node]+=s[to]+1;
			dp[node]=((dp[node]*spe[to]%mod)*2ll%mod+spe[node]*dp[to]%mod+dp[node]*dp[to]%mod)%mod;
			spe[node]=spe[node]*2ll*spe[to]%mod;
		}
	}
	ans=(ans+dp[node]*qui_pow(2,cnt-1-s[node]-1)%mod)%mod;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		insert(u,v),insert(v,u);
	}
	Tarjan(1,0);
	int ext=0;
	for(int i=1;i<=n;i++){
		for(int j=head[i];j;j=G[j].nxt){
			int u=bl[i],v=bl[G[j].to];
			if(u==v){
				ext++;
				continue;
			}
			_insert(u,v);
		}
	}
	dfs(1,0);
	printf("%lld",(ans*qui_pow(2,ext/2))%mod);
	return 0;
}
