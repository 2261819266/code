#include <cstdio>
#include <algorithm>

const int maxn = 2e5 + 8;
int a[maxn], b[maxn];

int main() {
    int n, min = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        min = std::min(min, a[i]);
        if (!a[i] || (!i || n - i == 1) && a[i] < 0) i--, n--;
        if (i) if (a[i] * a[i - 1] > 0) a[i - 1] += a[i], i--, n--;
    }
    if (n == 0) {
        printf("%d", min);
        return 0;
    }
    b[0] = a[0];
    for (int i = 2; i < n; i += 2) {
        a[i] = std::max(a[i], a[i] + a[i - 1] + b[i - 2]);
        
    }
    
}