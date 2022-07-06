#include <cstdio>

char a[2][3] = {"pb", "zs"};

int main() {
	int n, x;
	scanf("%d", &n);
	for (int c = 0; c < n; c++)
		scanf("%d", &x), printf("%s wins\n", a[x % 2]);
}
