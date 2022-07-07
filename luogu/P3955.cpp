#include <cstdio>
#include <cstring>
#define f(x, y, z) for (auto x = y, __ = z; x < __; x++) 

const int maxn = 1005;
int n, q;
char a[maxn][20], b[maxn], l[maxn];

bool find(const char *q, const char *s, int ls) {
    int lq = strlen(q);
    f(i, 0, lq) {
        if (q[i] - s[ls - lq + i]) return false;
    }
    return true;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d", &n, &q);
    f(i, 0, n) {
        scanf("%s", a[i]);
        l[i] = strlen(a[i]);
    }
    f(i, 0, q) {
        int lb;
        scanf("%d%s", &lb, b);
        int now = -1;
        f(j, 0, n) {
            if (find(b, a[j], l[j])) {
                if (~now) {
                    if (l[now] > l[j]) 
                    now = j;
                    if (l[now] == l[j] && strcmp(a[now], a[j]) > 0) 
                    now = j;
                } else now = j;
            }
        }
        printf("%s\n", ~now ? a[now] : "-1");
    }
}