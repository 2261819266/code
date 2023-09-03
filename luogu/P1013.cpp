#include <cstdio>
#include <cstring>

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	int to[128], k, l, d[10][10];
	char a[10][10][10];
	memset(to, -1, sizeof(to));
	int n, m;
	scanf("%d", &n);
	m = n - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%s", a[i][j]);
			if (strlen(a[i][j]) == 2) to[a[i][j][0]] = 1, k = a[i][j][0];
		}
	}
	for (int i = 1; i < n; i++) {
		if (strcmp(a[i][i], a[i][0]) == 0) to[a[i][i][0]] = 0;
	}
	for (int i = 1; i < n; i++) {
		if (a[i][0][0] == k) l = i;
	}
	for (int i = 3, now = l; i < n; i++) {
		to[a[l][now][0]] = to[a[now][0][0]] + 1;
		for (int i = 1; i < n; i++) {
			if (a[l][now][0] == a[i][0][0]) { now = i; break; }
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (strlen(a[i][j]) == 1) {
				d[i][j] = to[a[i][j][0]];
			} else {
				d[i][j] = m + to[a[i][j][1]];
			}
			if (i && j) {
				if (d[0][i] + d[0][j] - d[i][j]) {
					printf("ERROR!\n");
					return 0;
				}
			}
		}
	}
	for (int i = 1; i < n; i++) {
		printf("%c=%d ", a[i][0][0], d[i][0]);
	}
	printf("\n%d\n", m);
}