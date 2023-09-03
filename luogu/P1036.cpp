#include <cstdio>

bool su(int a) {
    int c, e = 0;
    if (a > 1) {
        e++;
        for (c = 2; c * c <= a; c++)
            if (a % c == 0)
                e++;
    }
    if (e == 1)
        return true;
    return false;
}

const int maxn = 21;
int a[maxn], n, m, time, zt[maxn];

int findm(int k) {
    int c, d;
    for (c = 1, d = 0; c <= n, d < k; c++)
        if (zt[c])
            d++;
    return c;
}

void dfs(int k, int he = 0) {
    int c, d, e;
    for (c = findm(k - 1); c <= n; c++) {
        if (!zt[c]) {
            zt[c] = true;
            he += a[c];
            if (k == m) {
                if (su(he))
                    time++;
            } else
                dfs(k + 1, he);
            zt[c] = false;
            he -= a[c];
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int c = 1; c <= n; c++)
        scanf("%d", &a[c]);
    dfs(1);
    printf("%d", time);
}