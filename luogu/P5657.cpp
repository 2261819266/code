#include <cstdio>
#define ll unsigned long long
#define y (1ull << (n - 1))

template<typename t>
void scan(t &x) {
    int c;
    x = 0;
    while (~(c = getchar()) && c >= '0' && c <= '9') {
        x *= 10, x += c - '0';
    }
}

ll n, k;

void f(int n, ll k, bool op = false) {
    if (!n) return;
    op = (k >= y);
    printf("%d", op);
    if (op) k = (y << 1) - k - 1;
    f(n - 1, k, op);
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scan(n);
    scan(k);
    f(n, k);
    // for (ll i = 0; i < y * 2; i++) {
    //     f(n, i);
    //     puts("");
    // }
}