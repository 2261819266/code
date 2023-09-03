#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long 

const int maxn = 1e4 + 8;

ll f(ll x) {
    return x * x - x - 1;
}

void P3951() {
    ll a, b;
    ll ans;
    scanf("%lld%lld", &a, &b);
    // memset(dp, 0, sizeof(dp));
    // dp[0] = 1;
    // for (int i = 1; i < maxn; i++) {
    //     dp[i] = (i >= a && dp[i - a]) || (i >= b && dp[i - b]);
    //     if (!dp[i]) ans = i;
    // }
    if (a > b) std::swap(a, b);
    // if (a == 1) ans = 0;
    // else {
        
    // }
    ans = f(a) + (b - a - 1) * (a - 1);
    printf("%lld\n", ans);
}


int main() {
#ifdef LOCAL
    LOCALfo
#endif
    P3951();
    return 0;
}