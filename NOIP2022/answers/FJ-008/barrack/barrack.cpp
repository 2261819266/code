#include<bits/stdc++.h>
using namespace std;
#define maxn 500009
#define maxm 1000009
#define pb push_back
int n,m,clr[maxn],siz[maxn],cnt[maxn],sonsiz[maxn];
const long long mod=1e9+7,inv2=(mod+1)/2;
long long dp[maxn][2],pwtwo[maxm],ans=0;
int tot=0,vis[maxn];
vector<int > to[maxn],tre[maxn];
inline int read(){
	int sum=0,d=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')d=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*d;
}
void build(int now,int f=0){
	vis[now]=++tot;
	for(auto v:to[now])if(v!=f){
		if(!vis[v])build(v,now);
		else if(vis[v]<vis[now])cnt[v]--,cnt[now]++;
	}
	return ;
}
void dfs(int now,int f=0){
	vis[now]=++tot;
	for(auto v:to[now])if(!vis[v]){
		dfs(v,now);cnt[now]+=cnt[v];
	}
	return ;
}
void work(int now,int f=0){
	vis[now]=++tot;
	if(cnt[now]==0)clr[now]=now,tre[clr[f]].pb(now);
	else clr[now]=clr[f];
	siz[clr[now]]++;
	for(auto v:to[now])if(!vis[v]){
		work(v,now);
	}
	return ;
}
void slove(int now,int f=0){
	sonsiz[now]=1;
	dp[now][1]=(pwtwo[siz[now]]-1+mod)%mod;dp[now][0]=1;
	for(auto v:tre[now])if(v!=f){
		slove(v,now);sonsiz[now]+=sonsiz[v];
		dp[now][1]=(dp[now][1]*dp[v][0]%mod*2%mod+(dp[now][1]+dp[now][0])%mod*dp[v][1]%mod)%mod;
		dp[now][0]=dp[now][0]*dp[v][0]%mod*2%mod;
	}
	return ; 
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read();m=read();
	pwtwo[0]=1;for(int i=1;i<=max(m,n);i++)pwtwo[i]=pwtwo[i-1]*2%mod;
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		to[u].pb(v);to[v].pb(u);
	}
	build(1);
	for(int i=1;i<=n;i++)vis[i]=0;
	tot=0;
	dfs(1);
	for(int i=1;i<=n;i++)vis[i]=0;
	tot=0;
	work(1);slove(1);
	for(int i=1;i<=n;i++)if(clr[i]==i){
		ans+=dp[i][1]*pwtwo[max(sonsiz[1]-sonsiz[i]-1,0)]%mod;ans%=mod;
	}
	ans=ans*pwtwo[m-sonsiz[1]+1]%mod;
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

