#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 5e5 + 7, M = 1e6 + 7;
int n, m;
struct edge {
	int u, v, fail;
} e[M << 1];
int h[N], eid = -1;
void ins(int u, int v) {
	++ eid;
	e[eid].u = u;
	e[eid].v = v;
	e[eid].fail = h[u];
	h[u] = eid;
}
int f[27], size[27];
int find(int x)  {
	return x == f[x] ? x : f[x] = find(f[x]);
}
void merge(int u, int v) {
	int fu = find(u), fv = find(v);
	if(fu == fv)	return;
	f[fu] = fv;
	size[fv] += size[fu];
}
long long check(int S) {
	for(int i = 1; i <= n; ++ i) {
		f[i] = i, size[i] = 1;
	}
	for(int i = 0; i < m; ++ i) {
//		cout << i << '\n';
		if((1 << i) & S) {
			merge(e[i << 1].u, e[i << 1].v);
			cout << i << ' ' << e[i << 1].u << ' ' << e[i << 1].v << '\n';
		}
	}
	long long res = 0;
	for(int i = 1; i <= n; ++ i) {
		if(f[i] == i) {
			res += (1 << size[i]) - 1;
		}
	}
	return res;
}
typedef long long ll;
ll ksm(ll x, ll y) {
	ll res = 1;
	if(y <= 0)	return 2;	
	while(y) {
		if(y & 1) {
			res = res * x % mod; 
		}
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}
long long ans;
int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		ins(u, v), ins(v, u);
	}
//	if(m == n - 1) {
//		for(int i = 1; i <= m; ++ i) {
//			ans = (ans + (m - i) * (n - i) % mod * (ksm(2, i - 3) - 1 % mod)) % mod;
//		}
//		printf("%lld\n", ans + );
//		return 0;
//	}
//	ans = 0
//	cout << (1 << m) 	
	for(int i = 0; i < (1 << m); ++ i) {
		int t;
		ans += (t = check(i));
//	z	printf("%d\n", t);
	}
	printf("%lld\n", ans);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
/*\
4 3
1 2
2 3
3 4
*/
/*
4 4
1 2
2 3
3 1
1 4
*/
/*
wssb
*/
