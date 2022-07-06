// 前序遍历
#include <cstdio>

const int maxn = 1005;

struct node {
    int lc, data, rc;
    node() { lc = rc = 0; }
    /* data */
};

node a[maxn];

void preorder_traversal(int x) {
    printf("%d ", x);
    if (a[x].lc)
        preorder_traversal(a[x].lc);
    if (a[x].rc)
        preorder_traversal(a[x].rc);
}

int c, d, e, n, x;

int main() {
    scanf("%d", &n);
    for (c = 1; c < n; c++)
        scanf("%d%d%d", &d, &x, &e), (x == 1 ? a[d].lc : a[d].rc) = e;
}