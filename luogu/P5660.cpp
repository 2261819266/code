#include <cstdio>

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int c, ans = 0;
    while (~(c = getchar())) {
        if (c - '0') ans++;
    }
    printf("%d\n", ans);
}