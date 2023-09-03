#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

template <class T>
inline void read(T &x) {
	static char s;
	static bool opt;
	while (s = getchar(), (s < '0' || s > '9') && s != '-');
	x = (opt = s == '-') ? 0 : s - '0';
	while (s = getchar(), s >= '0' && s <= '9') x = x * 10 + s - '0';
	if (opt) x = ~x + 1;
}

typedef unsigned long long u64;

const int N = 250100;

int type, n, Q;

int a[N], b[N];

u64 ans;

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);

	read(type), read(n);

	for (int i = 1; i <= n; i ++) read(a[i]);
	for (int i = 1; i <= n; i ++) read(b[i]);

	read(Q);

	while (Q --) {
		int l, r;
		read(l), read(r);

		ans = 0;

		for (int i = l; i <= r; i ++) {
			int maxA = 0, maxB = 0;
			for (int j = i; j <= r; j ++) {
				maxA = std::max(maxA, a[j]), maxB = std::max(maxB, b[j]);
				ans += 1ull * maxA * maxB;
			}
		}

		std::cout << ans << std::endl;
	}

	return 0;
}
