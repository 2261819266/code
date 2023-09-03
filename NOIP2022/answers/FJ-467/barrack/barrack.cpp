#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int n,m;
int result;
bool a[15];
bool b[10];
int u[15],v[15];
bool vis[15];
vector<int>adj[50];
void BFS(int x,int p){
//	cout<<x<<" "<<u[p]<<" "<<v[p]<<endl;
	memset(vis,0,sizeof(vis));
	vis[x] = true;
	queue<int>q;
	q.push(x);
	while(q.size()){
		int fr = q.front();
		for(int i = 0;i<adj[fr].size();i++){
			if((adj[fr][i] == u[p]&&fr == v[p])||(adj[fr][i] == v[p]&&fr == u[p])||vis[adj[fr][i]])continue;
			else{
				vis[adj[fr][i]] = true;
				q.push(adj[fr][i]);
			}
		}
		q.pop();
	}
}
bool f(int p){
	for(int i = 1;i<=n;i++){
		if(b[i]){
			BFS(i,p);
		}
		for(int j = 1;j<=n;j++){
			if(b[j]&&!vis[j])return false;
		}
	}
	return true;
}
bool okay(){
	for(int i = 0;i<m;i++){
		if(a[i])continue;
		if(f(i))return false;
	}
	return true;
}
void DFS1(int pos){
	if(pos == n+1){
		if(okay()){
//			for(int i = 0;i<m;i++)cout<<a[i];
//			cout<<" ";
//			for(int i = 1;i<=n;i++)cout<<b[i];
//			cout<<endl;
			result++;
			result%=MOD;
		}
		return ;
	}
	b[pos] = true;
	DFS1(pos+1);
	b[pos] = false;
	DFS1(pos+1);
}
void DFS(int pos){
	if(pos == m){
		DFS1(1);
		return ;
	}
	a[pos] = true;
	DFS(pos+1);
	a[pos] = false;
	DFS(pos+1);
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		cin>>u[i]>>v[i];
		adj[u[i]].push_back(v[i]);
		adj[v[i]].push_back(u[i]);
	}
	DFS(0);
	cout<<result<<endl;
}
