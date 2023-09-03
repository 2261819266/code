#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e6+5,mod=1e9+7;
ll n,m,dfn[N],dfv[N],cnt,fd,st[N],top,dp[N][4],ans;
vector<int>ed[N],ed2[N];

int read(){
	int x=0,fs=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') fs=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar(); 
	return x*fs;
}

void tarjan(int u,int fa){
	dfn[u]=dfv[u]=++cnt;
	st[++top]=u;
	for(auto v:ed[u]){
		if(v==fa) continue;
		if(!dfn[v]){
			tarjan(v,u); dfv[u]=min(dfv[u],dfv[v]);
			if(dfv[v]==dfn[u]){
				fd++;
				while(st[top+1]!=v){
					ed2[st[top]].push_back(fd); ed2[fd].push_back(st[top]); top--;
				}
				ed2[u].push_back(fd); ed2[fd].push_back(u); continue;
			}
			if(dfv[v]>dfn[u]){
//				if(st[top]!=v) cerr<<"afdsaads";
				while(st[top+1]!=v) top--;
				ed2[u].push_back(v); ed2[v].push_back(u);
			}
		}else{
			dfv[u]=min(dfv[u],dfn[v]);
		}
	}
	return;
}

void dfs(int u,int fa){
	dp[u][0]=1;
	for(auto v:ed2[u]){
		if(v==fa) continue;
		dfs(v,u);
//		cerr<<dp[u][2]<<" "<<(dp[u][1]+dp[u][2])*(dp[v][1])<<"\n";
		dp[u][3]=(dp[u][3]+dp[v][3]*2)%mod;
		dp[u][2]=(dp[u][2]*dp[v][0]*2+(dp[u][1]+dp[u][2])*dp[v][1])%mod; dp[u][1]=(dp[u][1]*dp[v][0]*2+dp[u][0]*dp[v][1])%mod;
		dp[u][0]=dp[u][0]*dp[v][0]*2;
	}
	if(u<=n){
//	cerr<<u<<" "<<dp[u][0]<<" "<<dp[u][1]<<" "<<dp[u][2]<<" "<<dp[u][3]<<" "<<ans<<"\n";
//		ans=(ans+dp[u][0]+dp[u][1]+dp[u][2]*2)%mod;
		dp[u][3]=(dp[u][3]+dp[u][0]+dp[u][1]+dp[u][2])%mod;
		dp[u][1]=(dp[u][0]+dp[u][1]*2+dp[u][2]*2)%mod;
	}else{
//	cerr<<u<<" "<<dp[u][0]<<" "<<dp[u][1]<<" "<<dp[u][2]<<" "<<dp[u][3]<<" "<<ans<<"\n";
//		ans=(ans+dp[u][2])%mod;
		dp[u][3]=(dp[u][3])%mod;
		dp[u][1]=(dp[u][1]+dp[u][2])%mod; dp[u][2]=0;
	}
	return;
}

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(); m=read(); fd=n;
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		ed[u].push_back(v); ed[v].push_back(u);
	}
	tarjan(1,0);
//	for(int i=1;i<=n;i++){
//		cerr<<"   "<<i<<" "<<ed2[i].size()<<"\n";
//		for(auto j:ed2[i]) cerr<<j<<"\n";
//	}
	dfs(1,0);
	printf("%lld",dp[1][3]);
	return 0;
}
