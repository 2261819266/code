/*The truth is with you!*/
# include <bits/stdc++.h>
# define MAX (500009)
# define ll long long
# define inf (0x3f3f3f3f)
const int mod=1e9+7;
struct Node {
	int first;
} node[MAX],od[MAX];
struct Edge {
	int to,next;
} edge[MAX*4],dg[MAX*4];
int num,n,m,dfn[MAX],low[MAX],col[MAX],cnt,scc,dis[3009][3009],sr,fv[MAX];
ll ans;
bool vis[MAX];
std::stack<int>s;
std::vector<int>vs;
void add(int u,int v) {
	edge[++num].to=v;
	edge[num].next=node[u].first;
	node[u].first=num;
}
void ad(int u,int v) {
	dg[++num].to=v;
	dg[num].next=od[u].first;
	od[u].first=num;
}
int read() {
	int f=1,x=0;
	char ch=0;
	while('0'>ch||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
void cmin(int &a,int b) {
	a>b?a=b:0;
}
void tarjan(int now,int fa) {
	low[now]=dfn[now]=++cnt;
	vis[now]=1;
	s.push(now);
	int i,to;
	for(i = node[now].first; i; i = edge[i].next) {
		if((to=edge[i].to)==fa)continue;
		if(!dfn[to]) {
			tarjan(to,now);
			cmin(low[now],low[to]);
		} else if(vis[to]) {
			cmin(low[now],dfn[to]);
		}
	}
	if(low[now]==dfn[now]) {
		scc++;
		while(s.top()!=now) {
			col[s.top()]=scc;
			vis[s.top()]=0;
			s.pop();
		}
		col[now]=scc;
		vis[now]=0;
		s.pop();
	}
}
bool cmp(int a,int b) {
	return col[a]<col[b];
}
int anss,tu;
void dfss(int now,int dep) {
	if(now==tu)anss=dep;
	fv[now]=sr;
	int i,to;
	for(i = od[now].first; i; i = dg[i].next) {
		to=dg[i].to;
		if(fv[to]!=sr)dfss(to,dep+1);
	}
}
void check() {
	int i,j,l,k=m;
	vs.clear();
	for(i = 1; i <= n; i++) {
		if(vis[i])vs.push_back(col[i]);
	}
	std::sort(vs.begin(),vs.end());
	l=std::unique(vs.begin(),vs.end())-vs.begin();
	for(i = 0; i < l; i++) {
		for(j = i+1; j < l; j++) {
			if(dis[col[i]][col[j]]==0) {
				++sr,anss=inf,tu=j;
				dfss(i,0);
				dis[i][j]=anss;
			}
			k-=dis[i][j];
		}
	}
	if(k<0)k=0;
	ans=(ans+(1ll<<k))%mod;
}
void dfs(int now) {
	if(now>n) {
		check();
		return;
	}
	vis[now]=1;
	dfs(now+1);
	vis[now]=0;
	dfs(now+1);
}
int main() {

	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);

	n=read();
	m=read();
	int i,u,v;
	for(i = 1; i <= m; i++) {
		u=read();
		v=read();
		add(u,v);
		add(v,u);
	}
	tarjan(1,0);
	if(!s.empty()) {
		scc++;
		while(!s.empty()) {
			col[s.top()]=scc;
			vis[s.top()]=0;
			s.pop();
		}
	}
	for(i = 1; i <= n; i++) {
		for(u = node[i].first; u; u = edge[u].next) {
			v=edge[u].to;
			if(col[i]!=col[v])ad(col[i],col[v]);
		}
	}
	memset(vis,0,sizeof(vis));
	dfs(1);
	printf("%lld\n",ans);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
