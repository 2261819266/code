#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)

const int maxn = 6005;
std::vector<ll> e[maxn];
ll a[maxn], s;
int n;
struct Node {
    ll v, need;
} dp[maxn];


void dfs(int r) {
    if (e[r].empty()) 
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%lld", &n, &s);
    f(i, 1, n) {
        ll x;
        scanf("%lld", &x);
        e[x].push_back(i + 1);
    }
}