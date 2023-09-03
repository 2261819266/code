#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+5;
const int mod=1e9+7;
int head[maxn],nxt[maxn],ver[maxn],tot;
int n,m;
inline void add(int x,int y){
	tot++,nxt[tot]=head[x],head[x]=tot,ver[tot]=y;
}
inline int rd(){
	int x=0,ng=1;char c;
	while((c=getchar())&&(!isdigit(c)&&(c!='-')));
	c=='-'?ng=1:x=c&15;
	while((c=getchar())&&(isdigit(c)))x=(x<<3)+(x<<1)+(c&15);
	return x*ng;
}
inline void wr(int x,char end='\n'){
	if(x==0)return putchar('0'),putchar(end),void();
	static char c[32];int t=0;
	if(x<0)putchar('-'),x=-x;
	while(x)c[++t]=x%10,x/=10;
	while(t)putchar(c[t--]^'0');
	putchar(end);
}
int fa[maxn];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int vis[maxn],pre[maxn],onroll[maxn];
void findroll(int x){
	while(!onroll[x]){
		cout<<x<<' ';
		fa[x]=find(pre[x]);
		onroll[x]=1;
		x=pre[x];
	}
	cout<<endl;
}
void dfs(int x,int fa){
	if(!vis[x])vis[x]=1;
	else return findroll(x);
	for(int i=head[x];i;i=nxt[i])if(ver[i]!=fa){
		pre[ver[i]]=x;
		dfs(ver[i],x);
	}
}
int qpow(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)ans=1ll*ans*x%mod;
	return ans;
}
set<int> has[maxn];
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=rd(),m=rd();
	for(int i=1;i<=m;i++){
		int x,y;x=rd(),y=rd();
		add(x,y),add(y,x);
	}
	cout<<1ll*qpow(2,n)*qpow(2,m)%mod<<endl;
	return 0;
}
