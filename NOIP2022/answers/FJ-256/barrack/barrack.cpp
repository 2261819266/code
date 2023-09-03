#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1e6 + 10, INF = 1e9;
struct edge {int u, v;};
edge edges[MAX_N];
int n, m, tot = -1, ans;
vector<int> G[MAX_N];
vector<int> yd, nd, ks;
bool vis[MAX_N];
int dis[MAX_N];
void AddEdge(int u, int v) {
	edges[++tot] = {u, v};
	G[u].push_back(tot);
}

inline ll read() {
	ll ret = 0, w = 1; char c = getchar();
	while(!isdigit(c))	{if(c == '-')	w = -1; c = getchar();}
	while(isdigit(c))	{ret = (ret << 1) + (ret << 3) + (c ^ 48); c = getchar();}
	return ret * w;
}
char buf[100];
inline void write(ll x) {
	if(x < 0)	putchar('-'), x = -x;
	int tp = 0;
	do {buf[++tp] = x % 10 + 48; x /= 10;} while(x);
	while(tp) putchar(buf[tp--]);
}

void dijkstra(int s, int e) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for(int i = 1; i <= n; i++)
		vis[i] = 0, dis[i] = INF;
	dis[s] = 0; pq.push({0, s});
	while(!pq.empty()) {
		int u = pq.top().second; pq.pop();
		if(vis[u])	continue;
		vis[u] = 1;
		for(int i : G[u]) {
			if(i == e || i == (e ^ 1)) {
				bool flag = 0;
				for(int E : ks)
					if(E == e || E == (e ^ 1))	flag = 1;
				if(!flag)	continue;	
			}
			int v = edges[G[u][i]].v;
			if(dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				pq.push({dis[v], v});
			}
		}
	}
}

bool check() {
	for(int x = 0; x <= tot; x += 2) {
		for(int i = 0; i < (int)yd.size(); i++) {
			int u = yd[i];
			dijkstra(u, x);
			for(int j = 0; j < (int)yd.size(); j++) {
				int v = yd[j];
				if(dis[v] == INF)	return 0;
			}
		}	
	}
	return 1;
}

void dfs(int p, int q) {
	ans += check();
	if(p > n || q > tot)	return;
	dfs(p + 1, q + 2);
	
	yd.push_back(p);
	dfs(p + 1, q);
	yd.pop_back();
	
	ks.push_back(q);
	dfs(p, q + 2);
	ks.pop_back();
	
	yd.push_back(p), ks.push_back(q);
	dfs(p + 1, q + 2);
	yd.pop_back(), ks.pop_back();
}

int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read();
		AddEdge(u, v), AddEdge(v, u);
	}
	if(n == m + 1)	ans = (n * (1 << m) % INF + m * ((1 << n) - 2) % INF) % INF;
	else	dfs(1, 0);
	write(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
