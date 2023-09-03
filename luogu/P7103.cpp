#include <cstdio>

const int maxn = 5e6 + 8;
struct Node {
    int fa, depth;
} a[maxn];

int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[i].fa = x;
        a[i].depth = a[a[i].fa].depth + 1;
    }
}