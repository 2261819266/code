#include <cstdio>
#define abs(X) ((X) < 0 ? -(X) : (X))

const double accuracy = 0.2, range = 0.001;
double data[3], a, b, c, d;
int top;

inline double f(double x) { return a * x * x * x + b * x * x + c * x + d; }

void addx(double x) { data[top++] = x; }

void find(double x) {
	for (double c = x; c <= x + accuracy; c += range) {
		double x = abs(f(c - range)), y = abs(f(c)), z = abs(f(c + range));
		if (y < x && y < z)
			addx(c);
	}
}

void find(double first, double last) {
	double lon = last - first;
	if (lon < accuracy) {
		find(first);
		return;
	}
	double middle = (first + last) / 2;
	double x = f(first), y = f(middle), z = f(last);
	if (x * y < 0 || lon > 1)
		find(first, middle);
	if (y * z < 0 || lon > 1)
		find(middle, last);
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	find(-100, 100);
	for (int c = 0; c < 3; c++)
		printf("%.2lf ", data[c]);
}