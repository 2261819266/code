#include<bits/stdc++.h>
#define int long long
#define re register
#define il inline
#define For(i,a,b) for(re int i=a;i<=b;++i)
using namespace std;
const int N = 5e5+5,M = 1e6+5,P = 1e9+7;
struct edge{
	int from,to,next;
}e[M<<1];
struct edge2{
	int to,next;
}e2[M<<1];
int head2[N],cnt2;
int head[N],cnt=1;
int T,n,m;
int dfn[N],low[N],num,col;
int belong[N],bian[N],dian[N];
int st[N],top;
int a[N][2],dp[N][2][2];
int ans,MM;
bool vis[N];
il int read(){
	int x=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
		if(c=='-') f=-1;
	for(;isdigit(c);c=getchar())
		x=(x<<1)+(x<<3)+c-48;
	return x*f;
}
il void add(int u,int v){
	e[++cnt]=(edge){u,v,head[u]};
	head[u]=cnt;
}
il void add2(int u,int v){
	e2[++cnt2]=(edge2){v,head2[u]};
	head2[u]=cnt2;
}
il int ksm(int a,int b){
	re int res=1;
	while(b){
		if(b&1) res=res*a%P;
		a=a*a%P;
		b>>=1;
	}
	return res;
}
il void tarjan(int u,int fa){
	dfn[u]=low[u]=++num;
	st[++top]=u;
	vis[u]=1;
	for(re int i=head[u];i;i=e[i].next){
		re int v=e[i].to;
		if(v==fa) continue;
		if(!dfn[v]){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		++col;
		dian[col]=top;
		while(st[top]!=u){
			re int v=st[top];
			vis[v]=0;
			belong[v]=col;
			--top;
		}
		vis[u]=0;
		belong[u]=col;
		--top;
		dian[col]-=top;
	}
}
int dfs(int u,int fa){
	re int M=1;
	dp[u][1][1]=a[u][1];
	dp[u][0][0]=dp[u][0][1]=a[u][0];
	for(re int i=head2[u];i;i=e2[i].next){
		re int v=e2[i].to;
		if(v==fa) continue;
		M+=dfs(v,u);
		dp[u][1][1]=((dp[v][1][1]+dp[v][0][1])%P+2*dp[v][0][0]%P)%P*dp[u][1][1]%P;
		dp[u][0][0]=dp[u][0][0]*dp[v][0][0]%P*2%P;
		dp[u][0][1]=((dp[v][1][1]+dp[v][0][1])%P+dp[v][0][0]*2)%P*dp[u][0][1]%P;
	}
	dp[u][0][1]=((dp[u][0][1]-dp[u][0][0])%P+P)%P;
	if(u!=1) ans=(ans+(dp[u][1][1]+dp[u][0][1])%P*ksm(2,MM-M)%P)%P;
	return M;
}
signed main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read();
	m=read();
	For(i,1,m){
		re int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	tarjan(1,0);
	for(re int i=2;i<=cnt;i+=2){
		re int a=belong[e[i].from],b=belong[e[i].to];
		if(a==b) ++bian[a];
		else add2(a,b),add2(b,a),++MM;
	}
	For(i,1,col){
		a[i][0]=ksm(2,bian[i]);
		a[i][1]=((ksm(2,bian[i]+dian[i])-a[i][0])%P+P)%P;
	}
	dfs(1,0);
	cout<<(ans+dp[1][1][1]+dp[1][0][1])%P;
	return 0;
}

