#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7,N=2e6+1;;
int to[N],first[N],nex[N];
int f[N],r[N],wei[N];
int topf[N],dfn[N],co[N],st[N],in[N];
int base[N],pre[N],side[N];
int fn[3001][10001];
int cnt,cntt,top;
int n,m;

int ans;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0') {if(c=='0') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
void add(int x,int y){
	to[++cnt]=y;
	nex[cnt]=first[x];
	first[x]=cnt;
	return;
}
void pree(){
	pre[0]=1;
	for(int i=1;i<N;i++) pre[i]=pre[i-1]*2%mod;
	return;
}
void tarjan(int u,int fa){
	dfn[u]=++cnt;topf[u]=dfn[u];st[++top]=u;
	for(int i=first[u];i!=0;i=nex[i]){
		int v=to[i];
		if(v==fa) continue;
		if(!dfn[v]){
			tarjan(v,u);
			topf[u]=min(topf[v],topf[u]);
		}
		else
		 topf[u]=min(topf[v],topf[u]);
	}
	if(dfn[u]==topf[u]){
		co[u]=++cntt;
		while(st[top]!=u){
			co[st[top]]=cntt;
			top--;
		}
		top--;
	}
	return;
}
void dfs(int u,int fa){
	fn[u][wei[u]]=1;
	for(int i=first[u];i!=0;i=nex[i]){
		int v=to[i];
		if(v==fa) continue;
		dfs(v,u);
		for(int i=wei[u];i>=0;i--)
		 for(int j=1;j<=wei[v];j++){
		  fn[u][i+j]+=fn[u][i]*fn[v][j]%mod;
		  fn[u][i+j]%=mod;
	     }
		wei[u]+=wei[v];side[u]+=side[v];
	}
	for(int i=1;i<=wei[u];i++)
	 ans=(ans+(pre[i]-1)*fn[u][i]%mod*pre[side[u]]%mod)%mod;
	
	return;
}
signed main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	pree();
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		add(x,y);add(y,x);
	}
	cnt=0;
	tarjan(1,0);
	cnt=0;top=0;
	for(int i=1;i<=n;i++){
		for(int j=first[i];j!=0;j=nex[j]){
			int v=to[j];
			if(co[i]!=co[v]) f[++top]=co[i],r[top]=co[v];
			else side[co[i]]++;
		}
		wei[co[i]]+=1;
	}
	n=cntt;cnt=0;
	for(int i=1;i<=n;i++) side[i]/=2;
	memset(first,0,sizeof(first));
	for(int i=1;i<=top;i++)
	 add(f[i],r[i]);
	dfs(1,0);
	cout<<ans;
	return 0;
}
