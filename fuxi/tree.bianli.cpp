#include <cstdio>
#include <vector>

const int maxn = 1001;
std::vector<int> g[maxn];

void Link(int x, int y) {
    g[x].push_back(y);
    // g[y].push_back(x);
}

void dfs(int x, int fa) {
    printf("%d ", x);
    for (int c = 0; c < g[x].size(); c++)
        if (g[x][c] != fa)
            dfs(g[x][c], x);
}

int x, y, n, root;
int main() {
    scanf("%d", &n);
    for (int c = 1; c < n; c++)
        scanf("%d%d", &x, &y), Link(x, y);
    root = 1;
    dfs(root, 0);
}