#include <cstdio>
#include<cstring>

const int maxn = 105;
char key[maxn], value[maxn];
char str[maxn];
int a[maxn], b[maxn];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	LOCALfo
#endif
	scanf("%s%s%s", key, value, str);
	for (int i = 0; i < strlen(key); i++) {
		int x, y;
		x = key[i], y = value[i];
		if (a[x] && a[x] != y || b[y] && b[y] != x) {
			printf("Failed\n");
			return 0;
		}
		a[x] = y;
		b[y] = x;
	}
	for(int i = 'A'; i <= 'Z'; i++) {
		if (!a[i]) {
			printf("Failed\n");
			return 0;
		}
	}
	for(int i = 0; i < strlen(str); i++) {
		putchar(a[str[i]]);
	}
	return 0;
}
