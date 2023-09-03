#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define fo(x) freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout);

const int maxn = 5 + 5;

int n;
int a[maxn];
int tt[maxn];
int pos[2][maxn];
bool c[maxn * 2];

int getp(int p) {
	if (pos[0][a[p]] != p) return pos[0][a[p]];
	return pos[1][a[p]];
}

void out() {
	for (int i = 1; i <= 2 * n; ++i)
		putchar(c[i] ? 'R' : 'L');
	putchar('\n');
}

bool check(int l, int r, int x) {
	int tot = 1, tot2 = 2 * n;
	int L = getp(x), R = getp(x);
	bool flg;
	while (l < r && tot2 - tot > 1) {
		flg = false;
		if (l < L) {
			int tmp = getp(l);
			if (tmp == L - 1 || tmp == R + 1) {
				++l;
				if (tmp == L - 1) --L, c[--tot2] = 0;
				else ++R, c[--tot2] = 1;
				c[++tot] = 0;
				flg = true;
			}
		}
		if (flg) continue;
		if (R < r) {
			int tmp = getp(r);
			//printf("Q%d %d\n", tmp, r);
			if (tmp == L - 1 || tmp == R + 1) {
				--r;
				if (tmp == L - 1) --L, c[--tot2] = 0;
				else ++R, c[--tot2] = 1;
				c[++tot] = 1;
				flg = true;
			}
		}
		if (!flg) {
			//printf("l%d r%d\n", l, r);
			//printf("L%d R%d\n", L, R);
			//out();
			return false;
		}
	}
	out();
	return true;
}

void clear() {
	for (int i = 1; i <= n; ++i)
		tt[i] = 0;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; ++i) {
		scanf("%d", &a[i]);
		//printf("Q%d %d\n", tt[a[i]], a[i]);
		pos[tt[a[i]]][a[i]] = i;
		++tt[a[i]];
	}
	if (n == 1) {
		printf("LL\n");
		return;
	}
	c[1] = 0; c[2 * n] = 0;
	if (check(2, 2 * n, 1)) {
		return;
	}
	c[1] = 1; c[2 * n] = 0;
	if (check(1, 2 * n - 1, 2 * n)) {
		return;
	}
	printf("-1\n");
}

int main() {
	fo(palin)
	int T;
	scanf("%d", &T);
	while (T--) solve(), clear();
	return 0;
} 