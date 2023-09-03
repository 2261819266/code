#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,Mod=1000000007;
vector<int> G[N],G2[30];
long long n,m,dp[N][4]{{0,0,0,0},{0,0,0,0},{1,1,2,3}};
pair<int,int> bian[30];
int vis[30];
long long d[4][4]={{1,1,0,0},
				   {1,1,0,0},
				   {1,1,0,0},
				   {1,1,1,1}};
bool S1(){
	if(n!=m+1) return 0;
	for(int i=2;i<=n-1;i++){
		if(G[i][0]==i-1 && G[i][1]==i+1 || G[i][0]==i+1 && G[i][1]==i-1);
		else return 0;
	}
	return 1;
}
long long mpow(int x,int y){
	if(y==0) return 1;
	int t=x;
	for(int i=2;i<=y;i++) t=(t*x)%Mod;
	return t;
}
long long dfs(int x){
	vis[x]=1;
	int t=1;
	for(int i=0;i<G2[x].size();i++){
		if(!vis[G2[x][i]]) t=(t+dfs(G2[x][i]))%Mod;
	}
	return t;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin >> u >> v;
		bian[i]=make_pair(u,v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
//	if(S1()){
//		for(int i=3;i<=n;i++){
//			for(int j=0;j<4;j++){
//				for(int k=0;k<4;k++){
//					dp[i][j]=(dp[i][j]+dp[i-1][k]*d[j][k])%Mod;
//				}
//			}
//		}
//		cout << dp[n][2]+dp[n][3];
//	}
	if(n<=16 && m<=25){
		long long ans=0;
		for(int i=0;i<(1<<m);i++){
			for(int j=0;j<30;j++) vector<int>().swap(G2[j]);
			memset(vis,0,sizeof(vis));
			for(int j=1;j<=m;j++){
				if(i&(1<<(j-1))){
//					cout << 1 << " ";
					G2[bian[j].first].push_back(bian[j].second);
					G2[bian[j].second].push_back(bian[j].first);
				}
//				else cout << 0 << " ";
			}
//			cout << endl;
			for(int i=1;i<=n;i++){
				if(!vis[i]) ans=(ans+mpow(2,dfs(i))-1)%Mod;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
