#include <cstdio>

struct Data { 
	int a, b; 

	Data operator+(const Data &x) { return (Data) {a + x.a, b + x.b}; }
};
Data a[100];
int fib[100];

int getFib(int x) {
	if (x == 1) return fib[x] = 1;
	if (x == 0 || fib[x]) return fib[x];
	return fib[x] = getFib(x - 1) + getFib(x - 2);
}

void init() {
	a[1] = a[2] = (Data) {1, 0};
	a[3] = a[1] + a[2];
}

Data f(int x) {
	if (a[x].a) return a[x];
	return a[x] = f(x - 1) + (Data) {getFib(x - 4), getFib(x - 3)};
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	init();
	int a, n, m, x, k;
	scanf("%d%d%d%d", &a, &n, &m, &x);
	Data last = f(n - 1), need = f(x);
	k = (m - last.a * a) / last.b;
	printf("%d", a * need.a + k * need.b);
}