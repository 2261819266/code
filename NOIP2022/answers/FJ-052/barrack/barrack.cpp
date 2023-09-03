#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=2e6,mod=1e9+7;
vector<int> to[N];
int n,m,si[N];
long long ans;
void dfs(int x,int fa){
	for(int i=0;i<(int)to[x].size();i++)
		if(to[x][i]!=fa) {
			dfs(to[x][i],x);
		}
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),to[u].push_back(v),to[v].push_back(u);
	ans=(1ll+4ll*(n-1))%mod;
	printf("%lld",ans);
	return 0;
}
