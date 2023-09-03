#include <cstdio>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T1,typename T2> void cmin(T1 &a,const T2 &b){if(a>b)a=b;}
template<typename T1,typename T2> void cmax(T1 &a,const T2 &b){if(a<b)a=b;}

const int N=500005,M=1000005;
constexpr int P=1000000007;

int p2[M];
int n,m;
vector<pii> e;
vector<pii> edge[N];
vector<int> tedge[N];

int dcnt,dfn[N],low[N],b[M];
void tarjan(int x,int p){
	dfn[x]=low[x]=++dcnt;
	for(auto [y,i]:edge[x]){
		if(i==p)
			continue;
		if(!dfn[y]){
			tarjan(y,i);
			if(dfn[x]<low[y])
				b[i]=1;
			else
				cmin(low[x],low[y]);
		}else{
			cmin(low[x],dfn[y]);
		}
	}
}

int ccnt,c[N];
int ncnt[N],ecnt[N];

void dfs_c(int x){
	c[x]=ccnt;
	++ncnt[ccnt];
	for(auto [y,i]:edge[x]){
		if(c[y] || b[i])
			continue;
		dfs_c(y);
	}
}

int f[N][3],g[N];
void dfs(int x,int p){
	for(int y:tedge[x]){
		if(y==p)
			continue;
		dfs(y,x);
	}
	int s=1;
	for(int y:tedge[x]){
		if(y==p)
			continue;
		g[y]=s;
		s=(ll)s*f[y][0]%P;
	}
	reverse(tedge[x].begin(),tedge[x].end());
	s=1;
	for(int y:tedge[x]){
		if(y==p)
			continue;
		g[y]=(ll)g[y]*s%P;
		s=(ll)s*f[y][0]%P;
	}
	reverse(tedge[x].begin(),tedge[x].end());
	f[x][0]=p2[ecnt[x]];
	int o=0,s1=1,s2=1;
	for(int y:tedge[x]){
		if(y==p)
			continue;
		f[x][0]=(ll)f[x][0]*f[y][0]*2%P;
		s1=(ll)s1*((ll)f[y][0]*2+f[y][1])%P;
		s2=(ll)s2*((ll)f[y][0]*2)%P;
		f[x][2]=(f[x][2]+(f[y][1]+(ll)f[y][2]*2)*g[y])%P;
		++o;
	}
	f[x][1]=((ll)p2[ncnt[x]]*s1-s2+P)%P*p2[ecnt[x]]%P;
	if(f[x][2])
		f[x][2]=(ll)f[x][2]*p2[o-1+ecnt[x]]%P;
}

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	p2[0]=1;
	for(int i=1;i<M;++i)
		p2[i]=p2[i-1]*2%P;
	scanf("%d%d",&n,&m);
	e.reserve(m);
	for(int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
		edge[u].emplace_back(v,i);
		edge[v].emplace_back(u,i);
		e.emplace_back(u,v);
	}
	tarjan(1,0);
	for(int i=1;i<=n;++i)
		if(!c[i]){
			++ccnt;
			dfs_c(i);
		}
	for(auto [u,v]:e)
		if(c[u]!=c[v]){
			tedge[c[u]].push_back(c[v]);
			tedge[c[v]].push_back(c[u]);
		}else{
			++ecnt[c[u]];
		}
	for(int i=1;i<=ccnt;++i){
		sort(tedge[i].begin(),tedge[i].end());
		tedge[i].resize(unique(tedge[i].begin(),tedge[i].end())-tedge[i].begin());
	}
	if(ccnt==1){
		printf("%d\n",int((ll)(p2[ncnt[1]]-1)*p2[ecnt[1]]%P));
		return 0;
	}
	dfs(1,0);
//	for(int i=1;i<=ccnt;++i)
//		printf("%d %d %d\n",f[i][0],f[i][1],f[i][2]);
	printf("%d\n",int((f[1][1]+f[1][2])%P));
	return 0;
}
