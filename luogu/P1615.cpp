#include <cstdio>

struct time {
	int hour, minute, second;

	void input() { scanf("%d:%d:%d\n", &hour, &minute, &second); }

	operator int() { return hour * 3600 + minute * 60 + second; }

	int operator-(time x) { return (int)*this - (int)x; }
} a, b;

long long n;

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int h, m, s;
	a.input();
	b.input();
	scanf("%d", &n);
	printf("%lld", n * (long long)(b - a));
}