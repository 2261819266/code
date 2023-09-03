#include <cstdio>
#include <cstring>
#include <string>
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))
#define maxn 10005

struct high {

    void init() { memset(data, 0, sizeof(data)), len = 0; }

    void operator=(const char *str) {
        init();
        len = strlen(str);
        for (int c = 0; c < len; c++) {
            data[c] = str[len - c - 1] - '0';
        }
    }

    void arr() {
        if (data[len - 1] == 0 && len > 1)
            len--, arr();
        return;
    }

    void print(const char *str = "\n") const {
        for (int c = 0; c < len; c++)
            printf("%d", data[len - c - 1]);
        printf("%s", str);
    }

    int &operator[](int x) { return data[x]; }

    int data[maxn];
    int len;
};

high operator+(high a, high b) {
    high h;
    h.init();
    int na = a.len, nb = b.len, n = max(na, nb), c, d = 0;
    for (int c = 0; c <= n ; c++) {
        h[c] = a[c] + b[c] + d;
        d = h[c] / 10;
        h[c] %= 10;
    }
    h.len = n+1;
    h.arr();
    return h;
}

int main() {
    high a, b, he;
#ifdef LOCAL
    freopen("E:\\code\\in.in", "r", stdin);
    freopen("E:\\code\\out.out", "w", stdout);
#endif

    char *str = new char;
    scanf("%s", str);
    a = str;
    scanf("%s", str);
    b = str;
    he = a + b;
    he.print();
}