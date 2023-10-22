#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int n, m, s;
vector<vector<int>> e, f;
vector<int> fa, d;
const int maxl = 20;

void add_edge(int u, int v) {
	e[u].push_back(v);
	e[v].push_back(u);
}

void build_tree(int u = s) {
	for (int v : e[u]) {
		if (!fa[v]) fa[v] = u, d[v] = d[u] + 1, build_tree(v);
	}
}

void build_f() {
	for (int i = 0; i < maxl; i++) {
		for (int u = 1; u <= n; u++) {
			if (!i) {
				f[u][i] = fa[u];
			} else {
				f[u][i] = f[f[u][i - 1]][i - 1];
			}
		}
	}
}

int get_LCA(int u, int v) {
	if (d[u] != d[v]) {
		if (d[u] < d[v]) return get_LCA(v, u);
		for (int i = maxl - 1; i >= 0; i--) {
			if (d[f[u][i]] > d[v]) u = f[u][i];
		}
		u = fa[u];
	}
	if (u == v) return u;
	for (int i = maxl - 1; i >= 0; i--) {
		if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
	}
	return fa[u];
}

void P3379() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	e.assign(n + 1, vector<int>());
	fa.assign(n + 1, 0);
	d.assign(n + 1, 0);
	f.assign(n + 1, vector<int>(maxl));
	fa[s] = s;
	d[s] = 1;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		add_edge(u, v);
	}
	build_tree();
	build_f();
	while (m--) {
		int u, v;
		cin >> u >> v;
		cout << get_LCA(u, v) << "\n";
	}
}

int main() {
	P3379();
	return 0;
}
