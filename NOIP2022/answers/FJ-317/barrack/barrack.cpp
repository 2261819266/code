#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 2e6 + 7;
const int mod = 1e9 + 7;

int nxt[N], to[N], head[N], tot = 0, ans = 1, m, n, vis[N];

void add (int x, int y) {
	nxt[++ tot] = head[x];
	to[tot] = y;
	head[x] = tot;
}

void dfs (int x, vector<int> vc, int tot, int res) {
	if (tot == (int)vc.size ()) {
		bool fg = true;
		for (int i = 0; i < (int)vc.size (); i ++) {
			if (vis[vc[i]] == 0) {
				fg = false;
				break;
			}
		}
		if (fg == true) {
			ans += (1 << (m - res));
		}
		return ;
	}
	for (int i = head[x]; i; i = nxt[i]) {
		int v = to[i];
		if (vis[v]) {
			continue;
		}
		vis[v] = 1;
		dfs (v, vc, tot + 1, res + 1);
		vis[v] = 0;
	}
	return ;
}

void dfss (int x, vector<int> v, int tar) {
	if (x == n + 1) {
		if (v.size () == tar) {
			memset (vis, 0, sizeof (vis));
			vis[v[0]] = 1;
			dfs (v[0], v, 1, 0);
		}
		v.clear ();
		return ;
	}
	dfss (x + 1, v, tar);
	v.push_back (x);
	dfss (x + 1, v, tar);
}

int main () {
	freopen ("barrack.in", "r", stdin);
	freopen ("barrack.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	bool f = true;
	if (m != n - 1) {
		f = false;
	}
	for (int i = 1, u, v; i <= m; i ++) {
		scanf ("%d%d", &u, &v);
		add (u, v);
		add (v, u);
		if (v != u + 1 || v + 1 != u) {
			f = false;
		}
	}
	if (f == true) {
		int s = 1;
		for (int i = 1; i <= n; i ++) {
			s = (s * 2) % mod;
		}
		int jc = 1;
		for (int i = 1; i <= n; i ++) {
			jc *= i;
			jc %= mod;
		}
		s -= jc;
		s += n * 2 - 1;
		cout << s;
		return 0;
	}
//	vector<int> v;
//	v.push_back (1);
//	 v.push_back (2);v.push_back (3);
//	 vis[1] = 1;
//	 dfs (1, v, 1, 0);
//	 cout << ans;
	for (int i = 1; i <= m + 1; i ++) {
		ans = (ans * 2) % mod;
	}
	ans = (ans * n) % mod;
	for (int i = 2; i <= n; i ++) {
		vector<int> v;
		dfss (1, v, i);
		v.clear ();
	}
	cout << ans;
}
