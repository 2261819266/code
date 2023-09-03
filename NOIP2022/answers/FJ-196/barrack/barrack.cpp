#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;
const int N = 500005;
//int T, n, m, head[N], top, low[N], dfn[N], co, s[N], ts, fa[N], edg, ed[N], j[N];
long long p = 1e9 + 7, n, m, ans, b[500005];

struct node {
	int from, to, next;
} e[N * 5];

queue <node> q;

inline long long read() {
	long long n = 0; char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') { n = n * 10 + c - 48, c = getchar();}
	return n;
}

/*inline void tar (int x) {
	low[x] = dfn[x] = ++co;
	s[++ts] = x;
	for (int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if (!dfn[v]) {
			tar(v);
			if (low[x] > low[v])
			  low[x] = low[v];
		}
		else if (dfn[x] > low[v]);
		  low[x] = low[v];
	}
	if (dfn[x] == low[x]) {
		j[x] = ts;
		while (s[ts]) {
			int y = s[ts--];
			fa[y] = x;
		}
		ed[x] = edg;
		edg = 0;
	}
}
*/
int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	/*T = read();
	while (T--) {
		n = read(), m = read();
		for (int i = 1; i <= m; i++) {
			int u = read(), v = read();
			e[++top].to = v, e[top].from = u, e[top].next = head[u], head[u] = top;
			e[++top].to = u, e[top].from = v, e[top].next = head[v], head[v] = top;
		}
		tar(1);
		for (int i = 1; i <= n; i++)
		  cout << low[i] << ' ' << co;
	}*/
	n = read(), m = read();
	ans = n * (1 << (n - 1));
	b[0] = 1;
	for (int i = 1; i <= n; i++)
	  b[i] = b[i - 1] * 2 % p;
	for (int i = 2; i <= n; i++)
	  	ans = (ans + (n - i + 1) * (b[i - 2] * b[n - i] % p)) % p;
	cout << ans;
}
