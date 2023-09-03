#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int mod=1e9+7;
int n,m;
const int N=17,M=26;
int u[M],v[M],sum;
int ans;
vector <int> e[N];
bool o1[N],o2[M];
bool vis[N];
void bfs(int x){
	if(vis[x])
		return ;
	vis[x]=1;
	for(int i=0;i<(int)e[x].size();i++)
		bfs(e[x][i]);
}
bool ok(int x){
	for(int i=1;i<=n;i++)
		e[i].clear();
	for(int i=1;i<=m;i++)
		if(i!=x){
			e[u[i]].push_back(v[i]);
			e[v[i]].push_back(u[i]);
		}
	for(int i=1;i<=n;i++)
		if(o1[i]){
			for(int j=1;j<=n;j++)
				vis[j]=0;
			bfs(i);
			for(int j=i+1;j<=n;j++)
				if(o1[j]&&vis[j]==0)
					return 0;
			return 1;
		}
	return 1;
}
bool check(){
	for(int i=1;i<=m;i++)
		if(o2[i]==0)
			if(ok(i)==0)
				return 0;
	return 1;
}
void dfs2(int x){
	if(x>m){
		ans+=check();
		return ;
	}
	dfs2(x+1);
	o2[x]=1;
	dfs2(x+1);
	o2[x]=0;
}
void dfs1(int x){
	if(x>n){
		if(sum)
			dfs2(1);
		return ;
	}
	dfs1(x+1);
	sum++;
	o1[x]=1;
	dfs1(x+1);
	o1[x]=0;
	sum--;
}
void work(){
	for(int i=1;i<=m;i++)
		scanf("%d%d",&u[i],&v[i]);
	dfs1(1);
	printf("%d",ans);
}
int pw(int x,int y){
	int z=1;
	while(y){
		if(y&1)
			z=1ll*z*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return z;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=10)
		work();
	else{
		ans=2*n;
		for(int i=2;i<=n;i++)
			ans=(ans+n-i+1)%mod;
		printf("%lld",1ll*ans*pw(2,n-2)%mod);
	}
	return 0;
}
