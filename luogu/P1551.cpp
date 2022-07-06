#include <cstdio>

const int maxn = 5000 + 10;
int fa[maxn];

void init(int n) {
    for (int c = 1; c <= n; c++)
        fa[c] = c;
}

int find_fa(int x) {
    if (x != fa[x])
        fa[x] = find_fa(fa[x]);
    return fa[x];
}

void union_fa(int x, int y) {
    int a = find_fa(x), b = find_fa(y);
    if (a != b)
        fa[b] = a;
}

int main() {
    int n, m, q, c, x, y;
    scanf("%d%d%d", &n, &m, &q);

    init(n);

    for (c = 0; c < m; c++)
        scanf("%d%d", &x, &y), union_fa(x, y);

    for (c = 0; c < q; c++) {
        scanf("%d%d", &x, &y);
        if (find_fa(x) != find_fa(y))
            printf("No\n");
        else
            printf("Yes\n");
    }
}