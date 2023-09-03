#include <cstdio>
#include <algorithm>
#include <queue>

const int maxn = 1e5 + 8;
int a[maxn], b[maxn], p[maxn], fa[maxn];
std::priority_queue<int> q[maxn];

int find(int x) {
    while (x != fa[x]) {
        fa[x] = fa[fa[x]];
        x = fa[x];
    }
    return x;
}

void P2127() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        b[i] = a[i];
        fa[i] = i;
    }
    std::sort(b, b + n);
    for (int i = 0; i < n; i++) {
        p[std::lower_bound(b, b + n, a[i]) - b] = i;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        fa[i] = find(p[i]);
    }
    for (int i = 0; i < n; i++) {
        q[find(i)].push(a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (fa[i] != i) continue;
        int n = q[i].size();
        while (q[i].size() > 1) {
            ans += q[i].top();
            q[i].pop();
        }
        if (n > 1) {
            ans += q[i].top() * (n - 1);
        }
    }
    printf("%lld\n", ans);
}


int main() {
#ifdef LOCAL
    LOCALfo
#endif
    P2127();
    return 0;
}