#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <random>
#include <bitset>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#define rep(i,j,k) for(int i=j;i<=(k);++i)
#define drp(i,j,k) for(int i=j;i>=(k);--i)
#define isdigit(ch) (ch>=48&&ch<=57)
#define mp std::make_pair
#define mod 1000000007
#define MAXN 1000005
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
const double eps=1e-6;
const double pi=acos(-1);
const int dx[8]={1,-1,0,0,1,1,-1,-1};
const int dy[8]={0,0,1,-1,1,-1,1,-1};
inline int read(){
	int x=0;
	char ch=getchar();
	bool f=false;
	while(!isdigit(ch)) f|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
inline ll readll(){
	ll x=0;
	char ch=getchar();
	bool f=false;
	while(!isdigit(ch)) f|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
template <typename tp> inline tp min(tp a,tp b){return a<b?a:b;}
template <typename tp> inline tp max(tp a,tp b){return a>b?a:b;}
template <typename tp> inline bool chkmin(tp &a,tp b){return a>b&&(a=b,true);}
template <typename tp> inline bool chkmax(tp &a,tp b){return a<b&&(a=b,true);}
int n,m,tot,rk,top,cnt,num,head[MAXN];
int dfn[MAXN],low[MAXN],stk[MAXN],blg[MAXN],size[MAXN],val[MAXN];
ll ans,f[MAXN][2][2];
bool vis[MAXN];
std::vector<int> son[MAXN];
struct graph{int v,next;}edge[MAXN<<1];
inline void add_edge(int u,int v){
	edge[++tot]=(graph){v,head[u]};
	head[u]=tot;
}
inline void dfs(int u,int lst){
	dfn[u]=low[u]=++rk;
	vis[u]=true,stk[++top]=u;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].v;
		if(v==lst) continue;
		if(!dfn[v]){
		    dfs(v,u),chkmin(low[u],low[v]);
		    if(low[v]>dfn[u]){
		    	++cnt;
		    	int cur=stk[top--];
		    	while(true){
		    		blg[cur]=cnt;
		    		++size[cnt];
		    		vis[cur]=false;
		    		if(cur==v) break;
		    		cur=stk[top--];
	  	    	}
	    	}
		}
		else if(vis[v]) chkmin(low[u],dfn[v]);
	}
	if(u==1){
		++cnt;
		rep(i,1,top){
			int cur=stk[i];
			blg[cur]=cnt;
			++size[cnt];
		}
	}
}
inline ll pw(int x,int y){
	ll base=x,ret=1;
	for(;y;y>>=1,(base*=base)%=mod)
	    if(y&1) (ret*=base)%=mod;
	return ret;
}
inline void solve(int u,int fa){
	f[u][0][0]=f[u][0][1]=1;
	ll prod=1;
	for(auto v:son[u]){
		if(v==fa) continue;
		solve(v,u),val[u]+=val[v]+1;
		(f[u][0][0]*=f[v][0][0]<<1)%=mod;
		(f[u][0][1]*=f[v][0][1]<<1)%=mod;
		(prod*=f[v][1][1]+(f[v][0][1]<<1))%=mod;
	}
	f[u][1][0]=f[u][1][1]=((prod-f[u][0][1]+mod)+(pw(2,size[u])-1)*prod)%mod;
	(ans+=f[u][1][0]*pw(2,max(num-val[u]-1,0)))%=mod;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	rep(i,1,m){
		int u=read(),v=read();
		add_edge(u,v),add_edge(v,u);
	}
	dfs(1,0);
	rep(u,1,n) for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].v;
		if(blg[u]==blg[v]) continue;
		if(u<v) ++num;
		son[blg[u]].push_back(blg[v]);
		son[blg[v]].push_back(blg[u]);
	}
	rep(i,1,n){
		std::sort(son[i].begin(),son[i].end());
		son[i].erase(std::unique(son[i].begin(),son[i].end()),son[i].end());
	}
	solve(1,0);
	printf("%lld\n",ans*pw(2,m-num)%mod);
}
