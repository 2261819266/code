#include <cstdio>

#define fo(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);

const int maxn = 1e5 + 8;
int vis[maxn];


void dfs(int l, int r, int x = 0) {
    for (int i = l; i <= r; i++) {
        int y = x | i;
        if (vis[y]) continue;
        vis[y] = true;
        dfs(i, r, y);
    }
}

void subset() {
    int l, r;
    scanf("%d%d", &l, &r);
    dfs(l, r);
    int ans = 0;
    for (int i = 1; i < maxn; i++) {
        if (vis[i]) ans++;
    }
    // return ans;
    printf("%d", ans);
}

int main(int argc, const char **args) {
    fo(subset)
    // LOCALfo
    // int l, r;
    // sscanf(args[1], "%d", &l);
    // sscanf(args[2], "%d", &r);
    subset();
    return 0;
}