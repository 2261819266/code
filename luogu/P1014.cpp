#include <cstdio>

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int x;
	scanf("%d", &x);
	int y = 0;
	for (int c = 1; y <= x; c++) {
		for (int d = 1; d <= c; d++) {
			y++;
			if (y == x) {
				c % 2 == 1 ? d = c + 1 - d : 0;
				printf("%d/%d", d, c + 1 - d);
				return 0;
			}
		}
	}
}