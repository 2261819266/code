#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
const int MAXN = 3333;
const int MOD = 1e9 + 7;
bool G[MAXN][MAXN];
int n, m;
int a[MAXN], top;
int u[MAXN], v[MAXN], pw[MAXN];
bool vis[MAXN];
bool vis2[MAXN];
int cnt;
void dfs1(int x) {
    vis2[x] = true;
    cnt += vis[x];
    for(int i = 1; i <= n; ++i) if(G[x][i] && !vis2[i]) dfs1(i);   
}
bool Work(int u, int v) {
    G[u][v] = G[v][u] = false;
    for(int i = 1; i <= n; ++i) vis2[i] = false;
    cnt = 0;
    dfs1(a[1]);
    G[u][v] = G[v][u] = true;
    return cnt == top;
}
int ans;
void dfs(int x) {
    if(x > n) {
        int c = 0; 
        for(int i = 1; i <= m; ++i) if(Work(u[i], v[i])) ++c;
        (ans += pw[c]) %= MOD;
        return;   
    }
    a[++top] = x;
    vis[x] = true;
    dfs(x + 1);
    --top;
    vis[x] = false;
    dfs(x + 1);
}
int main() {
    freopen("barrack.in", "r", stdin);
    freopen("barrack.out", "w", stdout);
    scanf("%d%d", &n, &m);
    pw[0] = 1;
    for(int i=1; i<=m; ++i) pw[i] = pw[i - 1] * 2 % MOD;
    for(int i=1; i<=m; ++i) {
        scanf("%d%d", &u[i], &v[i]);
        G[u[i]][v[i]] = G[v[i]][u[i]] = 1;
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;   
}
