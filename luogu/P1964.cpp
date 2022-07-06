#include <cstdio>
#include <cstring>
#define min(X, Y) ((X) < (Y) ? (X) : (Y))
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

const int maxn(105), M(21);
int n, m;

struct node {
	char str[105];
	int a, b, c;
	node *next = NULL, *last = NULL;
	bool operator==(const node &x) const { return strcmp(str, x.str) == 0; }

	bool operator!=(const node &x) { return !(*this == x); }

	bool operator<(const node &x) const { return strcmp(str, x.str) < 0; }

	bool operator>(const node &x) const { return strcmp(str, x.str) > 0; }

	bool operator+(node &x) {
		if (*this != x)
			return false;
		a += x.a;
		if (a > c) {
			x.a = a / 10;
			a %= 10;
			return false;
		} else {
			if (x.last)
				x.last->next = x.next;
			if (x.next)
				x.next->last = x.last;
			return true;
		}
	}
} a[maxn];

int dfs(node *x, int k) {
	int num = x->a * x->b;
	if (k < 1)
		return 0;
	if (!x->next)
		return num;
	return max(dfs(x->next, k - 1) + num, dfs(x->next, k));
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d%d", &m, &n);
	m = M - m;
	for (int c = 1; c <= n; c++) {
		scanf("%d %d %d %s", &a[c].a, &a[c].b, &a[c].c, &a[c].str);
		a[c].next = a[c - 1].next;
		a[c - 1].next = a + c;
		a[c].last = a + c - 1;
		while (a[c].a > a[c].c) {
			int num = a[c].a - a[c].c;
			a[c].a = a[c].c;
			a[c + 1].next = a[c].next;
			a[c].next = a + c + 1;
			n++, c++;
			a[c].a = num;
			a[c].last = a + c - 1;
			a[c].b = a[c - 1].b;
			a[c].c = a[c - 1].c;
			strcpy(a[c].str, a[c - 1].str);
		}
	}
	for (node *c = a + 1; c != NULL; c = c->next) {
		for (node *d = c + 1; d != NULL; d = d->next) {
			c->operator+(*d);
		}
	}
	printf("%d", dfs(a + 1, m));
}