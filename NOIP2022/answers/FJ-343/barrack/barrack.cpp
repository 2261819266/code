#include<bits/stdc++.h>
#define ll long long
#define fs(i,x,y,z) for(int i=x;i<=y;i+=z)
#define ft(i,x,y,z) for(int i=x;i>=y;i+=z)
#define ull unsigned long long
const ll N=1000001,inf=1e9+7;
inline int read(){
	int v=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar();}
	while(c>='0'&&c<='9'){v=v*10+(c-'0');c=getchar();}
	return v*w;
}
using namespace std;
struct edge{int v,nx;}e[N<<1];
struct bian{int u,v;}g[N];
int n,hd[N],totm,m,xz1=1;
int pow2[N],geb[N],dfn[N],low[N],idx,vis[N],dccs,chs[N],seen[N];
ll ans;
void add(int u,int v){
	e[++totm].v=v;e[totm].nx=hd[u];
	hd[u]=totm;
}
ll ksm(ll x,ll y){
	ll res=1ll;while(y){
		if(y&1) res=res*x%inf;
		x=x*x%inf;y>>=1ll;
	} 
	return res;
}
void dfs(int now){
	if(now>n){//一个边双一条边，别的无所谓 
		//计算 
		ll res=0,anss=0,flg=0;
		fs(i,1,n,1) seen[i]=0;
		fs(i,1,n,1){
			if(!chs[i]) continue;
			if(!seen[vis[i]]) res++;
			flg=1;
			seen[vis[i]]=1;
		}
		if(!flg) return;
//		fs(i,1,n,1) printf("(%d,%d)",sz[i],find(i));
//		printf("%d cont %lld\n",zt,res);
		//说明有res-1条割边
		anss=ksm(2,m-res+1);//其他爱怎么连怎么连 
		ans=(ans+anss)%inf; 
		return;
	}
	chs[now]=0;dfs(now+1);
	chs[now]=1;dfs(now+1); 
	//那如果连了呢？ 
	//问题很明显：哪来的7？ 
} 
void tarjan(int now,int faf){
	dfn[now]=low[now]=++idx;
	for(int i=hd[now];i;i=e[i].nx){
		int v=e[i].v;
		if(!dfn[v]){
			tarjan(v,now);
			if(low[v]>dfn[now]){
				geb[i]=1;
				if(i&1) geb[i+1]=1;
				else geb[i-1]=1;
			}
			low[now]=min(low[v],low[now]);
		}else if(v!=faf) low[now]=min(low[v],low[now]);
	}
}
void dfs0(int now){
	vis[now]=dccs;
	for(int i=hd[now];i;i=e[i].nx){
		if(geb[i]||vis[e[i].v]) continue;
		dfs0(e[i].v);
	}
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	pow2[0]=1;
	n=read(),m=read();
	fs(i,1,m,1) pow2[i]=pow2[i-1]*2;
	fs(i,1,m,1){
		int u=read(),v=read();
		add(u,v);add(v,u);//一共多少条边，这个要记录上去 
		xz1&=((v-u==1)&&(u==i));
		g[i]={u,v};
	}
	if(xz1) return printf("%lld",((n*(n-1)%inf*ksm(2,inf-2)%inf)*ksm(2,n-2)%inf+n*ksm(2,n-1)%inf)%inf),0;
	tarjan(1,0);//fs(i,1,totm,1)cout<<geb[i]<<' ';
	fs(i,1,n,1){
		if(!vis[i]){
			dccs++;
			dfs0(i);
		}
	}
	//fs(i,1,n,1) cout<<vis[i]<<' ';
	dfs(1);//找出那些割边，必须填写，其他的无所谓 
	printf("%lld",ans);
	return 0;
}
