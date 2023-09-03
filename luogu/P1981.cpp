#include <cstdio>

int ans, x, c, y;
const int M = 10000;

int main() {
#ifdef LOCAL    
    LOCALfo
#endif
    while (~scanf("%d", &x)) {
        x %= M;
        c = getchar();
        if (!~c) {
            ans += x;
            ans %= M;
            break;
        }
        if (c == '*') {
            while (~scanf("%d", &y)) {
                y %= M;
                x *= y;
                x %= M;
                c = getchar();
                if (c == '+') break;
            }
            ans += x, ans %= M;
            if (!~c) break;
        } else ans += x, ans %= M;
    }
    printf("%d", ans);
}