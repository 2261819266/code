#include <bits/stdc++.h>
using namespace std;
#define int long long

inline int read(){
	int x=0;
	bool f=0;
	char ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-') f=1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9'){
		x=x*10+(ch^48);
		ch=getchar();
	}
	return (f?-x:x);
}

inline void write(int x){
	if (x<0) putchar('-'), x=-x;
	if (x>9) write(x/10);
	putchar(x%10+48);
}

bool ST;

const int N=2e6+10,inf=0x7fffffff,mod=1e9+7;
int n,m;
int pow2[N];
int ecnt1=1,head1[N],to1[N],nxt1[N];
int dfncnt,dfn[N],low[N],dccid,dcc[N];
bool cut[N];
int ncnt[N],mcnt[N];
//vector <int> dccv;
int ecnt2=1,head2[N],to2[N],nxt2[N];
int f[N][2];
unordered_map<int,unordered_map<int,bool> > mp;

inline void add_edge1(int u,int v){
	to1[++ecnt1]=v;
	nxt1[ecnt1]=head1[u];
	head1[u]=ecnt1;
}

void tarjan(int u,int fa){
	dfn[u]=low[u]=++dfncnt;
	int i,v;
	for (i=head1[u];i;i=nxt1[i]){
		v=to1[i];
		if (!dfn[v]){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if (dfn[u]<low[v]) cut[i]=cut[i^1]=1;
		}
		else if (v!=fa) low[u]=min(low[u],dfn[v]);
	}
}

void dcc_dfs(int u){
	dcc[u]=dccid;
	int i;
	for (i=head1[u];i;i=nxt1[i]){
		if (cut[i] || dcc[to1[i]]) continue;
		dcc_dfs(to1[i]);
	}
}

inline void add_edge2(int u,int v){
	to2[++ecnt2]=v;
	nxt2[ecnt2]=head2[u];
	head2[u]=ecnt2;
}

void dfs(int u,int fa){
	cerr<<u<<endl;
	int i,v,child=0;
	for (i=head2[u];i;i=nxt2[i]){
		v=to2[i];
		if (v==fa) continue;
		dfs(v,u);
		child++;
		f[u][0]+=2*(f[v][0]+f[v][1]);
		f[u][1]+=f[v][1]+f[v][0]*2;
	}
	if (!child) f[u][0]=1;
	f[u][0]*=pow2[mcnt[u]];
	f[u][1]*=(pow2[ncnt[u]]-1)*(mcnt[u]+1);
	cerr<<u<<' '<<f[u][0]<<' '<<f[u][1]<<endl;
}

bool ED;

signed main(){
//	cerr<<(&ST-&ED)/1024.0/1024.0<<endl;
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(), m=read();
	int i,u,v;
	pow2[0]=1;
	for (i=1;i<=2e6;i++) pow2[i]=pow2[i-1]*2%mod;
	for (i=1;i<=m;i++){
		u=read(), v=read();
		add_edge1(u,v), add_edge1(v,u);
	}
	for (i=1;i<=n;i++) if (!dfn[i]) tarjan(i,0);
	for (i=1;i<=n;i++) if (!dcc[i]) dccid++, dcc_dfs(i);
	for (i=1;i<=n;i++) ncnt[dcc[i]]++;
	for (i=1;i<=m;i++) if (dcc[to1[i]]==dcc[to1[i^1]]) mcnt[dcc[to1[i]]]++;
	for (i=1;i<=m;i++) if (dcc[to1[i]]!=dcc[to1[i^1]] && !mp[dcc[to1[i]]][dcc[to1[i^1]]]) cerr<<"ok"<<endl,mp[dcc[to1[i]]][dcc[to1[i^1]]]=1, add_edge2(dcc[to1[i]],dcc[to1[i^1]]), add_edge2(dcc[to1[i^1]],dcc[to1[i]]);
//	cerr<<dccid<<endl;
//	for (i=1;i<=n;i++) cerr<<dcc[i]<<endl;
	dfs(1,0);
	write(f[1][0]+f[1][1]-pow2[m]);
	return 0;
}
