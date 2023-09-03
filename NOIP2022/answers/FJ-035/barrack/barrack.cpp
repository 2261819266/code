# include <bits/stdc++.h>
# define N 500010
std::vector<int> e[N],ne[N];
int dfn[N],low[N],dfnn=0,cnt[N],t[N],t_n=0,wh[N];
bool mark[N],vis[N];
bool cs[N];
int n,m,p2[N],ex[N],ey[N],ans=0,en;
# define MOD 1000000007
int min(int x,int y) {
	return x<y?x:y;
}
void Tarjan(int x,int fa) {
	dfn[x]=low[x]=++dfnn;
	vis[x]=true;
//	printf("%d\n",x);
	for(auto v:e[x]) {
		if(v!=fa) {
			if(!vis[v]) Tarjan(v,x), low[x]=min(low[x],low[v]);
			else low[x]=min(low[x],dfn[v]);
		}
	}
	if(low[x]>=dfn[x]) mark[x]=true, t[++t_n]=x, wh[x]=t_n;
}
void dfs(int x,int fa,int bel) {
	if(mark[x]) {
		if(x!=bel) ne[bel].push_back(x), ex[++en]=bel, ey[en]=x;
		bel=x;
	}
	cnt[wh[bel]]++; vis[x]=true;
	for(auto v:e[x]) {
		if(v!=fa && !vis[v]) {
			dfs(v,x,bel);
		}
	}
}
bool fin(int x,int fa) {
//	printf("fin %d %d\n",x,fa);
	if(cs[x])return true;
	vis[x]=true;
	for(auto v:ne[x]) {
		if(!vis[v] && v!=fa) {
			if(fin(v,x)) return true;
		}
	}
	return false;
}
void dfs(int x,int mul) {
	if(x>t_n) {
		int i,cnt=0;
		for(i=1;i<=n && !cs[i];i++);
		if(i>n) return;
		for(i=1;i<=en;i++) {
			for(int j=1;j<=n;j++) vis[j]=false;
			if(fin(ex[i],ey[i]) && fin(ey[i],ex[i])) cnt++;
//			printf("%d %d\n",fin(1,2),fin(2,1));
		}
		ans=(1ll*mul*p2[m-cnt]+ans)%MOD;
//		for(i=1;i<=t_n;i++) printf("%d ",cs[i]);
//		puts("");
//		printf("%d\n",1ll*mul*p2[m-cnt]%MOD);
		return;
	}
	cs[x]=true;
	dfs(x+1,1ll*mul*(p2[cnt[x]]-1)%MOD);
	cs[x]=false;
	dfs(x+1,mul);
}
int main() {
	int i,x,y;
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	Tarjan(1,0);
	memset(vis,false,sizeof(vis));
	dfs(1,0,1);
p2[0]=1;
	for(i=1;i<=m;i++) p2[i]=p2[i-1]*2;
	dfs(1,1);
	printf("%d",ans);
	return 0;
} 
