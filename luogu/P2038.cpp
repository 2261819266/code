#include <cstdio>
#include <algorithm>
#define ll long long
#define f(x, y, z) for (auto x = (y), __ = (z); x < __; ++x)

const int maxn = 200;
int n, m;
ll b[maxn][maxn], a[maxn][maxn];

ll get(int x1, int y1, int x2, int y2) {
    x1--, y1--;
    ll s1 = a[x2][y2], 
    s2 = a[x1][y2], 
    s3 = a[x2][y1], 
    s4 = a[x1][y1];
    if (x1 < 0) s2 = s4 = 0;
    if (y1 < 0) s3 = s4 = 0;
    ll s = s1 + s4 - s2 - s3;
    return s;
}

int main() {
#ifdef LOCAL    
    LOCALfo
#endif
    scanf("%d%d", &n, &m);
    f(i, 0, m) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        b[x][y] += z;
    }
    f(i, 0, 129) {
        f(j, 0, 129) {
            if (!(i | j)) a[i][j] = b[i][j];
            else if (!i) a[i][j] = a[i][j - 1] + b[i][j];
            else if (!j) a[i][j] = a[i - 1][j] + b[i][j];
            else a[i][j] = b[i][j] + a[i][j -1] + a[i - 1][j] - a[i - 1][j - 1];
        }
    }
    ll ans = 0;
    f(i, 0, 129) {
        f(j, 0, 129) {
            int x1 = std::max(0, i - n);
            int y1 = std::max(0, j - n);
            int x2 = std::min(128, i + n);
            int y2 = std::min(128, j + n);
            ans = std::max(ans, get(x1, y1, x2, y2));
        }
    }
    ll num = 0;
    f(i, 0, 129) {
        f(j, 0, 129) {
            int x1 = std::max(0, i - n);
            int y1 = std::max(0, j - n);
            int x2 = std::min(128, i + n);
            int y2 = std::min(128, j + n);
            if (ans == get(x1, y1, x2, y2)) 
                num++;
        }
    }
    printf("%lld %lld", num, ans);
}