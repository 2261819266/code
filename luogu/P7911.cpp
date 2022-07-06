#include <cstdio>
#include <cstring>

const int maxn = 1e3 + 2;
struct Node {
#define isNumber(x) (x >= '0' && x <= '9')
#define isString(x) (x == '.' || x == ':')
    int k;
    char a[100];
    void scan() {
        char s[10];
        scanf("%s", s);
        if (*s == 'C') k = 1;
        scanf("%s", a);
    }

    operator bool() {
        if (a[0] == '0') return false;
        for (int i = 0, j = 0; a[i]; i++) {
            if (a[i] == ':' && j <= 2 || a[i] == '.' && j > 2) return false;
            if (isString(a[i])) j++;
        }

    }
} a[maxn];

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        a[i].scan();
        printf("%d", a[i].operator bool());
    }
}
