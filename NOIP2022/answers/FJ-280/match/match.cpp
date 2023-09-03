#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 2.5e5 + 7;
int T, n, Q, a[N], b[N], l[N], r[N], s[N], tp;
namespace Tle5 {

const int N = 3007;
ull d[N][N];
void Solve() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	for(int i = 1; i <= n; ++i) scanf("%d", b + i);
	for(int i = 1; i <= n; ++i)
		for(int j = i; j <= n; ++j) d[i][j] = 1;
	for(int i = 1; i <= n; ++i) {
		while(tp && a[s[tp]] < a[i]) r[s[tp--]] = i - 1;
		l[i] = s[tp] + 1, s[++tp] = i;
	}
	while(tp) r[s[tp--]] = n;
	for(int i = 1; i <= n; ++i)
		for(int j = l[i]; j <= i; ++j)
			for(int k = i; k <= r[i]; ++k) d[j][k] *= a[i];
	for(int i = 1; i <= n; ++i) {
		while(tp && b[s[tp]] < b[i]) r[s[tp--]] = i - 1;
		l[i] = s[tp] + 1, s[++tp] = i;
	}
	while(tp) r[s[tp--]] = n;
	for(int i = 1; i <= n; ++i)
		for(int j = l[i]; j <= i; ++j)
			for(int k = i; k <= r[i]; ++k) d[j][k] *= b[i];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
	scanf("%d", &Q);
	for(int i = 1, p, q; i <= Q; ++i) {
		scanf("%d %d", &p, &q);
		printf("%llu\n", d[q][q] - d[p - 1][q] - d[q][p - 1] + d[p - 1][p - 1]);
	}
}

}
int main() {
	freopen("match.in", "r", stdin), freopen("match.out", "w", stdout);
	scanf("%d", &T);
	if(T <= 5) Tle5::Solve();
	return 0;
}
