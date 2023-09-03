#include <cstdio>
#include <cstring>
#include <algorithm>
#define f(x, y, z) for (auto x = y, __ = z; x < z; ++x)

const int maxn = 21;
int a[maxn][maxn], n, l[maxn];
char s[maxn][100];
int next[maxn][maxn];
int vis[maxn];

int dfs(int x) {
    vis[x]++;
    int ans = 0;
    f(i, 0, n) {
        if (next[x][i] && vis[i] < 2)
            ans = std::max(dfs(i) + next[x][i], ans);
    }
    vis[x]--;
    return ans;
}

int main() {
#ifdef LOCAL
	LOCALfo
#endif
    scanf("%d", &n);
    f(i, 0, n) {
        scanf("%s", s[i]);
        l[i] = strlen(s[i]);
    }
    f(i, 0, n) {
        f(j, 0, n) {
            f(k, 1, std::min(l[i], l[j])) {
                int x = l[i] - k, y = l[j] - k;
                if (strncmp(s[i] + x, s[j], k) == 0) {
                    next[i][j] = y;
                    break;
                }
            }
        }
    }
    char c[10];
    scanf("%s", c);
    int ans = 0;
    f(i, 0, n) {
        if (*s[i] == *c) 
            ans = std::max(ans, dfs(i) + l[i]);
    }
    printf("%d", ans);
}