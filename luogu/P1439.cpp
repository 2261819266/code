#include <cstdio>
#include <algorithm>

const int maxn = 1e5 + 8;
int a[maxn], b[maxn], dp[maxn][];

using std::max;

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", b + i);
    }
}