#include <cstdio>

int main() {
	int h, k;
	scanf("%d%d", &h, &k);
	printf("%d", (k + 1) * (1 << h));
}