#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
struct Edge {
	int to;
	int w;
	Edge *next;
    int id;
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
	void add_edge(int u, int v, int w = 1 int, i = 0) {
		Edge *e = new Edge(v, w, head[u], i);
		head[u] = e;
	}
};

// int main() {}

const int maxn = 5e4 + 8;
EdgeTable a;
int k[maxn], vis[maxn];

int main() {
    freopen("keylines.in", "r", stdin);
    freopen("keylines.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        a.add_edge(u, v, w, i);
    }
    // std::sort(a, a + m);
    std::priority_queue<Edge> q; 
    // for (int i = 0; i < m; ) {
    //     // int l = i, r = i;
    //     // while (a[l].w == a[i].w) i++;
    //     // r = i - 1;
    //     // if (l == r && !vis[a[l].u] && !vis[a[l].v]) {
    //     //     k[a[l].id] = 1;
    //     //     vis[a[l].u] = vis[a[l].v] = 1;
    //     //     continue;
    //     // }
        
    // }
    q.push(1);
    while (!q.empty()) {
        int u = q.top().to;
        int id = q.top().id;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        k[id] = 1;
        for (auto i = a.begin(u); i; i++) {
            q.push(i);
        }
    }
    for (int i = 0; i < m; i++) {
        
    }
    return 0;
}