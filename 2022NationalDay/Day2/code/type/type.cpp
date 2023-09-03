#include <cstdio>
#include <vector>
#include <algorithm>

#define fo(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);
#define ll long long

using std::vector;
vector<ll> rs;

struct Node {
    int x, k;  
    ll n, t, l, r;
    Node() {}
    Node(int x, const Node &last) {
        k = 1;
        this->x = x;
        l = last.r;
        r = l + 1;
        rs.push_back(r);
    }
    Node(int x, int y, const Node &last) {
        k = 2;
        l = last.r;
        r = l + x * y;
        n = x;
        t = y;
        rs.push_back(r);
    }

    // bool operator<(const Node &b) const {
    //     return this->l < b.l;
    // }
} none;

vector<Node> a;

int get(ll x) {
    int i = std::upper_bound(rs.begin(), rs.end(), x) - rs.begin();
    if (i == a.size()) i--;
    if (a[i].k == 1) {
        return a[i].x;
    } else {
        ll y = x - a[i].l;
        y %= a[i].n;
        return get(y);
    }
}

void type() {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int k, x, y;
        scanf("%d%d", &k, &x);
        if (k == 1) {
            Node node(x, a.empty() ? none : a.back());
            a.push_back(node);
        } else {
            scanf("%d", &y);
            Node node(x, y, a.empty() ? none : a.back());
            a.push_back(node);
        }
    }
    scanf("%d", &m);
    // vector<ll> q;
    for (int i = 0; i < m ; i++) {
        ll x;
        scanf("%lld", &x);
        printf("%d\n", get(x - 1));
        // q.push_back(x);
    }
    // std::sort(q.begin(), q.end());
    // int i = 0;
    // for (int x : q) {
    //     while (x >= a[i].r) i++;
    // }
}

int main() {
    fo(type);
    type();
    return 0;
}