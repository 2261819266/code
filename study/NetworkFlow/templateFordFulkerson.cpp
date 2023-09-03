#include <bits/stdc++.h>
using namespace std;
long long n , m , s , t , ans;
long long pre[200] , dis[200][200] , vis[200010] , minn[200];
vector<int> e[200];
bool bfs(){
	memset(vis , 0 , sizeof(vis));
	queue<int> q;
	vis[s] = 1;
	q.push(s);
	minn[s] = 0x3ffffff;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i = 0; i < e[x].size(); i++){
			int nx = e[x][i];
			if(dis[x][nx] > 0){
				if(vis[nx]) continue;
				minn[nx] = min(minn[x] , dis[x][nx]);	//找出最小容量 
				pre[nx] = x;	//记录前驱 
				q.push(nx);
				vis[nx] = 1;
				if(nx == t) return 1;
			}
		}
	}
	return 0;
}
void update(){	//更新剩余容量 
	int x = t;
	while(x != s){
		int px = pre[x];
		dis[x][px] += minn[t];
		dis[px][x] -= minn[t];
		x = px;
	}
	ans += minn[t]; 
}
int main(){
    LOCALfo
	cin >> n >> m >> s >> t;
	for(int i = 1; i <= m; i++){
		int x , y , z;
		cin >> x >> y >> z;
		e[x].push_back(y);
		dis[x][y] += z;	//有可能会有重边，需要把容量累加起来，如果直接重新建一条边的话，会因为边太多超时 这个地方的+=我查了几个小时/kk 
		e[y].push_back(x);	//反向边 
	}
	while(bfs()) update();
	cout << ans;
	return 0;
}