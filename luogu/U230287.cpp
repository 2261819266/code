#include <cstdio>

const int maxn = 105;
char s[maxn];

int main() {
#ifdef LOCAL
    LOCALfo
// #else
// #define fo(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);
//     fo(title)
#endif  
    int n, ans = 0;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        fgets(s, maxn, stdin);
        char *p = s;
        while (*p == ' ') {
            p++;
        }
        if (*p == '#' && p[1] == ' ') {
            ans++;
            p++;
            while (*p == ' ') p++;
            if (*p == '\n') ans--;
        }
    }
    printf("%d", ans);
}