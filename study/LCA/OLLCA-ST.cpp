#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;
using std::swap;

const int maxn = 1e6 + 9, maxl = 22;
int to[maxn << 2], next[maxn << 2], head[maxn], top, a[maxn << 2], d[maxn];

void addEdge(int u, int v) {
	to[top] = v, next[top] = head[u], head[u] = top++;
}

int dfs(int root, int *data = a, int pre = 0, int k = 1) {
	d[root] = k;
	*data = root;
	int *p = data + 1;
	for (int i = head[root]; ~i; i = next[i]) {
		if (to[i] != pre) 
			p += dfs(to[i], p, root, k + 1), p[0] = root, p++;
	}
	return p - data;
}

int lo[maxn << 2] = {0, 0, 1}, dp[maxn << 2][maxl], o[maxn];
void makeLog(int n) {
	for (int i = 3; a[i - 1]; i++) 
		lo[i] = lo[i / 2] + 1;
}

int f(int u, int v) {
    int l = o[u], r = o[v];
    if (l > r) swap(l, r);
    int size = lo[r - l + 1];
    return d[dp[l][size]] < d[dp[r - (1 << size) + 1][size]] ? dp[l][size] : dp[r - (1 << size) + 1][size];
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	LOCALfo
#endif
	int n, m, root;
	memset(head, -1, sizeof(head));
	scanf("%d%d%d", &n, &m, &root);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(u, v) , addEdge(v, u);
	}
	dfs(root);
    makeLog(n);
    for (int i = 0; i <= lo[n] + 2; i++) {
        for (int j = 0; a[j]; j++) {
            if (i == 0) 
                dp[j][i] = a[j];
            else 
                dp[j][i] = d[dp[j][i - 1]] < d[dp[j + (1 << (i - 1))][i - 1]] ?
                dp[j][i - 1] : dp[j + (1 << (i - 1))][i - 1];
            if (!dp[j][i]) dp[j][i] = root;
            // printf("%d ", dp[j][i]);
        }
        // puts("");
    }

	
    for (int i = 0; a[i]; i++) {
        o[a[i]] = i;
    }

	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", f(u, v));
	}
	return 0;
}