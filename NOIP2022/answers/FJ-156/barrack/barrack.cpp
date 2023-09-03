#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;++i)
#define D(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
using namespace std;
bool star;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	int x=0,w=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	return x*w;
}
const int N=5e5+10;
int head[N],to[N],nxt[N],tot;
inline void add(int u,int v){
	to[++tot]=v;nxt[tot]=head[u];head[u]=tot;
	to[++tot]=u;nxt[tot]=head[v];head[v]=tot;
}
const int mod=1e9+7;
inline int qpow(int a,int b){
	int res=1;for(;b;b>>=1,a=(ll)a*a%mod) if(b&1) res=(ll)res*a%mod;
	return res;
}
int ans,inv[N],fac[N],f[N][2];
inline int C(int n,int m){
	if(m==0) return 1;
	return (ll)fac[n]*inv[n-m]%mod*(ll)inv[m]%mod;
}
inline void dfs(int x,int fa){
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];if(v==fa) continue;
		dfs(v,x);
		f[x][0]=(ll)(f[v][1]+(ll)f[v][0]*2%mod)%mod;
		f[x][1]=(ll)((ll)f[v][1]+f[v][0])%mod*2%mod;
	}
}
signed main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n=read(),m=read();
	F(i,1,m){
		int u=read(),v=read();
		add(u,v);
	}
	fac[0]=1;
	F(i,1,n) fac[i]=(ll)fac[i-1]*i%mod,f[i][0]=1,f[i][1]=0;
	inv[n]=qpow(fac[n],mod-2);
	D(i,n-1,0) inv[i]=(ll)inv[i+1]*(i+1)%mod;
//	printf("%d\n",inv[n]);
	if(m==n){
		F(i,1,n) ans=((ll)ans+C(n,i))%mod;
		printf("%lld\n",(ll)ans*(ans+1)%mod);
	}
	else if(m==n-1){
		dfs(1,0);
		ans=(ll)((ll)f[1][0]*2%mod+f[1][1])%mod;
//		F(i,0,n-1) ans=(ll)(ans-C(n-1,i)+mod)%mod;
		printf("%d\n",ans-1);
	}
}
