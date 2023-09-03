#include <cmath>
#include <cstdio>
#include <cstring>
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))
#define swap(X, Y) ((X) ^= (Y) ^= (X) ^= (Y))
#define maxn 10005

struct high {

    void init() { memset(data, 0, sizeof(data)), len = 0; }

    high operator=(const char *str) {
        init();
        len = strlen(str);
        for (int c = 0; c < len; c++) {
            data[c] = str[len - c - 1] - '0';
        }
        return *this;
    }
    high operator=(int x) {
        init();
        int c;
        for (c = 0; x > 0; c++)
            data[c] = x % 10, x /= 10;
        len = c;
        return *this;
    }

    void ar() {
        if (data[len - 1] == 0 && len > 1)
            len--, ar();
        return;
    }

    void arr() {
        ar();
        memset(data + len, 0, sizeof(data + len));
    }

    void print(const char *str = "\n") {
        arr();
        for (int c = 0; c < len; c++)
            printf("%d", data[len - c - 1]);
        printf("%s", str);
    }

    int &operator[](int x) { return data[x]; }

    int data[maxn];
    int len;
};

high operator<<(high a, int x) {
    if (x == 0)
        return a;
    for (int c = a.len - 1; c >= 0; c--) {
        swap(a[c], a[c + x]);
    }
    a.len += x;
    return a;
}

high operator>>(high a, int x) {
    for (int c = 0; c < a.len; c++) {
        a[c] = a[c + x];
    }
    a.len -= x;
    return a;
}

high operator<<=(high &a, int x) { return a = a << x; }

high operator>>=(high &a, int x) { return a = a >> x; }

high operator+(high a, high b) {
    a.arr();
    b.arr();
    high h;
    h.init();
    int na = a.len, nb = b.len, n = max(na, nb), c, d = 0;
    for (int c = 0; c <= n; c++) {
        h[c] = a[c] + b[c] + d;
        d = h[c] / 10;
        h[c] %= 10;
    }
    h.len = n + 1;
    h.arr();
    return h;
}

high operator+(high a, int x) {
    high b;
    b.init();
    b = x;
    return a + b;
}

high operator+(int x, high b) { return b + x; }

high operator+=(high &a, int x) { return a = a + x; }
high operator+=(high &a, high b) { return a = a + b; }
high operator++(high &a) {
    a += 1;
    return a;
}
high operator++(high &a, int) {
    ++a;
    return a;
}

high operator*(high a, int x) {
    a.arr();
    high h;
    h.init();
    int n = a.len += 10;
    for (int c = 0, d = 0; c < n; c++) {
        h[c] = a[c] * x + d;
        d = h[c] / 10;
        h[c] %= 10;
    }
    h.len = n;
    h.arr();
    return h;
}
high operator*(int x, high b) { return b * x; }

high operator*(high a, high b) {
    a.arr();
    b.arr();
    high h, x, z;
    h.init(), x.init(), z = 1;
    int na = a.len, nb = b.len, n = na + nb;
    for (int c = 0; c <= n; c++) {
        x = (a * b[c]);
        x <<= c;
        h += x;
    }
    h.arr();
    return h;
}

high operator*=(high &a, int x) { return a = a * x; }
high operator*=(high &a, high b) { return a = a * b; }

int main() {
    high a, b, he;
    he = 0;
#ifdef LOCAL
    freopen("E:\\code\\in.in", "r", stdin);
    freopen("E:\\code\\out.out", "w", stdout);
#endif
    int c, d, e, n, f;
    scanf("%d", &n);
    for (c = 1; c <= n; c++) {
        scanf("%d", &e);
        a = 1;
        for (d = 1; d <= e; d++) {
            a *= d;
        }
        scanf("%d", &e);
        f = 0;
        for (int d = 0; d < a.len; d++)
            if (a[d] == e)
                f++;
        printf("%d\n", f);
    }
}