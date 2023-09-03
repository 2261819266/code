#include <cstdio>
#define fo(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);

int main() {
    fo(a)
    int n;
    scanf("%d", &n);
    int now = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x > now) ans++;
        now = x;
    }
    printf("%d", ans);
}