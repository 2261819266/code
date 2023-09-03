#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define ll long long
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)

using std::queue;
using std::max;
using std::min;

const int maxn = 1005, maxm = 1e4 + 8;
const ll inf = 0xffffffffffff;
struct E {
	int to, next;
} edge[maxm << 2];
int head[maxn], cnt, n, m, s, t;
ll a[maxn][maxn];
int pre[maxn];

void addedge(int u, int v, ll w) {
	edge[cnt] = (E) {v, head[u]};
	head[u] = cnt++;
	a[u][v] += w;
}

bool bfs() {
	memset(pre, -1, sizeof(pre));
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; ~i; i = edge[i].next) {
			int to = edge[i].to;
			if (!~pre[to] && a[u][to]) {
				q.push(to), pre[to] = u;
				if (to == t) return true;
			}
		}
	}
	return false;
}

ll EK() {
	ll ans = 0;
	while (bfs()) {
		ll minx = inf;
		for (int i = t; i != s; i = pre[i]) {
			minx = min(minx, a[pre[i]][i]);
		}
		for (int i = t; i != s; i = pre[i]) {
			a[pre[i]][i] -= minx;
			a[i][pre[i]] += minx;
		}
		ans += minx;
	}
	return ans;
}


int main() {
#ifdef LOCAL
	LOCALfo
#endif	
	memset(head, -1, sizeof(head));
	scanf("%d%d", &m, &n);
    s = 1, t = n;
	f(i, 0, m) {
		int u, v; ll w;
		scanf("%d%d%lld", &u, &v, &w);
		addedge(u, v, w);
		addedge(v, u, 0);
	}
	ll ans = EK();
	printf("%lld", ans);
	return 0;
}