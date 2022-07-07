#include <cstdio>
#include <algorithm>

const int maxn = 101;
int a[maxn];

int main() {
#ifdef LOCAL    
    LOCALfo
#endif
    int n, m, y = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int w;
        scanf("%d", &w);
        int minx = 0x7fffffff, minid;
        for (int i = 0; i < m; i++) {
            if (a[i] < minx) minx = a[i], minid = i;
        }
        a[minid] += w;
        y = a[minid];
    }
    int max;
    for (int i = 0; i < m; i++) {
        max = std::max(max, a[i]);
    }
    printf("%d", max);
}