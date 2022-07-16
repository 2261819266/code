#include <algorithm>
#include <cstdio>
#include <cmath>
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)

const int maxn = 1e4 + 8;
struct Node {
    int x, y;
} a[maxn];

inline double sqr(int x) {
    return x * x;
}
double dis(const Node &x, const Node &y) {
    return sqrt(sqr(x.x - y.x) + sqr(x.y - y.y));
}

int main() {
#ifdef LOCAL    
    LOCALfo
#endif
    int n;
    scanf("%d", &n);
    f(i, 0, n) {
        scanf("%d%d", &a[i].x, &a[i].y); 
    }
    double ans = 0x7fffffff;
    f(i, 0, n) {
        f(j, i + 1, n) {
            ans = std::min(ans, dis(a[i], a[j]));
        }
    }
    printf("%.4lf", ans);
}