#include <cstdio>
#include <vector>
#include <algorithm>
#define f(x, y, z) for (auto x = y, __ = z; x < z; ++x)

const int maxn = 305;
std::vector<int> to[maxn];
int value[maxn], n, m, dp[maxn][maxn];

void dfs(int r) {
    for (int i : to[r]) dfs(to[r][i]);
     
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d", &n, &m);
    m++;
    f(i, 1, n + 1) {
        int fa;
        scanf("%d", &fa);
        to[fa].push_back(i);
    }
}