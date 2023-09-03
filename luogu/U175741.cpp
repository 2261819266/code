#include <cstdio>
#include <vector>
#include <queue>
#define ll long long

const int maxn = 3e5 + 8;
struct Node { int x, w; };
std::vector<Node> e[maxn];
std::pair<std::pair<ll, ll>, ll*> es;

void dijkstra(ll *dis, int s) {
    std::queue<int> q;
}

void U175741() {
    int n, p, q;
    scanf("%d%d%d", &n, &p, &q);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
}
#include <string>
int main() {
#ifdef LOCAL
    LOCALfo
#endif
    U175741();
    return 0;
}
