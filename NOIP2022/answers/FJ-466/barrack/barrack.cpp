#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define mod 1000000007
#define ll long long
using namespace std;
struct Node{
	ll v,num;
};
vector<Node> l[1000001];
vector<ll> ne[1000001];
Node edg[1000001];
ll dfn[1000001],low[1000001];
ll vis[1000001],num[1000001];
ll siz[1000001],esiz[1000001];
ll son[1000001];
ll tot,all;
void dfs(ll x,ll fa){
	dfn[x]=low[x]=++tot;
	for(ll i=0;i<l[x].size();i++){
		ll v=l[x][i].v;
		if(v==fa) continue;
		if(!dfn[v]){
			dfs(v,x);
			if(low[v]>=dfn[x]) vis[l[x][i].num]++;
			low[x]=min(low[x],low[v]);
		}
		else low[x]=min(low[x],dfn[v]);
	}
}
ll quickpow(ll a,ll x){
	if(x==0) return 1;
	ll b=a;x--;
	while(x){
		if(x&1) b=(b*a)%mod;
		a=(a*a)%mod;
		x>>=1;
	}
	return b; 
}
void dfs2(ll x){
	siz[num[x]]++;
	for(ll i=0;i<l[x].size();i++){
		ll v=l[x][i].v;
		if(vis[l[x][i].num] || num[v]) continue;
		num[v]=num[x];
		dfs2(v);
	}
}
ll dp[1000001][2];
void dfs3(ll x,ll fa){
	if(x==1)son[x]=ne[x].size();
	else son[x]=ne[x].size()-1;
	dp[x][0]=quickpow(2,esiz[x]);
	dp[x][1]=(((quickpow(2,siz[x])-1+mod)%mod)*quickpow(2,esiz[x]))%mod;
	for(ll i=0;i<ne[x].size();i++){
		if(fa==l[x][i].v) continue;
		int v=l[x][i].v;
		dfs3(v,x);
		dp[x][0]=(dp[x][0]+2*((dp[v][0]+dp[v][1])%mod))%mod;
		dp[x][1]=(dp[x][1]*(dp[v][1]+dp[v][0]*2))%mod;
	}
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	ll n,m,u,v;
	cin>>n>>m;
	for(ll i=1;i<=m;i++){
		cin>>u>>v;
		l[u].push_back((Node){v,i});
		l[v].push_back((Node){u,i});
		edg[i].num=u;edg[i].v=v;
	}
	dfs(1,0);
	for(ll i=1;i<=n;i++){
		if(!num[i]){
			num[i]=++all;
			dfs2(i);
		}
	}
	for(ll i=1;i<=m;i++){
		if(num[edg[i].num]==num[edg[i].v]) esiz[num[edg[i].num]]++;
		else{
			ne[num[edg[i].num]].push_back(num[edg[i].v]);
			ne[num[edg[i].v]].push_back(num[edg[i].num]);
		}
	}
	dfs3(1,0);
	cout<<(dp[1][0]+dp[1][1])%mod;
	return 0;
}
