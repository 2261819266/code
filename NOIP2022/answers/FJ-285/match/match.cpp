#include <bits/stdc++.h>
using namespace std;
const int M = 250100;
bool ST; 
typedef long long ll;
typedef unsigned long long ull;
int T, n, q;
ull a[M], b[M], mxa[M][20], mxb[M][20];
bool ED;
inline ull gma(int l, int r) {
	int f = __lg(r - l + 1);
	return max(mxa[l][f], mxa[r - (1 << f) + 1][f]);
} 
inline ull gmb(int l, int r) {
	int f = __lg(r - l + 1);
	return max(mxb[l][f], mxb[r - (1 << f) + 1][f]);
}
int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%d%d", &T, &n);
	for (int i = 1; i <= n; i++) scanf("%llu", a + i), mxa[i][0] = a[i];
	for (int i = 1; i <= n; i++) scanf("%llu", b + i), mxb[i][0] = b[i];
	for (int j = 1; j < 20; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++) 
			mxa[i][j] = max(mxa[i][j - 1], mxa[i + (1 << j - 1)][j - 1]),
			mxb[i][j] = max(mxb[i][j - 1], mxb[i + (1 << j - 1)][j - 1]);
	scanf("%d", &q);
	while (q--) {
		int l, r;
		ull ans = 0;
		scanf("%d%d", &l, &r);
		for (int i = l; i <= r; i++)
			for (int j = i; j <= r; j++) ans += gma(i, j) * gmb(i, j);
		printf("%llu\n", ans);
	}
	return 0;
}
