#include <cstdio>

const int maxn = 32768 + 8;
bool is[maxn];

void SP3394() {
    while (true) {
        int n, ans = 0;
        scanf("%d", &n);
        if (!n) return;
        for (int i = 0; i * i < n; i++) {
            for (int j = i; j * j + i * i < n; j++) {
                for (int k = j; ; k++) {
                    int x = n - k * k - i * i - j * j;
                    if (k * k > x) break;
                    if (is[x]) 
                        ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
}


int main() {
#ifdef LOCAL
    LOCALfo
#endif
    SP3394();
    return 0;
}