#include <iostream>
using namespace std;
int n,m,ans=0;
struct node{
	bool g[5001];
}g[5001];
bool b[5001]={0};
struct node2{
	int x,y;
} g2[10001];
bool ok (){
	node wuhu[5001];
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			wuhu[i].g[j]=g[i].g[j];
		}
	}
	for (int v=1;v<=n;v++){
		for (int f=1;f<=n;f++){
			for (int t=1;t<=n;t++){
				if (wuhu[f].g[v]&&wuhu[v].g[t]){
					wuhu[f].g[t]=1;
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (b[i]==1&&b[j]==1&&wuhu[i].g[j]==0){
				return 0;
			}
		}
	}
	return 1;
}
void dfs (int dep,int roadst){
	if (dep>n){
		if (roadst>m){
			if (ok()){
				ans++;
				ans/=1000000007;
			}
			return;
		}
		g[g2[roadst].x].g[g2[roadst].y]=0;
		dfs(dep,roadst+1);
		g[g2[roadst].x].g[g2[roadst].y]=1;
		return;
	}
	b[dep]=1;
	dfs(dep+1,roadst);
	b[dep]=0;
	dfs(dep+1,roadst);
	return;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=m;i++){
		int u,v;
		cin >> u >> v;
		g[u].g[v]=1;
		g2[i].x=u;
		g2[i].y=v;
	}
	dfs(1,1);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
