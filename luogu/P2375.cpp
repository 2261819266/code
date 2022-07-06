#include <cstdio>
#define ll long long

const int maxn = 1e6 + 8, B = 1e9 + 7;

char s[maxn];
int next[maxn];
int n;

void kmp() {
    next[0] = 0; int now = 0;
    for (int i = 0; s[i]; ) {
        if (s[i] == s[now] && 2 * now + 2 <= i + 1) next[i++] = ++now;
        else if (now) now = next[now - 1];
        else next[i++] = now;
    }
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif  
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ll ans = 1;
        scanf("%s", s);
        kmp();
        for (int i = 0; s[i]; i++) ans *= next[i] + 1, ans %= B;
        printf("%lld\n", ans);
    }
}