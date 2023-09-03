#include <cstdio>
#define ll long long 

int n, m, k, x;

ll pow(int x, int y) {
    if (!y) return 1;
    ll ans = pow(x * x % n, y / 2);
    if (y % 2) ans *= x;
    return ans % n;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d%d%d", &n, &m, &k, &x);
    printf("%lld", (pow(10, k) * m + x) % n);
}