#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
constexpr int maxn = 2.5e5 + 10;
ull mod = 1;
ull ans;
int T, N, Q;
int maxa = -1, maxb = -1;
int a[maxn], b[maxn];
inline int read() {
	int out = 0;
	bool flag = false;
	char cc = getchar();
	while (cc < '0' || cc > '9') {
		if (cc == '-') {
			flag = true;
		}
		cc = getchar();
	}
	while (cc >= '0' && cc <= '9') {
		out = (out << 3) + (out << 1) + (cc ^ 48);
		cc = getchar();
	}
	return flag ? -out : out;
}
int main() {
	freopen ("match.in", "r", stdin);
	freopen ("match.out" , "w", stdout);
	for (int i = 1; i <= 64; i++) {
		mod *= 2;
	}
	T = read(), N = read();
	for (int i = 1; i <= N; i++) {
		a[i] = read();
	}
	for (int i = 1; i <= N; i++) {
		b[i] = read();
	}
	Q = read();
	while (Q--) {
		maxa = -1, maxb = -1;
		int l = read(), r = read();
		for (int i = l; i <= r; i++) {
			for (int j = i; j <= r; j++) {
				for (int k = i; k <= j; k++) {
					maxa = max (maxa, a[k]);
					maxb = max (maxb, b[k]);
				}
			}
			ans += maxa * maxb;
			ans %= mod;
		}
		printf ("%llu\n", ans);
	}
	return 0;
}

