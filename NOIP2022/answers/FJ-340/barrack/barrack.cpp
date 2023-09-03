#include<bits/stdc++.h>
#define int long long
#define reg register
using namespace std;
inline int cmin(reg int x,reg int y){return x<y?x:y;}
inline int cmax(reg int x,reg int y){return x>y?x:y;}
const int N=5e5+10,mod=1e9+7;
int n,m,head[N],cnt,ky[N];
struct EDGE{int pre,to;}edge[N<<2];
inline void add(reg int u,reg int v){edge[++cnt]=(EDGE){head[u],v},head[u]=cnt;}
int dfn[N],dfc,low[N],vis[N],s[N],top,tot,bel[N],sz[N],pw[N];
inline void tarjan(reg int u,reg int fa){
	dfn[u]=low[u]=++dfc;vis[u]=1,s[++top]=u; 
	for (reg int i=head[u],v;v=edge[i].to,i;i=edge[i].pre) if (v^fa){
		if (!dfn[v]) tarjan(v,u),low[u]=cmin(low[u],low[v]);
		else if (vis[v]) low[u]=cmin(low[u],dfn[v]);		
	}
	if (low[u]==dfn[u]){
		tot++; reg int v;
		while (v=s[top--]){bel[v]=tot,sz[tot]++;if (v==u) break;}
	}
}
vector<int> G[N];
int dep[N],qwq[N];
inline void dfs(reg int u,reg int fa){
	qwq[u]=ky[u],dep[u]=dep[fa]+1;
	for (auto v:G[u]) if (v^fa) dfs(v,u),qwq[u]+=qwq[v];
}
int u[N],v[N],ans;
signed main(){
	freopen("barrack.in","r",stdin);freopen("barrack.out","w",stdout);
	scanf("%lld%lld",&n,&m); pw[0]=1;
	for (reg int i=1;i<=cmax(n,m);i++) pw[i]=pw[i-1]*2%mod;
	for (reg int i=1;i<=m;i++) scanf("%lld%lld",&u[i],&v[i]),add(u[i],v[i]),add(v[i],u[i]);
	tarjan(1,0); 
	for (reg int i=1;i<=m;i++) if (bel[u[i]]!=bel[v[i]]) G[bel[u[i]]].push_back(bel[v[i]]),G[bel[v[i]]].push_back(bel[u[i]]); 
	for (reg int i=1;i<=tot;i++){sort(G[i].begin(),G[i].end());G[i].erase(unique(G[i].begin(),G[i].end()),G[i].end());}
	for (reg int s=1;s<(1<<tot);s++){ reg int mul=1,Cnt=0;
		for (reg int i=1;i<=tot;i++) if (s>>i-1&1) ky[i]=1,Cnt++; else ky[i]=0;
		for (reg int i=1;i<=tot;i++) if (ky[i]) mul=mul*(pw[sz[i]]-1)%mod;	 
		//for (reg int i=1;i<=n;i++) cout<<qwq[i]<<endl;
		dfs(1,0);  reg int ecnt=0; 
		for (reg int i=1;i<=tot;i++) for (auto it:G[i]){
			if (dep[i]<dep[it]){ //cout<<qwq[i]<<" "<<qwq[it]<<endl;
				if (qwq[it]&&qwq[it]<Cnt) ecnt++; 
			}
		}
		ans=(ans+pw[m-ecnt]*mul%mod)%mod; 
	}
	printf("%lld",(ans+mod)%mod);
	return 0;
}