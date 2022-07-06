#include <cstdio>
#define ll long long

int lowbit(int x) { return x & (-x); }

const int maxn = 5e5 + 8;
int n, m;
ll a[maxn];

int add(int i, int x) {
    for (; i <= n; i += lowbit(i)) a[i] += x;
    return x;
}

ll ask(int i) {
    ll ans = 0;
    for (; i > 0; i -= lowbit(i)) ans += a[i];
    return ans;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        add(i + 1, x);
    }
    for (int i = 0; i < m; i++) {
        int k, x, y;
        scanf("%d%d%d", &k, &x, &y);
        k == 1 ? add(x, y) : printf("%lld\n", ask(y) - ask(x - 1));
    }
}