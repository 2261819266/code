#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
struct Node {
    int sum;
    int t;
    int ans;
    int col;
} tree[maxn << 2];

int n, m;
int t[maxn], col[maxn];
bool vis[maxn];
void pushup(int p)
{
    int ls = p * 2, rs = p * 2 + 1;
    tree[p].sum = tree[ls].sum + tree[rs].sum;
    tree[p].ans = tree[ls].ans + tree[rs].ans;
}

void modify(int p, int l, int r, int x, int v)
{
    if (r < x || l > x || p <= 0 || !p) return;
    if (l == r && l == x) {
        if (v == 1) {
            tree[p].sum --;
        } else {
            tree[p].sum ++;
        }
        tree[p].col = v;
        if (tree[p].col && tree[p].sum > tree[p].t) {
            tree[p].ans = 1;
        }
        if (!tree[p].col || tree[p].sum <= tree[p].t) {
            tree[p].ans = 0;
        }
        return;
    }
    int mid = (l + r) >> 1;
    // modify(p - 1, 1, n, x, v);
    modify(p << 1, l, mid, x, v);
    modify(p << 1 | 1, mid + 1, r, x, v);
    pushup(p);
}

int query(int p, int l, int r, int L, int R) {
    if (l <= L && R <= r) {
        return tree[p].sum;
    }
    int mid = (l + r) >> 1;
    return query(p << 1, l, mid, L, R) + query(p << 1 | 1, mid + 1, r, L, R);
}

void build(int p, int l, int r) {
    if (l == r) {
        tree[p].sum = tree[p].ans = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    pushup(p);
}
int main () {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n >> m;
    for (int i = 2; i <= n; ++i) {
        int p;
        scanf("%d", &p);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
        col[i] = 1;
    }
    build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        int q;
        cin >> q;
        if (q < 0) {
            col[-q] = 1;
            modify(1, 1, n, -q, 1);
        } else {
            col[q] = 0;
            modify(1, 1, n, q, 0);
        }
        int cnt = 0;
        cout << tree[1].ans << " ";
    }
}
