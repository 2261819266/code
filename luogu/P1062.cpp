#include <cstdio>

#define ll long long

ll powk[100];

void init(int k) {
    powk[0] = 1;
    for (int i = 1; i < 12; i++) {
        powk[i] = powk[i - 1] * k;
    }
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int k, n;
    ll ans = 0;
    scanf("%d%d", &k, &n);
    init(k);
    for (int i = 0; n; i++) {
        ans += powk[i] * (n % 2);
        n /= 2;
    }
    printf("%lld", ans);
}