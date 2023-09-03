#include <cstdio>
#include <algorithm>
#include <type_traits>

const int maxn = 1e5 + 8, maxm = 1005;
struct Node {
    int x, y;

    bool operator==(const Node &b) const {
        return x == b.x && y ==  b.y;
    }
} a[maxn], b[maxn], x, y;
int t[maxn], vis[maxn];

using T = const Node &;


int sqre(int x) {
    return x * x;
}

int dist(T x, T y) { return sqre(x.x - y.x) + sqre(x.y - y.y); }

int dx(T t) { return dist(t, x); }

int dy(T t) { return dist(t, y); }

bool operator<(T _x, T _y) { return dy(_x) > dy(_y); };

void P1158() {
    scanf("%d%d%d%d", &x.x, &x.y, &y.x, &y.y);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
        b[i] = a[i];
    }
    auto cmp1 = [](T _x, T _y) { return dx(_x) < dx(_y); };
    auto cmp2 = [](T _x, T _y) { return dy(_x) > dy(_y); };
    std::sort(a, a + n, cmp1);
    std::sort(b, b + n, cmp2);
    int ans = std::min(dy(*b), dx(a[n - 1]));

    for (int i = 0, now = 0; i < n; i++) {
        auto start = std::lower_bound(b, b + n, a[i]);
        auto end = std::upper_bound(b, b + n, a[i]);
        for (auto k = start; k < end; k++){
            if (*k == a[i]) vis[k - b]++;
        }
        while (vis[now]) now++;
        ans = std::min(ans, dx(a[i]) + dy(b[now]));
    }
    printf("%d", ans);
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    P1158();
    return 0;
}