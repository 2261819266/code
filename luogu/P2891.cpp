#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <queue>
// #include "edgetable"



const int maxn = 2005;
// int f[maxn], d[maxn];
int n, nf, nd, s, t;
int a[maxn][maxn];

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
	void add_edge(int u, int v, int w) {
		Edge *e = new Edge(v, w, head[u]);
		head[u] = e;
        a[u][v] = w;
	}

    void add_edge(int u, int v) {
        add_edge(u, v, 1);
        add_edge(v, u, 0);
	}
};

// int main() {}
#endif

const int inf = 0x3f3f3f3f;
EdgeTable e;
int vis[maxn], dep[maxn];
Edge cur[maxn];

bool bfs() {
    for (int i = s; i <= t; i++) {
        vis[i] = 0;
        dep[i] = inf;
        if (e.head[i]) cur[i] = *e.head[i];
        else cur[i] = {-1};
    }
    std::queue<int> q;
    q.push(s);
    dep[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto i = e.begin(u); i; i++) {
            int to = i.to;
            if (dep[to] > dep[u] + 1 && a[u][to]) {
                dep[to] = dep[u] + 1;
                if (!vis[to]) {
                    vis[to] = 1;
                    q.push(to);
                }
            }
        }
    }
    return dep[t] <= t;
}

int dfs(int u, int x) {
    int ans = 0;
    if (u == t) return x;
    for (auto i = e.begin(u); i; i++) {
        cur[i] = i;
        int to = i.to;
        if (dep[to] == dep[u] + 1 && a[u][to]) {
            ans = dfs(to, std::min(x, a[u][to]));
            if (ans){
                a[u][to] -= ans;
                a[to][u] += ans;
                return ans;
            }
        }
    }
    return 0;
}

int Dinic() {
    int ans = 0;
    while (bfs()) {
        int x;
        while (true) {
            x = dfs(s, inf);
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
    scanf("%d%d%d", &n, &nf, &nd);
    t = nf + nd + n * 2 + 1;
    for (int i = 1; i <= nf; i++) {
        e.add_edge(s, i);
    }
    for (int i = 1; i <= nd; i++) {
        e.add_edge(i + n * 2 + nf, t);
    }
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        e.add_edge(nf + i, nf + n + i);
        for (int j = 0; j < x; j++) {
            int k;
            scanf("%d", &k);
            e.add_edge(k, nf + i);
        }
        for (int j = 0; j < y; j++) {
            int k;
            scanf("%d", &k);
            e.add_edge(nf + n + i, nf + n * 2 + k);
        }
    }
    // for (int i = 0; i <= n * 2 + nf + nd + 1; i++) {
    //     for (auto j = e.begin(i); j; j++) {
    //         if (a[i][j.to]) printf("%d %d\n", i, j.to);
    //     }
    // }
    // int *nu = nullptr;
    // int *x = new int();
    // auto y = x - nu;
    printf("%d", Dinic());
}