#include<bits/stdc++.h>
using namespace std;
#define maxn 1000001
#define inf 99999999999999999
#define ll long long
#define mod 1000000007
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-48;ch=getchar();}
	return x*f;
}
struct edge{
	ll to,nxt;
}e[maxn*4],e2[maxn*4];
ll n,m,tot=1,fir[maxn];
ll tot2=0,fir2[maxn];
ll dfn[maxn],low[maxn],cnt=0;
ll num=0,vis[maxn],bel[maxn],ednum[maxn],dp[maxn][2];
ll mi[maxn];
vector<ll> bk[maxn];
bool cut[maxn*4];
void add(ll a,ll b){
	e[++tot].to=b;
	e[tot].nxt=fir[a];
	fir[a]=tot;
}
void add2(ll a,ll b){
	e2[++tot2].to=b;
	e2[tot2].nxt=fir2[a];
	fir2[a]=tot2;
}
void tarjan(ll now,ll fro){
	dfn[now]=++cnt,low[now]=cnt;
	for(ll i=fir[now];i;i=e[i].nxt){
		if(i==(fro^1)) continue;
		ll v=e[i].to;
		if(!dfn[v]){
			tarjan(v,i);
			low[now]=min(low[now],low[v]);
			if(low[v]>dfn[now]){
				cut[i]=1,cut[i^1]=1;
			}
		}
		else low[now]=min(low[now],dfn[v]);
	}
	return;
}
void dfs(ll now,ll fa){
	if(vis[now]) return;
	vis[now]=1,bk[num].push_back(now),bel[now]=num;
	for(ll i=fir[now];i;i=e[i].nxt){
		ll v=e[i].to;
		if(v==fa||cut[i]) continue;
		dfs(v,now);
	}
	return;
}
ll ksm(ll di,ll mi){
	ll sum=1;
	while(mi){
		if(mi&1) sum=sum*di%mod;
		di=di*di%mod,mi=mi>>1;
 	}
 	return sum;
}
void dfs2(ll now,ll fa){
	ll son=0;
	for(ll i=fir2[now];i;i=e2[i].nxt){
		ll v=e2[i].to;
		if(v==fa) continue;
		son++;
		dfs2(v,now);
	}
	ll now1=mi[ednum[now]],now2=((mi[bk[now].size()]-1)%mod+mod)%mod*mi[ednum[now]]%mod;
	if(!son){
		dp[now][0]=now1;
		dp[now][1]=now2;
	}
	else{
		ll sum1=1,sum2=1,sum3=0;
		for(ll i=fir2[now];i;i=e2[i].nxt){
		    ll v=e2[i].to;
		    if(v==fa) continue;
		    sum1=sum1*((dp[v][1]+dp[v][0]*2)%mod)%mod;
		    sum2=sum2*dp[v][0]%mod;
	    }
	    for(ll i=fir2[now];i;i=e2[i].nxt){
		    ll v=e2[i].to;
		    if(v==fa) continue;
		    sum3=(sum3+sum2*ksm(dp[v][0],mod-2)%mod*dp[v][1]%mod*mi[son-1]%mod)%mod;
	    }
	    sum2=sum2*mi[son]%mod;
	    dp[now][0]=sum2*now1%mod;
	    dp[now][1]=(sum1*now2%mod)+((sum1+sum3-sum2)%mod+mod)%mod*now1%mod;
	    dp[now][1]=dp[now][1]%mod;
	}
	return;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	for(ll i=1;i<=m;i++){
		ll x=read(),y=read();
		add(x,y),add(y,x);
	}
	for(ll i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i,0);
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]) num++,dfs(i,0);
	}
	for(ll i=1;i<=n;i++){
		for(ll j=fir[i];j;j=e[j].nxt){
			ll v=e[j].to;
			if(bel[i]==bel[v]) ednum[bel[i]]++;
			else add2(bel[i],bel[v]);
		}
	}
	for(ll i=1;i<=num;i++) ednum[i]/=2;
	mi[0]=1;
	for(ll i=1;i<=m;i++) mi[i]=mi[i-1]*2%mod;
	dfs2(1,0);
	printf("%lld",dp[1][1]);
	return 0;
}
