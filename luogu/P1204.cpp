#include <cstdio>
#include <algorithm>

const int maxn = 5e3 + 8;
struct Person {
    int x, y;
    bool operator<(const Person &b) { return x < b.x; }
} a[maxn];
int n;

int getMaxHaveTime() {
    int s = a->x, e = a->y, ans = e - s;
    for (int i = 1; i < n; i++) {
        if (a[i].x > e) s = a[i].x;
        e = std::max(e, a[i].y);
        ans = std::max(ans, e - s);
    }
    return ans;
}

int getMaxNoneTime() {
    int s = a->y, e = a[1].x, ans = std::max(0, e - s);
    for (int i = 1; i < n; i++) {
        s = std::max(s, a[i].y);
        e = a[i + 1].x;
        ans = std::max(ans, e - s);
    }
    return ans;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    std::sort(a, a + n);
    printf("%d %d", getMaxHaveTime(), getMaxNoneTime());
}