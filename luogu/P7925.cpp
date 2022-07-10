#include <cstdio>
#include <vector>
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)

const int maxn = 6005;
std::vector<int> e[maxn];
int a[maxn], s, n;

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d", &n, &s);
    f(i, 1, n) {
        int x;
        scanf("%d", &x);
        e[x].push_back(i + 1);
    }
}