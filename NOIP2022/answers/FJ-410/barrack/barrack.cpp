#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e6+5,N=5e5+5;
const ll mod=1e9+7;
inline void dd(int &ss){
	ss=0;int ff=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ss=ss*10+ch-'0',ch=getchar();
	}
	ss*=ff;
}
int n,m,ver[M*2],net[M*2],cnt,h[N],tot,b[N],xb[M],yb[M],dp[N],dep[N],dfn[N],low[N],c[N],doc,siz[N],br[N],g;ll ans;
void add(int x,int y){
	++cnt;
	ver[cnt]=y;
	net[cnt]=h[x];
	h[x]=cnt;
}
void tarjan(int x,int d){
	dfn[x]=low[x]=++tot;
	for(int i=h[x];i;i=net[i]){
		int y=ver[i];
		if(!dfn[y]){
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
		}else{
			if(i!=(d^1)){
				low[x]=min(low[x],dfn[y]);
			}
		}
		if(low[x]>=dfn[x]){
			br[d]=br[d^1]=1;
		}
	}
}
void dfs(int x){
	c[x]=doc;
	for(int i=h[x];i;i=net[i]){
		int y=ver[x];
		if(!c[y]&&!br[i]){
			dfs(y); 
		}
	}
}
void sss(int x,int fa){
	dep[x]=dep[fa]+1;
	dp[x]=dp[fa]+b[x];
	siz[x]=b[x];
	for(int i=h[x];i;i=net[i]){
		int y=ver[i];
		if(y==fa) continue;
		sss(y,x);
		siz[x]+=siz[y];
	}
}
ll ksm(ll a,ll b){
	ll res=1;
	for(;b;b>>=1){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
	}
	return res;
}
void dfss(int x,int u){
	if(x==n+1){
		if(!u){
			return ;
		}
//		cout<<1<<endl;
		g=0;
		sss(1,0);
		for(int i=1;i<=m;++i){
			if(c[xb[i]]!=c[yb[i]]){
//				cout<<1<<endl;
				int u=c[xb[i]],v=c[yb[i]];
				if(dep[u]<dep[v]) swap(u,v);
				if(siz[u]!=m)
				++g;
			}
		}
//		cout<<g<<endl;
		ans+=ksm(2,m-g);
//		exit(0);
		return ;
	}
	b[c[x]]=1;
	dfss(x+1,u+1);
	b[c[x]]=0;
	dfss(x+1,u);
}
int main(){
	freopen("barrack.out","r",stdin);
	freopen("barrack.in","w",stdout);
	dd(n),dd(m);
	for(int i=1;i<=m;++i){
		dd(xb[i]),dd(yb[i]);
		add(xb[i],yb[i]);
		add(yb[i],xb[i]);
	}
//	for(int i=1;i<=n;++i)
	for(int i=1;i<=n;++i){
		if(!dfn[i])
			tarjan(i,0);
	}
	for(int i=1;i<=n;++i){
		if(!c[i]){
			++doc;
			dfs(i);
		}
	}
//	cout<<c[1]<<" "<<c[2]<<endl;
	cnt=0;
	for(int i=1;i<=n;++i) h[i]=0;
	for(int i=1;i<=m;++i){
		if(c[xb[i]]!=c[yb[i]]){
			add(c[xb[i]],c[yb[i]]);
			add(c[yb[i]],c[xb[i]]);
		}
	}
	dfss(1,0);
	printf("%lld",ans);
}

