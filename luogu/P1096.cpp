#include <cstdio>
#include <cstring>
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)

struct BigInterger {
    static const int maxn = 2001;
    int a[maxn], len;
    BigInterger() { memset(a, 0, sizeof(a)), a[0] = len = 1; }
    BigInterger operator*(int x) {
        int d;
        f(i, 0, len) {
            a[i] = a[i] * x + d;
            d = a[i] / 10;
            a[i] %= 10;
            if (d && i == len - 1) __++, len++;
        }
        return *this;
    }

    void updata() {
        a[0] -= 2;
        int d = a[0] < 0;
        for (int i = 1; i < len && d; ++i) {
            if (a[i]) d = 0, a[i]--;
            else a[i] = 9;
        }
    }

    BigInterger operator*=(int x) { return *this = *this * x; }

    void write(int i = 0) {
        if (i == len) return;
        write(i + 1);
        putchar(a[i] + '0');
    }
} a;

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int x;
    scanf("%d", &x);
    f(i, 0, x + 1) {
        a *= 2;
    }
    a.updata();
    a.write();
}
