#include<bits/stdc++.h>
//%:line 3 "Suruka"//Luogu User
using namespace std;
#define fr(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
using ll = long long;
constexpr int N=5e5+5,M=2e6+5;
constexpr ll mod=1e9+7;
#define m(x) (((x)%mod+mod)%mod) 
ll n,m,h[N],to[M],nxt[M],dfn[N],low[N],cnt=0,st[M];
ll edg[N],poi[N],col[N],colcnt=0,dfncnt=0;
ll h2[N],to2[M],nxt2[M],cnt2=0;
bool fk[M],v[N];
inline ll adde(ll x,ll y){to[++cnt]=y;st[cnt]=x;nxt[cnt]=h[x];return h[x]=cnt;}
inline ll adde2(ll x,ll y){to2[++cnt2]=y;nxt2[cnt2]=h2[x];return h2[x]=cnt2;}
ll tarjan(ll x,ll fa=0){
	low[x]=dfn[fa],dfn[x]=++dfncnt;
	for(int i=h[x],y;i;i=nxt[i]){y=to[i];
		if(!dfn[y]){if(tarjan(y,x)>=dfn[x])fk[i]=fk[i&1?i+1:i-1]=true;}
		else if(y!=fa)low[x]=min(low[x],low[y]);
	}return low[x];
}
void edgestrong(ll x,ll fa=0){
	poi[colcnt]++,v[x]=true,col[x]=colcnt;
	for(int i=h[x],y;i;i=nxt[i]){y=to[i];
//		if(fk[i]){if(col[y]!=0)adde2(colcnt,col[y]),adde2(col[y],colcnt);continue;}
		if(fk[i])continue;
		if(!v[y]&&y!=fa)edgestrong(y,x);
		else edg[colcnt]++;
	}
}
inline ll qpow(ll n,ll k,ll m=mod){ll ans=1;for(;k;k>>=1,n=(n*n)%m)if(k&1)ans=(ans*n)%m;return ans;}
ll dp[N],ans=0;set<pair<int,int>> s_;
ll shuxindp(ll x,ll fa=0){
	//好好想想！！！ 
//	ll siz=0,tmp=0;vector<int>v{x};
//	for(ll i=h2[x];i;i=nxt2[i])if(to2[i]!=fa)siz++;
//	if(!siz)return qpow(2,poi[x])-1;
//	for(ll i=siz,j=siz;i;j=m(j*--i/(siz-i)))tmp=m(tmp+m(j*qpow(2,i)));
//	for(ll i=h2[x];i;i=nxt2[i])if(to2[i]!=fa)dp[x]=m(dp[x]+m(tmp*shuxindp(to2[i],x)));
//	for(ll i=h2[x];i;i=nxt2[i])if(to2[i]!=fa)dp[x]=m(dp[x]+m((qpow(2,poi[x])-1)*m(tmp*shuxindp(to2[i],x)>>1)));
	return dp[x]=m(qpow(2,poi[x]*edg[x])-1);
}
signed main(){
	fr(barrack);
	scanf("%lld%lld",&n,&m);
	for(ll i=0,x,y;i<m;i++)scanf("%lld%lld",&x,&y),adde(x,y),adde(y,x);
	tarjan(1);for(ll i=1;i<=n;i++)if(!v[i])++colcnt,edgestrong(i);
	for(ll i=1;i<=m<<1;i++)if(fk[i]&&!s_.count(make_pair(col[st[i]],col[to[i]])))adde2(col[st[i]],col[to[i]]),s_.insert(make_pair(col[st[i]],col[to[i]]));
	printf("%lld\n",shuxindp(1));
	return 0;
}

