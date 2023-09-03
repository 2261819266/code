#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

const int maxn = 1e5 + 8;
// struct SegTree {
// #define mid (l + r) / 2
//     struct Node {
//         Node *ls, *rs;
//         int sum;
//     };

//     void modify(Node *)
// };

struct Node {
#define mid ((l + r) / 2)
#define Ls l, mid
#define Rs mid + 1, r
#define num (r - l + 1)
    Node *ls, *rs;
    int sum, lazy;

    void modify(int l, int r, int i, int x) {
        if (l == r) {
            sum = x;
            return;
        }
        if (i <= mid) {
            if (!ls) ls = new Node();
            ls->modify(Ls, i, x);
        } else {
            if (!rs) rs = new Node();
            rs->modify(Rs, i, x);
        }
        pushup();
    }

    void pushdown(int l, int r) {
        if (ls)
            ls->lazy += lazy,
            ls->sum += lazy * (mid - l + 1);
        if (rs)
            rs->lazy += lazy,
            rs->sum += lazy * (r - mid);
        lazy = 0;
    }

    void pushup() {
        sum = 0;
        if (ls) sum += ls->sum;
        if (rs) sum += rs->sum;
    }

    void add(int l, int r, int L, int R) {
        if (l > R || L > r) return;
        if (l >= L && r <= R) {
            sum += num;
            lazy++;
            return;
        }
        pushdown(l, r);
        ls->add(Ls, L, R);
        rs->add(Rs, L, R);
        pushup();
    }

    int ask(int l, int r, int i) {
        if (l == r) return sum;
        pushdown(l, r);
        return i <= mid ? ls->ask(Ls, i) : rs->ask(Rs, i);
    }
};

int n, m;
std::vector<int> e[maxn];
int fa[maxn], dep[maxn], size[maxn], top[maxn], hsonmax[maxn], son[maxn];
Node *a[maxn];

void dfs1(int u = 1) {
    size[u] = 1;
    for (int v : e[u]) {
        if (dep[v]) continue;
        dep[v] = dep[u] + 1;
        fa[v] = u;
        dfs1(v);
        size[u] += size[v];
    }
}

void dfs(int u = 1) {
    std::queue<int> q;
    q.push(u);
    while (!q.empty()) {
        
    }
}

void dfs2(int u = 1, int t = 1) {
    top[u] = t;
    int x = 0;
    for (int v : e[u]) {
        if (dep[v] == dep[u] + 1 && size[v] > size[x])
            x = v;
    }
    if (x)
        dfs2(x, t), son[u] = x;
    hsonmax[u] = hsonmax[x] + 1;
    for (int v : e[u]) {
        if (dep[v] == dep[u] + 1 && x != v) 
            dfs2(v, v);
    }
}

void dfs3(int u = 1) {
    if (top[u] == u) a[u] = new Node();
    a[top[u]]->modify(1, hsonmax[top[u]], dep[u] - dep[top[u]] + 1, 0);
    if (son[u]) dfs3(son[u]);
    for (int v : e[u]) {
        if (dep[v] == dep[u] + 1 && v != son[u]) {
            dfs3(v);
        }
    }
}  

void add(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) 
            std::swap(u, v);
        a[top[u]]->add(1, hsonmax[top[u]], 1, dep[u] - dep[top[u]] + 1);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) 
        std::swap(u, v);
    a[top[u]]->add(1, hsonmax[top[u]], dep[v] - dep[top[u]] + 2, dep[u] - dep[top[u]] + 1);
}

int query(int u, int v) {
    if (dep[u] < dep[v]) 
        std::swap(u, v);
    return a[top[u]]->ask(1, hsonmax[top[u]], dep[u] - dep[top[u]] + 1);
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    fa[1] = 1;
    dep[1] = 1;
    dfs1();
    dfs2();
    dfs3();
    for (int i = 0; i < m; i++) {
        int u, v;
        char op[10];
        scanf("%s%d%d", &op, &u, &v);
        if (op[0] == 'P') {
            add(u, v);
        } else {
            printf("%d\n", query(u, v));
        }
    }
}