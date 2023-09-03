#include <cstdio>
#include <queue>
#include <algorithm>
#define ll long long

const int maxn = 1e5 + 8;
struct Node {
#define mid ((l + r) / 2)
#define Ls l, mid
#define Rs mid + 1, r
    Node *ls, *rs;
    ll sum, lazy;
    void pushup() {
        sum = 0;
        if (ls) sum += ls->sum;
        if (rs) sum += rs->sum;
    }

    Node *modify(int l, int r, int i, ll x) {
        if (l == r) {
            sum = x;
            return this;
        } 
        Node *returned;
        if (i <= mid) {
            if (ls) ls = new Node();
            returned = ls->modify(Ls, i, x);
        } else {
            if (rs) rs = new Node();
            returned = rs->modify(Rs, i, x);
        }
        pushup();
        return returned;
    }

    void pushdown(int l, int r) {
        if (ls) 
            ls->sum += lazy * (mid - l + 1),
            ls->lazy += lazy;
        if (rs)
            rs->sum += lazy * (r - mid),
            rs->lazy += lazy;
        lazy = 0;
    }

    void add(int l, int r, int L, int R, ll x) {
        if (l > R || L > r) return;
        if (l >= L && r <= R) {
            sum += x * (r - l + 1);
            lazy += x;
        }
        pushdown(l, r);
        add(Ls, L, R, x);
        add(Rs, L, R, x);
        pushup();
    }
};

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    
}