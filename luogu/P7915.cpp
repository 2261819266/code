#include <cstdio>

const int maxn = 5e1 + 8;

int a[maxn], b[maxn], c[maxn];

struct set {
    int l, r;
    set operator-(const set &y) {
        return (set) {l - y.l, r - y.r};
    }
    bool operator==(const set &y) {
        return l == y.l && r == y.r;
    }
};

void print(int n) {
    int l = 0, r = n;
    for (int i = 1; i <= n; i++) {
        printf("%c", "LR"[c[i]]);
        c[i] ? l++ : r--;
    }
    puts("");
}

bool f(set x, set y, int n, int i = 1) {
    if (i == n / 2) {
        print(n);
        return true;
    }
    i++;
    x.l++;
    bool k;
    if (a[x.l] == a[y.l - 1]) {
        y.l--;
        k = f(x, y, n, i);
        y.l++;
        if (k) return true;
    }
    if (a[x.l] == a[y.r + 1]) {
        y.r++;
        k = f(x, y, n, i);
        y.r--;
        if (k) return true;
    }
    x.l--;
    x.r--;
    if (a[x.r] == a[y.l - 1]) {
        y.l--;
        c[i]++;
        k = f(x, y, n, i);
        c[i]--;
        y.l++;
        if (k) return true;
    }
    if (a[x.r] == a[y.r + 1]) {
        y.r++;
        c[i]++;
        k = f(x, y, n, i);
        c[i]--;
        y.r--;
        if (k) return true;
    }
    return false;
}

bool solve(int n) {
    set x = {1, n + 1}, y;
    b[0] = a[0];
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[1]) y = (set) {i, i}; 
    }
    c[0] = 0;
    bool k = f(x, y, n);
    if (k) return true;
    x = (set) {0, n};
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[n]) y = (set) {i, i}; 
    }
    c[0] = 1;
    k = f(x, y, n);
    if (k) return true;
    return false;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        for (int i = 1; i <= m * 2; i++) {
            scanf("%d", a + i);
        }
        int k = solve(m * 2);
    }
}