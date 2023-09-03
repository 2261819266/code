#include <cstdio>
#define ll long long

const int maxn = 1e7 + 8;
int n, m;
ll a[maxn];

void add(int x, int k) {
    for (; x <= n; x += x & -x) a[x] += k;
}

ll ask(int x) {
    int ans = 0;
    for (; x; x -= x & -x) ans += a[x];
    return ans;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int k, x, y;
        scanf("%d%d", &k, &x);
        if (k == 0) {
            scanf("%d", &y);
            add(x, 1), add(y + 1, -1);
        } else printf("%lld\n", ask(x));
    }
}