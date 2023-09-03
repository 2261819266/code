#include <cstdio>
#define f(x, y, z) for (int x = y, __ = z; x < __; ++x)

const int maxn = 5e5 + 8;
int a[maxn];
int n, m, L;

bool check(int x) {
    int tot = 0;
    int i = 0;
    int now = 0;
    while (i < n + 1){
        i++;
        if (a[i] - a[now] < x)
            tot++;
        else
            now = i;
    }
    if (tot > m)
        return false;
    else
        return true;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d%d", &L, &n, &m);
    a[n + 1] = L;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    int l = 0, r = L + 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        auto placeholder = check(mid);
        placeholder ? l = mid : r = mid - 1;
    }    
    printf("%d", l);
}