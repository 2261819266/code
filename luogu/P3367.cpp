#include <cstdio>

const int maxn = 200000 + 100;
int fa[maxn];

void init(int n) {
    for (int c = 1; c <= n; c++)
        fa[c] = c;
}

int find_fa(int x) {
    if (fa[x] != x)
        fa[x] = find_fa(fa[x]);
    return fa[x];
}

void union_fa(int x, int y) {
    int a = find_fa(x), b = find_fa(y);
    if (a != b)
        fa[b] = a;
}

int main() {
    int n, m, x, y, z, c;
    scanf("%d%d", &n, &m);
    init(n);
    for (c = 0; c < m; c++) {
        scanf("%d%d%d", &z, &x, &y);
        if (z == 1)
            union_fa(x, y);
        else if (find_fa(x) != find_fa(y))
            printf("N\n");
        else
            printf("Y\n");
    }
}