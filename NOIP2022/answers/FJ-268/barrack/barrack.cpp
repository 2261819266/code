#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
int n,m,head[500005],hc[500005],dfn[500005],low[500005],c[500005],siz[500005],w[500005],cnt,tot=1,num,dcc;
long long f[500005][2];
bool bridge[2000005],vis[500005];
struct edge{
	int to,nxt;
}e[2000005],ec[2000005];
inline int read(){
	int x=0,ff=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')ff=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*ff;
}
inline void add(int u,int v){
	e[++tot].nxt=head[u];
	e[tot].to=v;
	head[u]=tot;
}
inline void adde(int u,int v){
	ec[++cnt].nxt=hc[u];
	ec[cnt].to=v;
	hc[u]=cnt;
}
inline void tarjan(int u,int in_edge){
	low[u]=dfn[u]=++num;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(!dfn[v]){
			tarjan(v,i);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){
				bridge[i]=bridge[i^1]=1;
			}
		}else{
			if(i!=(in_edge^1)){
				low[u]=min(low[u],dfn[v]);
			}
		}
	}
}
inline void dfs(int u){
	c[u]=dcc;
	siz[dcc]++;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(bridge[i])continue;
		if(c[u]==c[v]){
			w[c[u]]++;
			continue;
		}
		dfs(v);
	}
}
inline long long qpow(long long a,int b){
	long long sum=1;
	while(b){
		if(b&1)sum=1ll*a*sum%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return sum;
}
inline void dp(int u){
	vis[u]=1;
	f[u][1]=(1ll*(qpow(2,siz[u])-1+mod)%mod*qpow(2,w[u]))%mod;
	f[u][0]=qpow(2,w[u]);
	for(int i=hc[u];i;i=ec[i].nxt){
		int v=ec[i].to;
		if(vis[v])continue;
		dp(v);
		f[u][1]=1ll*(f[v][1]+1ll*2*f[v][0])%mod*f[u][1]%mod;
		f[u][0]=1ll*2*f[u][0]%mod*((f[v][1]+f[v][0])%mod)%mod;
	}
}
inline void pt(){
	printf("%d\n",dcc);
//	for(int i=1;i<=n;i++){
//		printf("%d ",c[i]);
//	}
	for(int i=1;i<=dcc;i++){
		printf("%d %d\n",siz[i],w[i]);
	}
}
int main(){
//	freopen("barrack.in","r",stdin);
//	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	tarjan(1,0);
	for(int i=1;i<=n;i++){
		if(!c[i]){
			++dcc;
			dfs(i);
			if(w[c[i]]){
				w[c[i]]--;
			}
		}
	}
	for(int i=2;i<=tot;i+=2){
		if(bridge[i]){
			adde(c[e[i].to],c[e[i^1].to]);
			adde(c[e[i^1].to],c[e[i].to]);
		}
	}
//	pt();
	dp(1);
	printf("%lld\n",(1ll*(f[1][0]+f[1][1])%mod-qpow(2,m)+mod)%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
9 10
1 2
1 3
2 4
4 5
5 6
6 2
3 7
3 8
3 9
8 9
*/
