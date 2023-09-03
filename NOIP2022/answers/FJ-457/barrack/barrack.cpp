#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int x=0,f=1;char c;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	while(isdigit(c))x=(x<<1)+(x<<3)+(c&15),c=getchar();
	return x*f;
}
const int N=5e5+10,M=1e6+10,p=1e9+7;
struct node{
	int to,nex,id;
}e[M*2];
int head[N],cnt;
int n,m;
ll fac[N],inv[N];
bool vis[M],is[25];
int pre[N],K;
struct edge{
	int x,y;
}G[M],g[M];
int fa[N],len,siz[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void add(int x,int y,int id){
	e[++cnt]=(node){y,head[x],id};
	head[x]=cnt;
}
int power(int a,int b){
	int c=1;
	for(;b;b>>=1){
		if(b&1)c=1ll*c*a%p;
		a=1ll*a*a%p;
	}
	return c;
}
ll C(int x,int y){
	if(x<y)return 0;
	return fac[x]*inv[y]%p*inv[x-y]%p;
}
void solve_tree(){
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%p;
	inv[n]=power(fac[n],p-2);
	for(int i=n-1;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%p;
	ll ans=0;
	for(int i=1;i<=n;i++)ans=(ans+C(n,i)*power(2,n-i)%p)%p;
	cout<<(ans+p)%p;
}
void dfs_find(int x,int fa){
	vis[x]=1;
	for(int i=head[x];i;i=e[i].nex){
		int y=e[i].to;
		if(!vis[y]){
			pre[y]=x;
			dfs_find(y,x);
		}
		else if(y!=fa){
			int p=x;
			while(p!=y){
				K++;
				p=pre[p];
			}
			K++;
			return;
		}
	}	
}
void solve_jihuan_tree(){
	
}
int Ans;
int check1(){
	int tot=0;
	for(int i=1;i<=n;i++)tot+=vis[i];
	if(tot==1)return 1;
	for(int j=1;j<=m;j++){
		if(is[j])continue; //不能删 
		for(int i=1;i<=n;i++){
			fa[i]=i;
			siz[i]=vis[i];
		}
		for(int i=1;i<=m;i++){
			if(i==j)continue; //如果是删的边就跳过 
			int x=get(G[i].x),y=get(G[i].y);
			if(x==y)continue;
			siz[y]+=siz[x];
			fa[x]=y;
		}
		bool flag=0;
		for(int i=1;i<=n;i++)if(siz[i]==tot)flag=1;
		if(!flag)return 0;
	}
	return 1;
}
void dfs2(int x){
	if(x>m){
		if(check1()){
			Ans++;
		}
		if(Ans>=p)Ans-=p;
		return;
	}
	is[x]=1;
	dfs2(x+1);
	is[x]=0;
	dfs2(x+1);
}
void dfs(int x,int sum){
	if(x>n){
		if(sum)dfs2(1);
		return;
	}
	vis[x]=1;
	dfs(x+1,sum+1);
	vis[x]=0;
	dfs(x+1,sum);
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		add(x,y,i);
		add(y,x,i);
		G[i]=(edge){x,y};
	}
	for(int i=1;i<=n;i++)vis[i]=1;
	if(m==n-1){
		solve_tree();
		return 0;
	}
	if(n+m<=27){
		dfs(1,0);
		cout<<Ans;
		return 0;
	}
	if(m==n){
		solve_jihuan_tree();
		return 0;
	}
}

