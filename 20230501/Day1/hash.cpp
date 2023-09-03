#include <cmath>
#include <cstdio>
#include <string>

const int M = 2001000097;
#define ll long long
using std::string;

ll f(ll x) {
    string s;
    char ss[100];
    sprintf(ss, "%lld", x);
    s = ss;
    ll ans = 0;
    for (int i : s) {
        i -= 48;
        ans += i;
    }
    return ans * (x % M) % M;
}

#define fo(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);

int main() { 
#ifndef LOCAL
    fo(hash)
#endif
    int n;
    scanf("%d", &n);
    while (n--) {
        ll l = 1, r;
        scanf("%lld", &r);
        // scanf("%lld%lld", &l, &r);
        ll ans = 0;
        for (int i = r; i <= r; i++) {
            ans += f(i);
            ans %= M;
        }
        printf("%lld\n", ans);
    }
}

