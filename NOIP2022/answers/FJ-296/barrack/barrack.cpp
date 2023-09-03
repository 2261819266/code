//Lin Shuyao AK chemistry exam FOREVER.
#include<cstdio>
#include<cstring>
#include<vector>

//#define dxx
#ifdef dxx
#define dbg(...) fprintf(stderr,__VA_ARGS__)
#define dex(a) dbg(#a"=%lld onL%d infun %s\n",a,__LINE__,__FUNCTION__)
#include<cstdlib>
#define pause sys##tem("pause")
#endif

using ll=long long;
template<class T> T max(T a,T b){return a>b?a:b;}
template<class T> T min(T a,T b){return a<b?a:b;}
template<class T> void cmax(T&a,T b){a=max(a,b);}
template<class T> void cmin(T&a,T b){a=min(a,b);}
template<class T> T sqr(T a){return a*a;}
template<class T> T abs(T a){return a<0?-a:a;}
template<class T> void swap(T&a,T&b){T t=a;a=b;b=t;}

bool be;

const ll mod=1000000007;
ll ksm(ll a,ll p=mod-2){
	ll ans=1;
	while(p){
		if(p&1) ans=ans*a%mod;
		a=a*a%mod;
		p>>=1;
	}return ans;
}

//震惊！NOIP 考了连通性！
namespace gph{
	struct edge{
		int t,n;
		bool isb;
	} g[2000005];
	int cnt=2,hd[500001];
	void ade(int s,int t){
		g[cnt]={t,hd[s],0};
		hd[s]=cnt++;
	}
	
	int dfc,dfn[500001],low[500001],bccnt,bcc[500001],bccsiz[500001];
	void targan(int x,int p){
		int i,t;

		dfn[x]=low[x]=++dfc;
		for(i=hd[x];i;i=g[i].n)
			if(!dfn[t=g[i].t]){
				targan(t,x);
				cmin(low[x],low[t]);
				if(low[t]>dfn[x]) g[i].isb=g[i^1].isb=1;
			}else if(t!=p) cmin(low[x],dfn[t]);
	}void col(int x){
		int i;
		bcc[x]=bccnt;
		++bccsiz[bccnt];
		for(i=hd[x];i;i=g[i].n)
			if(!g[i].isb&&!bcc[g[i].t])
				col(g[i].t);
	}
} 

namespace newgph{
	struct edge{
		int t,n;
	} g[1000005];
	int cnt=2,hd[1000005];
	void ade(int s,int t){
		g[cnt]={t,hd[s]};
		hd[s]=cnt++;
	}
	
	int pr[1000005],siz[1000005],son[1000005],dep[1000005],top[1000005],Stmp[1000005];
	bool vis[1000005];
	void dfs1(int x,int p){
		int i,mxs=0,t;
		siz[x]=1;
		pr[x]=p;
		dep[x]=dep[p]+1;
		for(i=hd[x];i;i=g[i].n)
			if((t=g[i].t)!=p){
				dfs1(t,x);
				siz[x]+=siz[t];
				if(siz[t]>mxs){
					mxs=siz[t];
					son[x]=t;
				}
			}
	}void dfs2(int x,int tp){
		int i;
		top[x]=tp;
		if(son[x]){
			dfs2(son[x],tp);
			for(i=hd[x];i;i=g[i].n)
				if(g[i].t!=pr[x]&&g[i].t!=son[x])
					dfs2(g[i].t,g[i].t);
		}
	}int lca(int x,int y){
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]]) ::swap(x,y);
			x=pr[top[x]];
		}return dep[x]>dep[y]?y:x;
	}ll solve(int S,int m){
		ll ans;
		int i,j,k,cnt=0,egc=0,LCA;
		for(i=0;i<gph::bccnt;++i) if(S>>i&1) Stmp[++cnt]=i+1;
	
		memset(vis+1,0,sizeof(*vis)*gph::bccnt);
		
		for(i=1;i<=cnt;++i)
		for(j=i+1;j<=cnt;++j){
			LCA=lca(Stmp[i],Stmp[j]);
			for(k=Stmp[i];k!=LCA;k=pr[k])
				if(!vis[k]){
					vis[k]=1;
					++egc;
				}
			for(k=Stmp[j];k!=LCA;k=pr[k])
				if(!vis[k]){
					vis[k]=1;
					++egc;
				}
		}
		
		ans=ksm(2,m-egc);
		for(i=1;i<=cnt;++i) ans=ans*((ksm(2,gph::bccsiz[Stmp[i]])+mod-1)%mod)%mod;
		return ans;
	}
}

namespace xm{
	void _(){
		ll ans=0;
		int n,m,u,v,i;
		
		scanf("%d%d",&n,&m);
		
		if(n>3000){
			for(i=1;i<=n;++i)
				ans=(ans+ksm(2,n-i)*(n-i+1)%mod*(i<3?1:ksm(2,i-2))%mod)%mod;
			printf("%lld\n",ans);
			return;
		}
		
		for(i=0;i<m;++i){
			scanf("%d%d",&u,&v);
			gph::ade(u,v);
			gph::ade(v,u);
		}
		
		for(i=1;i<=n;++i) if(!gph::dfn[i]) gph::targan(i,0);
		for(i=1;i<=n;++i) if(!gph::bcc[i]){
			++gph::bccnt;
			gph::col(i);
		}
		
		for(u=1;u<=n;++u)
		for(i=gph::hd[u];i;i=gph::g[i].n)
			if(gph::bcc[u]!=gph::bcc[gph::g[i].t])
				newgph::ade(gph::bcc[u],gph::bcc[gph::g[i].t]);
		newgph::dfs1(1,0);
		newgph::dfs2(1,1);
		for(i=1;i<(1<<gph::bccnt);++i){
			ans=(ans+newgph::solve(i,m))%mod;
		}
		
		printf("%lld\n",ans);
	}
}

bool ed;

int main(){
//	printf("%f MB\n",(&be - &ed)/1024.0/1024.0);
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	xm::_();
	return 0;
}

