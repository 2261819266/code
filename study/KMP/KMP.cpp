#include <cstdio>
#include <cstring>

int *getNext(int *next, const char *format, int n) {
	next[0] = 0;
	for (int i = 1, j = 0; i <= n; i++) {
		while (j && format[i] != format[j]) {
			j = next[j - 1];
		}
		if (format[i] == format[j]) {
			next[i] = ++j;
		}
	}
	return next;
}

void print(const int *data, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}
	puts("");
}

int *getAns(int *ans, int &k, const char *data, int n, const char *format, const int *next, int m) {
	k = 0;
	for (int i = 0, j = 0; i < n; i++) {
		while (data[i] != format[j] && j) {
			j = next[j - 1];
		}
		if (data[i] == format[j]) {
			j++;
		}
		if (j == m) {
			ans[k++] = i - m + 1;
			j = next[j - 1];
		}
	}
	return ans;
}

const int maxn = 1e6 + 8;
char a[maxn], b[maxn];
int c[maxn], ans[maxn];

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	scanf("%s%s", a, b);
	int n = strlen(a), m = strlen(b), k;
	getNext(c, b, m);
	getAns(ans, k, a, n, b, c, m);
	for (int i = 0; i < k; i++) {
		printf("%d\n", ans[i] + 1);
	}
	print(c, m);
}