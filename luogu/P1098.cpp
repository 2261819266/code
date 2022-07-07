#include <cstdio>
#include <cstring>
#include <algorithm>
#define f(x, y, z) for (int x = (y), __ = (z); x < __; x++)
#define isNumber(x) (x >= '0' && x <= '9')
#define isLetter(x) (x >= 'a' && x <= 'z')
#define isOk(x, y) (isNumber(x) && isNumber(y) || isLetter(x) && isLetter(y))

int p[3];
char a[10001], b[10001], c[10001];

template<typename t>
void read(t &x) {
    x = 0;
    int f = 1, c = 0;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar(); 
    }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    x *= f;
}

template<typename t>
void write(t &x) {
    if (x < 0) putchar('-');
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    f(i, 0, 3) read(p[i]);
    scanf("%s", a);
    for (int i = 0; a[i]; i++) {
        if (a[i] == '-' && isOk(a[i - 1], a[i + 1])&& a[i - 1] < a[i + 1]) {
            sprintf(b, "%s", a + i + 1);
            int num = a[i + 1] - a[i - 1] - 1;
            int l = 0;
            f(j, a[i - 1] + 1, a[i + 1]) {
                f(k, 0, p[1]) c[l++] = j;
            }
            if (*p == 2) f(j, 0, l) if (isLetter(c[j])) c[j] -= 0x20;
            if (*p == 3) f(j, 0, l) c[j] = '*';
            if (p[2] - 1) f(j, 0, l / 2) std::swap(c[j], c[l - j - 1]);
            sprintf(a + i, "%s", c);
            sprintf(a + i + num * p[1], "%s", b);
        }
    }
    printf("%s", a);
}