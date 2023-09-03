#include <cstdio>
#define forn(i) for (int i = 1; i < 4; i++)
#define p (a + b + c + d + e + f + g + h + i + j == n)
#define forfor forn(a) forn(b) forn(c) forn(d) forn(e) forn(f) forn(g) forn(h) forn(i) forn(j)
#include <cmath>

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	int n;
	scanf("%d", &n);
	int ans = 0;
	forfor pc ? ans++ : 0;
	printf("%d\n", ans);
	forfor pc ? printf("%d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j) : 0;
	return 0;
}