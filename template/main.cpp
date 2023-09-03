// #include "edgetable"
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

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
	}
};

// int main() {}

const int maxn = 2e5 + 8;
EdgeTable a(maxn);
int vis[maxn], dis[maxn];
struct Node { 
    int u;
    int dis;
    bool operator<(const Node &b) const { return dis > b.dis; }
    operator int() { return u; }
};

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        a.add_edge(u, v, w);
    }
    std::priority_queue<Node> q;
    q.push({s, 0});
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    while (!q.empty()) {
        int u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto i = a.head[u]; i; i = i->next) {
            int to = i->to;
            dis[to] = std::min(dis[to], dis[u] + **i);
            if (!vis[to]) q.push({to, dis[to]});
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", dis[i]);
    }
}