#include <cstdio>

int n, m;

int solve(int n, int m, int last = 1) {
    if (m == 1) return n >= last;
    int ans = 0;
    for (int i = last; i * m <= n; i++) {
        ans += solve(n - i, m - 1, i);
    }
    return ans;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d", &n, &m);
    printf("%d", solve(n, m));
}