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

const int M = 3001000;

int n, m, k;

int a[M];

int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);

	read(n), read(m), read(k);

	for (int i = 1; i <= m; i ++) read(a[i]);

	printf("%d\n", m);

	for (int i = 1; i <= m; i ++) printf("%d %d\n", 1, 1);

	return 0;
}
