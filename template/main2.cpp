#include <cstdio>
// #include "SegTree"
template<typename T>
class SegTree {
#define mid ((l + r) >> 1)
private:
    struct Node {
        Node *ls, *rs;
        T sum, lazy;
        Node operator=(const T &x) { sum = x; return *this;}
        Node operator+(const T &x) const { return {ls, rs, sum + x}; }
        Node operator+=(const T &x) { return *this = *this + x; }
        void pushdown(int l, int r) {
            ls->lazy += lazy;
            rs->lazy += lazy;
            ls->sum += (mid - l + 1) * lazy;
            rs->sum += (r - mid) * lazy;
            lazy = 0;
        }

        void pushup() {
            sum = 0;
            if (ls) sum += ls->sum;
            if (rs) sum += rs->sum;
        }
    } *root;

    
    void modify(Node *p, int l, int r, int i, T x) {
        if (l == r) {
            p->sum = x;
            return;
        }
        if (i <= mid) {
            if (!p->ls) p->ls = new Node();
            modify(p->ls, l, mid, i, x);
        } else {
            if (!p->rs) p->rs = new Node();
            modify(p->rs, mid + 1, r, i, x);
        }
        p->pushup();
    }

    T query(Node *p, int l, int r, int L, int R) {
        if (l > R || L > r) return 0;
        if (l >= L && r <= R) return p->sum;
        p->pushdown(l, r);
        return query(p->ls, l, mid, L, R) + query(p->rs, mid + 1, r, L, R);
    }


    void add(Node *p, int l, int r, int L, int R, T x) {
        if (l > R || L > r) return;
        if (l >= L && r <= R) {
            p->sum += (r - l + 1) * x;
            p->lazy += x;
            return;
        }
        p->pushdown(l, r);
        add(p->ls, l, mid, L, R, x);
        add(p->rs, mid + 1, r, L, R, x);
        p->pushup();
    }
public:
    SegTree() { root = new Node(); }

    void modify(int n, int i, T x) { modify(root, 1, n, i, x); }

    T query(int n, int L, int R) { return query(root, 1, n, L, R); }

    void add(int n, int L, int R, T x) { add(root, 1, n, L, R, x); }
#undef mid
};


#define ll long long
SegTree<ll> sgt;

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        ll x;
        scanf("%lld", &x);
        sgt.modify(n, i, x);
    }
    for (int i = 0; i < m; i++) {
        int op, l, r;
        ll x;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1) 
            scanf("%lld", &x), sgt.add(n, l, r, x);
        else printf("%lld\n", sgt.query(n, l, r));
    }
}