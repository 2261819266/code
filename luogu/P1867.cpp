#include <cstdio>
#include <cmath>
#define m(X) ((X) > 10 ? (X) = 10 : 0)

double bl = 10;

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int n;
	int j = 0;
	scanf("%d", &n);
	for (int c = 0; c < n; c++) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		bl -= x;
		m(bl);
		if (bl <= 0)
			break;
		j += y;
	}
	int ji = 0;
	while (true)
		if (j >= pow(2, ji))
			j -= pow(2, ji++);
		else
			break;
	printf("%d %d\n", ji, j);
}