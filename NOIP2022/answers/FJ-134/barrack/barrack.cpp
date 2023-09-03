#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=2e6+10;
const ll mod=1e9+7;
struct Edge{
	int u,v,nxt;
}e[N],c[N];
int head[N],num=0;
ll p[N];
void add(int u,int v){
	e[++num].nxt=head[u];
	head[u]=num;
	e[num].v=v;
}
int n,m;
bool in[N];
ll ans=0;
int fa[N];
int find(int x){
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	return x;
}
void work(){
	int cnt=0;
	for(int i=1;i<=m;i++){
		int k=0;
		for(int j=1;j<=n;j++) fa[j]=j;
		for(int j=1;j<=m;j++){
			if(j==i) continue;
			int u=c[j].u,v=c[j].v;
			u=find(u);v=find(v);
			if(u!=v){
			   k++;	
			   fa[u]=v;	
			   if(k==n-1) break;
			}
		}
		int fat=0;
		for(int j=1;j<=n;j++){
			if(!in[j]) continue;
			if(!fat) fat=find(j);
			if(find(j)!=fat){
			   cnt++;break;
			}
		}   
	}
	ans=(ans+p[m-cnt])%mod;
}
void dfs(int pos,int num){
	if(pos==n+1){
	   if(num==1) ans=(ans+p[m])%mod;
	   if(num>1) work();
	   return;
	}
	in[pos]=1;
	dfs(pos+1,num+1);
	in[pos]=0;
	dfs(pos+1,num);
}
signed main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read();m=read();
	bool fl=1;
	if(m!=n-1) fl=0;
	for(int i=1;i<=m;i++){
		c[i].u=read();c[i].v=read();
		add(c[i].u,c[i].v);
		add(c[i].v,c[i].u);
		if(!(c[i].u+1==c[i].v||c[i].v+1==c[i].u)) fl=0;
	}
	p[0]=1ll;
	for(int i=1;i<=m;i++) p[i]=p[i-1]*2%mod;
	if(n<=16){
		dfs(1,0);
		printf("%lld",ans);
		return 0;
	}
	if(fl){
		ans=(ans+n*p[m]%mod)%mod;
		for(int l=1;l<n;l++)
		    ans=(ans+(n-l)*p[m-1]%mod)%mod;
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
