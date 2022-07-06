#include <cstdio>
#include <algorithm>

const int maxn = 1e4;

struct Node {
    int x, i;
    bool operator<(const Node &b) {
        return x == b.x ? i < b.i : x < b.x;
    }
};

Node a[maxn], b[maxn];
int n, m, to[maxn];

void copy() {
    for (int i = 1; i <= n; i++) b[i] = a[i];
}

void sort(int now) {
    int i;
    for (i = now; i < n && b[i + 1] < b[i]; i++) std::swap(b[i], b[i + 1]);
    for (i; i > 0 && b[i] < b[i - 1]; i--) std::swap(b[i], b[i - 1]);
    for (int i = 1; i <= n; i++) {
        to[b[i].i] = i;
    }
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].x);
        a[i].i = i;
    }
    copy();
    std::sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        to[b[i].i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int k, x, y;
        scanf("%d%d", &k, &x);
        if (k == 1) {
            scanf("%d", &y);
            a[x].x = y;
            b[to[x]].x = y;
            sort(to[x]);
        } else {
            printf("%d\n", to[x]);
        }
    }
}