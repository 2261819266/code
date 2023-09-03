#include <cstdio>
#include <cstdlib>
#define fo(x)                      \
    freopen(#x ".in", "r", stdin); \
    freopen(#x ".out", "w", stdout);
#define ll long long

const int M = 998244353, maxn = 2e6 + 8;
int a[maxn], r, b, k;
int n, m;
ll anss[2], p[maxn];

void dfs(int x, ll ans = 1) {
    if (x == k) {
        // for (int i = 0; i < k; i++) {
        //     // printf("%c ", a[i] + 'A');
        // }
        if (ans > 1)
            ans /= 2;
        // printf("%d\n", ans);
        anss[a[x - 1]] += ans;
        anss[a[x - 1]] %= M;
        return;
    }
    if (r == n || b == m)
        ans <<= 1;
    if (r < n) {
        r++;
        a[x] = 0;
        dfs(x + 1, ans);
        r--;
    }
    if (b < m) {
        b++;
        a[x] = 1;
        dfs(x + 1, ans);
        b--;
    }
}

void init() {
    p[0] = 1;
    for (int i = 1; i < maxn; i++) {
        p[i] = p[i - 1] * 2 % M;
    }
}

// int main() {
//     fo(ball);
//     init();
//     scanf("%d%d", &n, &m);
//     k = n + m;
//     if (n == m) {
//         printf("%lld", p[n + m - 2]);
//         return 0;
//     }
//     dfs(0);
//     printf("%d\n", anss[1] % M);
// }

int main() {
    // system("make.exe");
    // fo(ball);
    // int q;
    // scanf("%d", &q);
    // for (int i = 0; i < q; i++) {
    //     scanf("%d%d", &n, &m);
    //     k = n + m;
    //     anss[0] = anss[1] = 0;
    //     dfs(0);
    //     printf("%d\n", anss[1]);
    // }
    // for (int i = 0; i <= 11; i++) {}
    n = 8, m = 10;
    k = n + m;
    dfs(0);
    printf("%d", anss[1]);
}