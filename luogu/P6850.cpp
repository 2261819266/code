#include <cstdio>

int sum(int *a, int *b) {
	int *c = a;
	int s = 0;
	while (c < b)
		s += *c, c++;
	return s;
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif

	int a[6], b, e;
	bool k;
	scanf("%d", &b);
	for (int c = 0; c < 6; c++)
		scanf("%d", a + c);
	scanf("%d%d", &k, &e);
	b += sum(a, a + 6);
	k ? b += 5 : 0;
	printf("%s", b < e ? "AFO\n" : "AKIOI");
}