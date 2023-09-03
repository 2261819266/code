#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int N=5e5+5,M=1e6+5,P=1e9+7;
template<class R>
void read(R &x){
	char c=getchar();
	for(;c<48||c>57;c=getchar());
	for(x=0;c>47&&c<58;c=getchar())x=(x<<1)+(x<<3)+(c^48);
}
int n,m,p2[M],dfn[N],low[N],F[N],sz[N],esz[N],ans=1,cnt,f[N][3];
int b[N],cb,pr[N],su[N],f2[N];
int hd[N],to[2*M],nx[2*M],num=1;
bool cut[M],vis[N];
vector<int>e[N];
void add(int x,int y){
	nx[++num]=hd[x],hd[x]=num,to[num]=y;
}
void adde(int x,int y){
	x=F[x],y=F[y];
	e[x].push_back(y);
	e[y].push_back(x);
}
void tarjan(int x,int y){
	dfn[x]=low[x]=++cnt;
	for(int i=hd[x],v;v=to[i],i;i=nx[i])if(v!=y){
		if(!dfn[v]){
			tarjan(v,x);
			low[x]=min(low[x],low[v]);
			if(low[v]>dfn[x])cut[i>>1]=true;
		}else low[x]=min(low[x],dfn[v]);
	}
}
void Dfs(int x,int y){
	vis[x]=true,F[x]=y,++sz[y];
	for(int i=hd[x],v;v=to[i],i;i=nx[i])if(!cut[i>>1]&&!vis[v])Dfs(v,y); 
}
void dfs(int x,int y){
	ans=1ll*ans*p2[esz[x]]%P;
	int s0=1,s1=1;
	for(auto v:e[x])if(v!=y){
		dfs(v,x);
		s0=2ll*s0*f[v][0]%P,s1=1ll*s1*(2ll*(f[v][0]+f[v][1])%P+f[v][2])%P;
	}
	f[x][1]=(s1-s0+P)%P;
	f[x][0]=s0;
	if(x==F[1]){
		cb=0;
		//printf("?%d %d %d %d %d\n",x,f[x][0],f[x][1],f[x][2],sz[x]);
		int sum=(1ll*f[x][1]*p2[sz[x]]%P+1ll*f[x][0]*(p2[sz[x]]-1)%P)%P;
		for(auto v:e[x])b[++cb]=(2ll*(f[v][0]+f[v][1])%P+f[v][2])%P,f2[cb]=f[v][2];
		pr[0]=su[cb+1]=1;
		for(int i=1;i<=cb;++i)pr[i]=1ll*pr[i-1]*b[i]%P;
		for(int i=cb;i;--i)su[i]=1ll*su[i+1]*b[i]%P;
		for(int i=1;i<=cb;++i)sum=(sum+1ll*pr[i-1]*su[i+1]%P*f2[i]%P)%P;
		ans=1ll*ans*sum%P;
		return;
	}
	cb=0;
	for(auto v:e[x])if(v!=y)b[++cb]=(2ll*(f[v][0]+f[v][1])%P+f[v][2])%P,f2[cb]=f[v][2];
	pr[0]=su[cb+1]=1;
	for(int i=1;i<=cb;++i)pr[i]=1ll*pr[i-1]*b[i]%P;
	for(int i=cb;i;--i)su[i]=1ll*su[i+1]*b[i]%P;
	for(int i=1;i<=cb;++i)f[x][2]=(f[x][2]+1ll*pr[i-1]*su[i+1]%P*f2[i]%P)%P;
	f[x][2]=(1ll*s1*(p2[sz[x]]-1)%P+f[x][2])%P;
	//printf("?%d %d %d %d\n",x,f[x][0],f[x][1],f[x][2]);
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	p2[0]=1;
	for(int i=1;i<=m;++i)p2[i]=2ll*p2[i-1]%P;
	for(int i=1,x,y;i<=m;++i){
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	tarjan(1,0);
	for(int i=1;i<=n;++i)if(!vis[i])Dfs(i,i);
	for(int i=1;i<=m;++i){
		if(cut[i])adde(to[i<<1],to[i<<1|1]);
		else ++esz[F[to[i<<1]]];
	}
	dfs(F[1],0);
	printf("%d\n",ans);
	return 0;
}
