#include <cstdio>
#define ll long long

ll C(ll a, ll b) {
    ll k = 1;
    for (ll c = a; c > a - b; c--)
        k = k * c / (a - c + 1);
    return k;
}

ll KTL(ll n) { return C(2 * n, n) / (n + 1); }

ll n;

int main() {
    scanf("%lld", &n);
    printf("%lld", KTL(n));
}