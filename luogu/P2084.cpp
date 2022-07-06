#include <cstdio>
#include <cstring>

int m;
char a[1005];

int main() {
	scanf("%d%s", &m, a);
	int n = strlen(a);
	for (int c = 0; c < n; c++) {
		if (a[c] - 48) {
			c == 0 ? 0 : printf("+");
			printf("%d*%d^%d", a[c] - 48, m, n - c - 1);
		}
	}
}
