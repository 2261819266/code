#include <bits/stdc++.h>
using namespace std;
const int N = 2.5e5 + 5;
typedef unsigned long long ull;
int n, T, Log[N];
ull a[N], b[N], st[2][N][19];
int l, r, q;
ull read() {
	ull num = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') {
		num = num * 10 + ch - 48;
		ch = getchar();
	}
	return num;
}
ull getmx(int x, int l, int r) {
	int k = Log[r - l + 1];
	return max(st[x][l][k], st[x][r - (1 << k) + 1][k]);
}
int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%d%d", &T, &n); Log[0] = -1;
	for(int i = 1; i <= n; i ++) {
		a[i] = read(); Log[i] = Log[i >> 1] + 1;
		st[0][i][0] = a[i];
	}
	for(int i = 1; i <= n; i ++) {
		b[i] = read();
		st[1][i][0] = b[i];
	}
	for(int x = 0; x < 2; x ++)
		for(int j = 1; j <= 18; j ++)
			for(int i = 1; i + (1 << j) - 1 <= n; i ++)
				st[x][i][j] = max(st[x][i][j - 1], st[x][i + (1 << j - 1)][j - 1]);
	scanf("%d", &q);
	while(q --) {
		ull ans = 0;
		scanf("%d%d", &l, &r);
		for(int i = l; i <= r; i ++)
			for(int j = i; j <= r; j ++)
				ans += getmx(0, i, j) * getmx(1, i, j);
		cout << ans << '\n';
	}
	return 0;
}
