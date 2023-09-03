#include <cstdio>
#include <algorithm>
#include <cmath>

struct Point {
    int x, y;
};

const int maxn = 100;
int a[maxn][maxn], n, m, k;

Point findMax() {
    Point max = (Point) {};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] > a[max.x][max.y])
                max = (Point) {i, j};
        }
    }
    return max;
}

int getAway(Point x, Point y) { return abs(x.x - y.x) + abs(x.y - y.y); }

int main () {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    Point next = findMax(), now = (Point) {1, next.y};
    int ans = 0;
    k -= 2;
    while (getAway(now, next) + next.x <= k) {
        k -= getAway(now, next) + 1;
        now = next;
        ans += a[now.x][now.y];
        a[now.x][now.y] = 0;
        next = findMax();
    }
    printf("%d", ans);
}