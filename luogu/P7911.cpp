#include <cstdio>
#include <cstring>
#define Is1(x) (x >= 0 && x < 256)
#define Is2(x) (x >= 0 && x < 65536)

const int maxn = 1e3 + 2;

struct Server {
	int a, b, c, d, e;
	Server() { a = b = c = d = e = -1; }
	bool operator==(const Server &y) {
		return a == y.a && b == y.b && c == y.c && d == y.d && e == y.e;
	}
} a[maxn];
int cnt;

int cmp(const char *s, bool IsServer) {
	Server x;
	cnt++;
	int t = sscanf(s, "%d.%d.%d.%d:%d", &x.a, &x.b, &x.c, &x.d, &x.e);
	if (t - 5) return -1;
	if (!(Is1(x.a) && Is1(x.b) && Is1(x.c) && Is1(x.d) && Is2(x.e))) return -1;
	char s2[100];
	sprintf(s2, "%d.%d.%d.%d:%d", x.a, x.b, x.c, x.d, x.e);
	if (strcmp(s, s2)) return -1;
	for (int i = 0; i < cnt; i++) {
		if (x == a[i]) return i + 1;
	}
	if (IsServer) a[cnt - 1] = x;
	return 0;
}

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char s[100];
		scanf("%s", s);
		int k = (*s == 'S');
		scanf("%s", s);
		int x = cmp(s, k);
		if (x < 0) printf("ERR\n");
		if (k && x == 0) printf("OK\n");
		if (!k && x == 0) printf("FAIL\n");
		if (k && x > 0) printf("FAIL\n");
		if (!k && x > 0) printf("%d\n", x);
	}
}
