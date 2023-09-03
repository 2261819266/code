#include <algorithm>
#include <cstdio>
#include <vector>

const int maxn = 2e3 + 8;

struct Node {
    int x, i;
    bool operator>(const Node &b) const {
        return (x < b.x) || (!(b.x < x) && i > b.i);
    }

    bool operator<(const Node &b) const {
        return b > *this;
    }
} a[maxn], b[maxn];

std::vector<int> v1, v2;

void P1056() {
    int m, n, k, l, d;
    scanf("%d%d%d%d%d", &m, &n, &k, &l, &d);
    for (int i = 1; i <= m; i++) {
        a[i].i = i;
    }
    for (int i = 1; i <= n; i++) {
        b[i].i = i;
    }
    for (int i = 0; i < d; i++) {
        std::pair<int, int> o, p;
        scanf("%d%d%d%d", &o.first, &o.second, &p.first, &p.second);
        if (p < o) o.swap(p);
        if (o.first == p.first) b[o.second].x++;
        else a[o.first].x++;
    }
    std::sort(a + 1, a + m + 1);
    std::sort(b + 1, b + n + 1);
    for (int i = 1; i <= k; i++) {
        v1.push_back(a[i].i);
    }
    std::sort(v1.begin(), v1.end());
    for (int x : v1) {
        printf("%d ", x);
    }
    putchar('\n');
    for (int i = 1; i <= l; i++) {
        v2.push_back(b[i].i);
    }
    std::sort(v2.begin(), v2.end());
    for (int x : v2) {
        printf("%d ", x);
    }
}


int main() {
#ifdef LOCAL
    LOCALfo
#endif
    P1056();
    return 0;
}