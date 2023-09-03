#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define ll long long 

bool St;

std::vector<ll> a, b;
ll maxx;

bool Ed;

int dfs(ll x, ll yuan) {
    if (x < a.size() && ~a[x]) {
        return a[x];
    }
    b[yuan] = std::max(b[yuan], x);
    // maxx = std::max(maxx, (ll)x);
    if (b[maxx] < b[yuan]) maxx = yuan;
    int y = dfs(x % 2 ? (x * 3 + 1) : (x / 2), yuan) + 1;
    if (x < a.size()) a[x] = y;
    return y;
}

void solve() {
    ll n, l;
    scanf("%lld%lld", &l, &n);
    a.assign(n + 1, -1);
    b.assign(n + 1, 0);
    a[1] = 0;
    ll maxi = 1;
    for (int i = l; i <= n; i++) {
        dfs(i, i);
        // printf("%d\n", a[i]);
        if (a[maxi] < a[i]) {
            maxi = i;
        }
    }

    printf("\n%d %lld\n%d %lld\n", maxi, a[maxi], maxx, b[maxx]);
}

LOCALinit

// int main() {
//     std::cerr << (double)std::abs(&Ed - &St) / 1024.0 / 1024.0 << "Mb\n";
//     solve();
// 	std::cerr << "\n" << double(clock()) / CLOCKS_PER_SEC << "s\n";
// }
