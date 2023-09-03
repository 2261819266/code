#include<bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 + 7;
int n, m, u, v;
long long ans;
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
	freopen ("barrack.in", "r", stdin);
	freopen ("barrack.out" , "w", stdout);
	n = read(), m = read();
	ans = n * m;
	for (int i = 1; i <= m; i++) {
		u = read(), v = read();
		ans *= (u + v);
		ans %= mod;
	}
	printf ("%lld\n", ans % mod);
	return 0;
}

