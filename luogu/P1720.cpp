#include <cstdio>
#include <cmath>

double f(double x) {
	const double S_5 = pow(5, 0.5);
	double a, b, c;
	a = (1 + S_5) / 2;
	b = (1 - S_5) / 2;
	c = pow(a, x) - pow(b, x);
	return c / S_5;
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif

	int x;
	scanf("%d", &x);
	for (int c = 1; c <= x; c++)
		printf("%.0lf ", f(c));
}