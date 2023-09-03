#include <cstdio>
#define ll long long

template <class T> inline T max(T a, T b) { return a > b ? a : b; }

const int maxn(1050005);
ll a[maxn];

ll n, m, maxa = 0;
ll f(int x) {
	ll num = 0;
	for (int c = 0; c < n; c++) {
		if (a[c] > x)
			num += a[c] - x;
	}
	return num;
}

int find(int strart, int end, int m) {
	if (end - strart == 1) {
		return strart;
	}
	int middle = (strart + end) / 2;
	ll x = f(strart), y = f(middle), z = f(end);
	if (y == m)
		return middle;
	if (m <= x && m >= y)
		return find(strart, middle, m);
	if (m <= y && m >= z)
		return find(middle, end, m);
	return -1;
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int c = 0; c < n; c++) {
		scanf("%d", &a[c]);
		maxa = max(maxa, a[c]);
	}
	printf("%lld", find(0, maxa, m));
}
