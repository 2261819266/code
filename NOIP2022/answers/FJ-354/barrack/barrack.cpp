#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll Mod = 1e9 + 7;
const int N = 5e5 + 7, M = 2e6 + 7;

struct Edge {
	int u, v;
} e[M];

int n, m;

inline int read() {
	int x = 0;
	char c = getchar();
	
	while (c < '0' || c > '9')
		c = getchar();
	
	while (c >= '0' && c <= '9')
		x = (x << 1) + (x << 3) + (c & 15), c = getchar();
	
	return x;
}

namespace solve1 {
struct DSU {
	int fa[N];
	
	inline void clear() {
		for (int i = 1; i <= n; ++i)
			fa[i] = i;
	}
	
	inline int find(int x) {
		while (x != fa[x])
			x = fa[x] = fa[fa[x]];
		
		return x;
	}
	
	inline void merge(int x, int y) {
		fa[find(x)] = find(y);
	}
} F;

vector<int> choose;

bool link[M];

inline bool check() {
	for (int i = 1; i <= m; ++i)
		if (!link[i]) {
			F.clear();
			
			for (int j = 1; j <= m; ++j)
				if (j != i)
					F.merge(e[j].u, e[j].v);
			
			for (int j = 0; j < choose.size(); ++j)
				for (int k = 0; k < choose.size(); ++k)
					if (F.find(choose[j]) != F.find(choose[k]))
						return false;
		}
	
	return true;
}

ll dfs2(int pos) {
	if (pos > m)
		return !choose.empty() && check();
	else {
		ll res = dfs2(pos + 1);
		link[pos] = true;
		res = (res + dfs2(pos + 1)) % Mod;
		link[pos] = false;
		return res;
	}
}

ll dfs1(int pos) {
	if (pos > n)
		return dfs2(1);
	else {
		ll res = dfs1(pos + 1);
		choose.push_back(pos);
		res = (res + dfs1(pos + 1)) % Mod;
		choose.pop_back();
		return res;
	}
}
}

signed main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	n = read(), m = read();
	
	for (int i = 1; i <= m; ++i)
		e[i].u = read(), e[i].v = read();
	
	printf("%lld", solve1::dfs1(1));
	return 0;
} 
