#include <cstdio>
#include <cmath>
#include <algorithm>

double f(int x, int y) {
    return sqrt(x * x + y * y);
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int T, n, m;
    scanf("%d%d", &T, &T);
    for (int i = 0; i < T; i++) {
        scanf("%d%d", &n, &m);
        int x = (n + 1) / 2, y = (m + 1) / 2;
        double ans = 0;
        for (int i = 1; i <= n; i += 2) {
            if (n % 2 == 0 && i == n / 2 + 2) {
                i++;
            }
            for (int j = 1; j <= m; j += 2) {
                if (m % 2 == 0 && j == m / 2 + 1) {
                    j++;
                }
                int mi = (n + 1) / 2;
                int mj = (m + 1) / 2;
                int k = 2 * (i < mi) + (j < mj);
                double a, b, c, d;
                a = f(i - 1, j - 1); 
                 b = f(i - 1, m - j); 
                c = f(n - i, j - 1); 
                d = f(n - i, m - j); 
                using std::max;
                ans += max(max(a, b), max(c, d));
            }
        }
        if (x * y == 1) ans = 0;
        printf("%d %.9lf\n", n * m - x * y, ans);
    }
}