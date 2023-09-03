#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int read() {
	int res = 0, w = 1; char chr = getchar();
	while(chr < '0' | chr > '9') { if(chr == '-') w = -1; chr = getchar(); }
	while(chr >= '0' & chr <= '9') res = res * 10 + chr - 48, chr = getchar();
	return res * w;
}
int n, m;
bool vis[3010];
int head[5010], to[5010], nxt[5010], cnt;
void add(int u, int v) {
	to[++ cnt] = v, nxt[cnt] = head[u], head[u] = cnt;
}
const int mod = 1e9 + 7;
long long ans = 0;
int quick_pow(int x, int k) {
	int res = 1;
	while(k) {
		if(k & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		k >>= 1;
	}
	return res;
}
void dfs(int x, int cnt) {//还剩下cnt条边 
	if(vis[x])
		for(int i = head[x]; i; i = nxt[i])
			if(vis[to[i]] & to[i] < x) cnt --;
//	cout << x << ' ' << cnt << endl; 
	if(cnt == 0) {
		ans = (ans + quick_pow(2, n - x)) % mod;
//		for(int i = 1; i <= n; i ++) cout << vis[i] << ' ';
//		cout << x << ' ' << cnt << ' ' << ans << endl;
		return;
	} else if(x == n) {
		ans = (ans + quick_pow(2, cnt)) % mod;
//		for(int i = 1; i <= n; i ++) cout << vis[i] << ' ';
//		cout << x << ' ' << cnt << ' ' << ans << endl;
		return;
	}
	dfs(x + 1, cnt);//不建第x + 1个
	vis[x + 1] = 1;//建第x + 1个 
	dfs(x + 1, cnt);
	vis[x + 1] = 0;
	return;
}
int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	n = read(), m = read();
//	ans = ans + 1ll * n * quick_pow(2, m) % mod;
//	ans = ans - quick_pow(2, m);
	for(int i = 1; i <= m; i ++) {
		int u = read(), v = read();
		add(u, v), add(v, u);
	}
	for(int i = 1; i <= n; i ++) {
		memset(vis, 0, sizeof vis);
		vis[i] = 1;
		cout << i << '\n';
		dfs(i, m);//在i处建 
	}
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4 1 2 2 3 3 1 1 4
*/
