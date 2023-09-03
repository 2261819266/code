#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const int M = 1e6 + 5;

const long long MOD = 1e9 + 7;

int head[N], nxt[M], to[M], tot;
void addedge(int u, int v) {
	++tot;
	nxt[tot] = head[u];
	to[tot] = v;
	head[u] = tot;
}

pair<int, int> edge[M];

int n, m;
int u, v;

int fa[N];
int gfind(int u) {
	return fa[u] == u ? u : fa[u] = gfind(fa[u]);
}

bool check(int pst, int est) {
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		if (est & (1 << (i - 1))) {
			int fu = gfind(edge[i].first), fv = gfind(edge[i].second);
			if (fu != fv) {
				fa[fu] = fv;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (pst & (1 << (i - 1))) {
			for (int j = 1; j <= n; j++) {
				if (pst & (1 << (j - 1))) {
					if (gfind(i) != gfind(j)) {
						return false;
					}
				}
			}
		}
	}
	return true;
}

long long base[N];

int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if (m == n - 1) {
		if (n == 1) {
			puts("1");
			return 0;
		}
		base[0] = 1LL;
		for (int i = 1; i <= n; i++) {
			base[i] = (base[i - 1] << 1) % MOD;
		}
		long long ans = 1LL * n * base[n - 1] % MOD;
		for (int i = 1; i < n; i++) {
			ans = (ans + 1LL * i * (n - i) % MOD * base[n - i - 1] % MOD);
		}
		printf("%lld\n", ans);
	} else {
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &u, &v);
			addedge(u, v);
			addedge(v, u);
			edge[i] = make_pair(u, v);
		}
		long long ans = 0LL;
		for (int pst = 1; pst < (1 << n); pst++) {
			for (int est = 0; est < (1 << m); est++) {
				if (check(pst, est)) {
					ans = (ans + 1LL) % MOD;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
