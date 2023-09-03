#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,P=1e9+7;
int n,m,u[N<<1],v[N<<1],dfn[N],low[N],num,c[N],cnt,hd[N],tot=1,t[N<<2],siz[N],fc[N<<2],f[N],g[N],ans;
struct edge{int to,nxt,f;}e[N<<2];
vector<int> r[N];
void add(int x,int y){e[++tot]={y,hd[x]},hd[x]=tot;}
void Tarjan(int x,int f){
	dfn[x]=low[x]=++num;
	for(int i=hd[x],y;y=e[i].to,i;i=e[i].nxt){
		if(!dfn[y]){
			Tarjan(y,i),low[x]=min(low[x],low[y]);
			if(low[y]>dfn[x])t[i]=t[i^1]=1;
		}else if(f^i^1)low[x]=min(low[x],dfn[y]);
	}
}
void dfs(int x,int co){
	c[x]=co,++siz[co];
	for(int i=hd[x],y;y=e[i].to,i;i=e[i].nxt)if(!t[i]&&!c[y])dfs(y,co);
}
void calc(int x,int fa){
	f[x]=g[x]=1;
	for(int y:r[x])if(y!=fa)calc(y,x),f[x]=1ll*f[x]*(f[y]+1)%P,g[x]=1ll*g[x]*(g[y]+1)%P;
	f[x]=1ll*f[x]*fc[m+siz[x]-r[x].size()+(x!=1)]%P,g[x]=1ll*g[x]*fc[m-r[x].size()+(x!=1)]%P;
	ans=(ans+1ll*fc[m+m-(x!=1)]*(P+f[x]-g[x]))%P;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)scanf("%d%d",&u[i],&v[i]),add(u[i],v[i]),add(v[i],u[i]);
	Tarjan(1,0);
	for(int i=1;i<=n;++i)if(!c[i])dfs(i,++cnt);
	for(int i=1;i<=m;++i)if(c[u[i]]!=c[v[i]])r[c[u[i]]].push_back(c[v[i]]),r[c[v[i]]].push_back(c[u[i]]);
	for(int i=fc[m]=1,j=5e8+4;i<=m;++i)fc[m+i]=2ll*fc[m+i-1]%P,fc[m-i]=1ll*fc[m-i+1]*j%P;
	calc(1,0);
	printf("%d\n",ans);
	return 0;
}
