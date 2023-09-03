#include <algorithm>
#include <cstdio>
// #include "../../template/edgetable"
#include <cstring>
#include <queue>
#define ll long long

#ifndef EDGETABLE
#define EDGETABLE

#include <cstring>
struct Edge {
	int to;
	int w;
	Edge *next;
	Edge (int _to = 0, int _w = 0, Edge *_next = 0) : to(_to), w(_w), next(_next) {}
	Edge operator++() {
		Edge *x = this->next;
		if (x) return *x;
		else return {-1, 0, nullptr};
	}
	Edge operator++(int) { return *this = ++*this; }
	int operator*() { return w; }
	operator bool() { return ~to; }
	bool operator<(const Edge &b) const {
		return w < b.w;
	}
};
class EdgeTable {
public:
	Edge **head;

	Edge begin(int x) { 
		auto y = head[x];
		if (y) return *y;
		else return {-1, 0, nullptr};
	}
	EdgeTable(int maxn_ = 1e5 + 10) {
		head = new Edge*[maxn_];
		memset(head, 0, sizeof(int) * maxn_);
	}
	void add_edge(int u, int v, int w = 1) {
		Edge *e = new Edge(v, w, head[u]);
		head[u] = e;
	}
};

// int main() {}
#endif

const int maxn = 205;
ll a[maxn][maxn];
EdgeTable e;
int n, m, s, t, vis[maxn], dep[maxn];
Edge cur[maxn];

bool bfs() {
    memset(vis, 0, sizeof(vis));
    memset(dep, 0x3f, sizeof(dep)); 
    for (int i = 1; i <= n; i++) {
        if (e.head[i])
        cur[i] = *e.head[i];
    }  
    std::queue<int> q;
    q.push(s);
    bool k = false;
    dep[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto i = e.begin(u); i; i++) {
            int to = i.to;
            if (dep[to] > dep[u] + 1 && a[u][to]) {
                dep[to] = dep[u] + 1;
                if (!vis[to]) {
                    vis[to] = true;
                    q.push(to);
                }
            }
        }
    }
    return dep[t] < maxn;
}

ll dfs(int u, ll x) {
    ll ans = 0;
    if (u == t) return x;
    for (auto i = cur[u]; i; i++) {
        cur[u] = i;
        int to = i.to;
        if (a[u][to] && dep[to] == dep[u] + 1) {
            ans = dfs(to, std::min(x, a[u][to]));
            if (ans) {
                a[u][to] -= ans;
                a[to][u] += ans;
                return ans;
            }
        }
    }
    return 0;
}

ll dinic() {
    ll ans = 0;
    while (bfs()) {
        while (true) {
            ll x = dfs(s, (ll)0x3f3f3f3f3f3f3f3f);
            if (!x) break;
            ans += x;
        }
    }
    return ans;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        e.add_edge(u, v);
        e.add_edge(v, u);
        a[u][v] += w;
    }
    printf("%lld\n", dinic());
}