#include<bits/stdc++.h>
#define F(i,x,n) for(int i=x;i<=n;++i)
#define _F(i,x,n) for(int i=x;i>=n;--i)
#define ll long long
#define ull unsgined long long
#define lson x<<1
#define rson x<<1|1
#define lowbit(x) x&-x
using namespace std;

inline int read(){
	int s=0;char c=getchar();bool flag=0;
	while(!isdigit(c))flag|=(c=='-'),c=getchar();
	while(isdigit(c))s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return flag?-s:s;
}

const int N=5e5+5;//数组不要开小，记得检查。 
const int M=1e6+5;
const int mod=1e9+7;

struct edge{
	int nxt,u,v;
}g[M<<1];

int head[M];
int cnt,n,m;

void add(int u,int v){
	g[++cnt]=edge{head[u],u,v};
	head[u]=cnt;
}

namespace sub1{
	int fa[N];
	bool a[N],b[N];
	int ans=0;
	int Find(int x){
		if(fa[x]==x)return fa[x];
		return fa[x]=Find(fa[x]);
	}
	bool check(){
		F(i,1,n)fa[i]=i;
		F(i,1,m)if(b[i]){
			if(Find(g[i].u)!=Find(g[i].v))fa[Find(g[i].v)]=Find(g[i].u);
		}
		int k=-1;
		F(i,1,n){
			if(a[i]&&k==-1)k=Find(i);
			if(a[i]&&k!=Find(i))return 0;
		}
		return 1;
	} 
	void dfs2(int k){
		if(k>m){
			if(check())++ans;
			return;
		}
		b[k]=1,dfs2(k+1);
		b[k]=0,dfs2(k+1);
	}
	void dfs1(int k){
		if(k>n){
			dfs2(1);
			return;
		}
		a[k]=1,dfs1(k+1);
		a[k]=0,dfs1(k+1);
	}
	void mian(){
		dfs1(1);
		cout<<ans<<'\n';
	}
}

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	F(i,1,m){
		int u=read(),v=read();
		add(u,v);
	}
	if(n<=16&&m<=25)sub1::mian();
	return 0;
}
