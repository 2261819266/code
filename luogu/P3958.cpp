#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)
#define ll long long

struct Point { ll x, y, z; };

ll square(ll x) { return x * x; }

ll dist(const Point a, const Point b) { return ceil(sqrt(square(a.x - b.x) + square(a.y - b.y) + square(a.z - b.z))); }

const int maxn = 1e3 + 8;
const char s[2][10] = {"No", "Yes"};
Point a[maxn];
bool vis[maxn];
int n, h, r;

bool dfs(int now) {
    vis[now] = true;
    if (a[now].z + r >= h) return true;
    f(i, 0, n) {
        if (!vis[i] && dist(a[now], a[i]) <= r * 2) {
            bool k = dfs(i);
            if (k) return true;
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int t;
    scanf("%d", &t);
    f(i, 0, t) {
        scanf("%d%d%d", &n, &h, &r);
        f(i, 0, n) {
            scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].z);
        }
        memset(vis, false, sizeof(vis));
        bool k = false;
        f(i, 0, n) {
            if (a[i].z <= r) {
                k |= dfs(i);
            }
        }
        printf("%s\n", s[k]);
    }
}