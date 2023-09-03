#include<bits/stdc++.h>
using namespace std;

const int N=5e5+3,mod=1e9+7;
vector<int>edge[N];
int n,now,ans,a[N],cnt;

void dfs2(int u){
	if(u==n+1) return;
	for(auto v:edge[u]){
		if(a[u]==0&&a[v]==1) now=(now*2)%mod;
		if(a[u]==1&&a[v]==0) now=(now*2)%mod;
		dfs2(u+1);
	}
}

void dfs(int x){
	if(x==n+1){
		now=1; dfs2(1); ans=(ans+now)%mod;
		//for(int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<now;if(now==4)cnt++; puts("");
		return;
	}
	for(int i=0;i<=1;i++) a[x]=i,dfs(x+1),a[x]=0;
}

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int m; scanf("%d%d",&n,&m);
	for(int u,v;m--;){
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
	}
	dfs(1);
	printf("%d",ans-1);
}
