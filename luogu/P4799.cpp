#include <cstdio>
#include <queue>
#include <algorithm>
#define ll long long
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)

const int maxn = 42;
ll a[maxn];
ll sum[2][1 << (maxn / 2)];

using std::queue;
queue<bool> getBin(int x) {
    queue<bool> q;
    while (x) {
        q.push(x % 2);
        x /= 2;
    }
    return q;
}

int main() {
#ifdef LOCAL    
    LOCALfo
#endif
    int n; ll m;
    scanf("%d%lld", &n, &m);
    f(i, 0, n) {
        scanf("%lld", a + i);
    }
    int mid = n / 2;
    f(i, 0, 1 << mid) {
        auto q = getBin(i);
        for (int j = 0; !q.empty(); ++j) {
            int u = q.front();
            q.pop();
            sum[0][i] += u * a[j];
        }
    }
    f(i, 0, 1 << (n - mid)) {
        auto q = getBin(i);
        for (int j = 0; !q.empty(); ++j) {
            int u = q.front();
            q.pop();
            sum[1][i] += u * a[j + mid];
        }
    }
    std::sort(sum[0], sum[0] + (1 << mid));
    std::sort(sum[1], sum[1] + (1 << (n - mid)));
    ll ans = 0;
    f(i, 0, 1 << mid) {
        if (sum[0][i] > m) break;
        ans += std::lower_bound(sum[1], sum[1] + (1 << (n - mid)), m - sum[1][i] + 1) - sum[1];
        // ans 
    }
    printf("%lld", ans);
}