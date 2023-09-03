#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<queue>
#include<random>
#include<bitset>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define I inline ll
#define ll long long 
using namespace std;
#define cht 998244353
#define her1 20090115//I love her
#define IV inline void
#define ull unsigned long long
#define F(i,j,n)for(int i=j;i<=n;i++)
#define D(i,j,n)for(int i=j;i>=n;i--)
#define E(i,now)for(int i=first[now];i;i=e[i].nxt)
#define FL(i,j,n)for(ll i=j;i<=n;i++)
#define DL(i,j,n)for(ll i=j;i>=n;i--)
#define EL(i,now)for(ll i=first[now];i;i=e[i].nxt)
#define mem(x,val)memset(x,val,sizeof x)
ll read(){
	ll ans=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();
	return ans*f;
}
mt19937 rnd(her1);
const int maxn = 4e6+5;
IV cadd(ll&x,ll val){x=(x+val)%cht;}queue<ll>qwq;
ll n,m,k,vis[maxn],stk[maxn][3],top[maxn],tmp[maxn],ans[maxn],A[maxn],B[maxn],cnt;
IV doit(ll opt,ll x,ll y=0){
	ans[++cnt]=opt;A[cnt]=x;B[cnt]=y;
}
IV poptop(ll t){
	if(top[t]==2)qwq.push(t);top[t]--;
}
IV push(ll t,ll v){
	if(top[t]==1)qwq.pop();
	stk[t][++top[t]]=v;vis[v]=top[t]+2*t-1;
}
IV popback(ll t){
	if(top[t]==2)qwq.push(t);vis[stk[t][1]]=0;
	F(i,2,top[t])vis[stk[t][i-1]=stk[t][i]]--;top[t]--;
}
IV ins(ll id,ll v){
	if(vis[v]){
		ll t=vis[v]/2;
		if((vis[v]&1)+1==top[t])doit(1,t),poptop(t);
		else doit(1,n),doit(2,t,n),popback(t);
	}
	else{
//		if(qwq.empty())
		ll t=qwq.front();doit(1,t);push(t,v);
	}
//	F(i,1,k)cout<<vis[i]<<' ';puts("");
//	F(i,1,n)cout<<top[i]<<' ';puts("");puts("");
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	ll T=read();
	while(T--){cnt=0;
		n=read();m=read();k=read();while(!qwq.empty())qwq.pop();
		F(i,1,n)top[i]=0;F(i,1,k)vis[i]=0;F(i,1,n-1)qwq.push(i);F(i,1,m)tmp[i]=read();
		F(i,1,m)ins(i,tmp[i]);
		printf("%lld\n",cnt);F(i,1,cnt){
			if(ans[i]==1)printf("%lld %lld\n",ans[i],A[i]);
			if(ans[i]==2)printf("%lld %lld %lld\n",ans[i],A[i],B[i]);
		}
	}
	return 0;
}
