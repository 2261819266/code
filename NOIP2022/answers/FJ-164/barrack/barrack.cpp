#include<iostream>
#include<cstdio>
const int maxn=5e5+10;
const int maxm=1e6+10;
const int mod=1e9+7;
int read(){
	int sum=0,sg=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')sg=-1; ch=getchar();}
	while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-'0',ch=getchar();
	return sum*sg;
}
int head[maxn],eid;
struct Edge{int nxt,to;}E[maxm<<1];
void add(int u,int v){E[++eid]={head[u],v},head[u]=eid;}
int n,m;
long long ans;
namespace solve1{
bool vis[maxn],kv[maxn],ke[maxm];
void dfs(int u){
	vis[u]=1;
	for(int i=head[u];i;i=E[i].nxt){
		int v=E[i].to;
		if(ke[(i+1)/2]&&!vis[v])dfs(v);
	}
}
bool check(){
	int rt=0;
	for(int i=1;i<=n;++i)
		if(kv[i]){rt=i; break;}
	for(int i=1;i<=n;++i)vis[i]=0;
	dfs(rt);
	for(int i=1;i<=n;++i)
		if(kv[i]&&!vis[i])return false;
	return true;
}
void dfs2(int cur){
	if(cur==m+1){
		if(check()){
			++ans;	
		}
		return;
	}
	ke[cur]=1,dfs2(cur+1);
	ke[cur]=0,dfs2(cur+1);
}
void dfs1(int cur,int num){
	if(cur==n+1){
		if(!num)return;
		dfs2(1);
		return;
	}
	kv[cur]=1,dfs1(cur+1,num+1);
	kv[cur]=0,dfs1(cur+1,num);
}
void main(){
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	dfs1(1,0);
	printf("%lld\n",ans);
	return;
}
}
namespace solve2{
int dfn_id,dfn[maxn],low[maxn],stk[maxn],deg[maxn],top;
long long pwr[maxm];
void Tarjan(int u,int fa){
	dfn[u]=low[u]=++dfn_id,stk[++top]=u;
	for(int i=head[u];i;i=E[i].nxt){
		int v=E[i].to;
		if(!dfn[v]){
			Tarjan(v,u);
			low[u]=std::min(low[u],low[v]);
			if(low[v]>dfn[u]){
				long long vu=0,eu=0,vd=0,ed=0;
				while(1){
					int x=stk[top--];
					++vd,ed+=deg[x];
					if(x==v)break;
				}
				ed=(ed-1)/2;
				vu=n-vd,eu=m-ed-1;
				long long numu=pwr[eu]*(pwr[vu]-1)%mod,numd=pwr[ed]*(pwr[vd]-1)%mod;
				ans=(ans+numu*numd%mod)%mod;
			}
		}
		else if(v!=fa)low[u]=std::min(low[u],dfn[v]);
	}
}
void main(){
	pwr[0]=1; for(int i=1;i<=1000000;++i)pwr[i]=pwr[i-1]*2%mod;
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		add(u,v),add(v,u);
		++deg[u],++deg[v];
	}
	Tarjan(1,0);
	ans=(pwr[m]*(pwr[n]-1)%mod-ans)%mod;
	printf("%lld\n",(ans+mod)%mod);
	return;
}
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	if(n<=8)solve1::main();
	else solve2::main();
	return 0;
}
