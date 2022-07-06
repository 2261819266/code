#include <cstdio>

int lowbit(int x) { return x & -x; }

const int maxn = 5e5 + 8;
int a[maxn], n, m;


int add(int i, int x) {
    for (; i <= n; i += lowbit(i)) a[i] += x;
    return x;
}

int ask(int i) {
    int ans = 0;
    for (; i > 0; i -= lowbit(i)) ans += a[i];
    return ans;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        add(i, x), add(i + 1, -x);
    }
    for (int i = 0; i < m; i++) {
        int k, x, y, z;
        scanf("%d%d", &k, &x);
        k == 1 ? scanf("%d%d", &y, &z), add(x, z), add(y + 1, -z) : printf("%d\n", ask(x));
    }
}
