#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define U(i,b,e) for(int i(b),END##i(e);i<=END##i;++i)
#define D(i,e,b) for(int i(e),END##i(b);i>=END##i;--i)
const ll P = 998244353;
const int N = 1005;

int n, m, c, f;
char a[N][N];

int r[N]; // len to the right
void solve() {
	U (i, 1, n) r[i] = m + !a[i][m];
	ll aC = 0, aF = 0;
	D (j, m - 1, 1) {
		ll sum = 0, su[N];
		su[n + 1] = 0;
		D (i, n, 1)
			if (a[i][j]) su[i] = 0;
			else su[i] = su[i + 1] + 1;
		U (i, 3, n) {
			(sum += r[i - 2] - j - 1) %= P;
			if (a[i][j] || a[i - 1][j] || a[i - 2][j]) sum = 0;
//			clog << "LD" << i << ' ' << j << ' ' << sum << ' ' << (r[i] - j - 1) << endl;
			(aC += sum * (r[i] - j - 1)) %= P;
			(aF += sum * (r[i] - j - 1) % P * su[i + 1]) %= P;
		}
		U (i, 1, n) if (a[i][j])
			r[i] = j;
	}
	printf("%lld %lld\n", aC * c, aF * f);
}

int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	
	int T, id; scanf("%d%d", &T, &id);
	while (T--) {
		scanf("%d%d%d%d", &n, &m, &c, &f);
		U (i, 1, n) scanf("%s", a[i] + 1);
		U (i, 1, n) U (j, 1, m) a[i][j] -= '0';
		solve();
	}
	return 0;
}