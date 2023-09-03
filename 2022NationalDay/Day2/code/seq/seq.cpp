#include <cstdio>
#include <algorithm>
#include <vector>

using std::vector;
#define fo(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);

const int maxn = 1e3 + 8;
vector<int> a, dp, mp(maxn, 0);
int maxmp = 0, maxdp = 1;

void seq() {
    int n, m;
    scanf("%d%d", &n, &m);
    a.push_back(0);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a.push_back(x);
        mp[x]++;
        maxmp = std::max(maxmp, mp[x]);
    }
    dp.assign(a.size(), 1);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[j] <= a[i]) 
                dp[i] = std::max(dp[i], dp[j] + 1);
        }
        maxdp = std::max(maxdp, dp[i]);
    }
    printf("%lld\n", 1ll * (m - 1) * (maxmp) + maxdp);
}

int main() {
    fo(seq)
    seq();
    return 0;
}