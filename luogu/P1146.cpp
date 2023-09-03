#include <cstdio>

const int maxn = 105;
int a[maxn];

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", n);
	for (int c = 1; c <= n; c++) {
		for (int d = 1; d <= n; d++) {
			if (d != c)
				a[d] = !a[d];
			printf("%d", a[d]);
		}
        printf("\n");
	}
}