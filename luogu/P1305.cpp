#include <cstdio>
#include <cstring>
#define f(x, y, z) for (auto x = (y), __ = (z); x < __; ++x)

const int maxn = 30;
int ls[maxn], rs[maxn], fa[maxn];

void dfs(int root) {
    printf("%c", root + 'a');
    if (~ls[root]) dfs(ls[root]);
    if (~rs[root]) dfs(rs[root]);
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n;
    memset(ls, -1, sizeof(ls));
    memset(rs, -1, sizeof(rs));
    memset(fa, -1, sizeof(fa));
    scanf("%d", &n);
    f(i, 0, n) {
        char s[10];
        scanf("%s", s);
        int x = s[0] - 'a';
        int y = s[1] - 'a';
        int z = s[2] - 'a';
        if (y >= 0) ls[x] = y, fa[y] = x;
        if (z >= 0) rs[x] = z, fa[z] = x;
    }
    int root;
    f(i, 0, n) {
        if (!~fa[i] && (~ls[i] || ~rs[i])) root = i;
    }
    dfs(root);
}   