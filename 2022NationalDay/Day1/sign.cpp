#include <cmath>
#include <cstdio>


int main() {
	freopen("sign.in", "r", stdin);
	freopen("sign.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int c = 1; c <= n; c++) {
		int x;
		scanf("%d", &x);
		int y = log2(x);
		printf("%d\n", (1 << y) - 1);
	}
}
