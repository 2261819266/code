#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll sta[22][250002], stb[22][250002], n, t, q, l, r;
ll fid(int a, int b, bool k) {
	int t = log(b - a + 1) / log(2);
	return max((k ? sta : stb)[t][a], (k ? sta : stb)[t][b - (1 << t) + 1]);
}
int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d", &t, &n);
	t ++;
	while (t -- ) {
		for (int i = 1; i <= n; i ++ ) scanf("%d", &sta[0][i]);
		for (int i = 1; i <= n; i ++ ) scanf("%d", &stb[0][i]);
		for (int i = 1; (1 << i - 1) <= n; i ++ ) for (int j = 1; j <= n; j ++ ) 
		sta[i][j] = max(sta[i - 1][j], sta[i - 1][j + (1 << i - 1)]), stb[i][j] = max(stb[i - 1][j], stb[i - 1][j + (1 << i - 1)]);
		scanf("%d", &q);
		while (q -- ) {
			cin >> l >> r;
			ll ans = 0;
			for (int i = l; i <= r; i ++ ) for (int j = i; j <= r; j ++ ) ans += fid(i, j, 1) * fid(i, j, 0);
			printf("%d\n", ans);
		}
	}
	return 0;
}




