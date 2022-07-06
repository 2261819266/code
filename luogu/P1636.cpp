#include <cstdio>

const int maxn = 1005;
const int maxm = 100005;

int head[maxn];

int u, v, c, n, m, d;

int main() {

#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    scanf("%d%d", &n, &m);

    for (c = 0; c < m; c++)
        scanf("%d%d", &u, &v), head[u]++, head[v]++;

    for (c = 1; c <= n; c++)
        if (head[c] % 2)
            d++;
    d /= 2;
    if (d)
        printf("%d", d);
    else
        printf("1");
}