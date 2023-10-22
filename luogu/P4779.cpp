#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::vector;
using std::priority_queue;
using std::min;

struct Edge { int v, w; };
struct Node {
    int u, dis;
    bool operator<(const Node &b) const {
        return dis > b.dis;
    }
};

vector<vector<Edge>> e;
vector<int> d, vis;

const int maxx = 1e9 + 8;

void addEdge(int u, int v, int w) {
    e[u].push_back({v, w});
}

void Dijkstra(int s) {
    priority_queue<Node> q;
    q.push({s, 0});
    while (!q.empty()) {
        Node u = q.top();
        q.pop();
        if (vis[u.u]) continue;
        vis[u.u] = true;
        for (Edge i : e[u.u]) {
            int v = i.v, w = i.w;
            d[v] = min(d[v], u.dis + w);
            q.push({v, d[v]});
        }
    }
}

void P4779() {
    int n, m, s;
    cin >> n >> m >> s;
    e.assign(n + 1, vector<Edge>());
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    d.assign(n + 1, maxx);
    vis.assign(n + 1, 0);
    d[s] = 0;
    Dijkstra(s);
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
}

int main() {
    P4779();
    return 0;
}
