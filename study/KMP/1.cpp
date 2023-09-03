#include <cstdio>
#include <cstring>

const int maxn = 1e6 + 8;
char a[maxn], t[maxn];
int next[maxn];

void getNext() {
	int l = strlen(t), now = 0;
	next[0] = 0;
	for (int i = 1; i < l; i++) {
		if (t[i] == t[now]) {
			now++;
			next[i] = now;
		} else if (now) {
			now = next[now - 1];
			i--;
		} else {
			next[i] = now;
		}
	}
}

void kmp() {
	int l = strlen(a), lt = strlen(t);
	for (int i = 0, j = 0; i < l;) {
		if (a[i] == t[j]) i++, j++;
		if (j == lt) printf("%d\n", i - j + 1);
		if (j == 0) i++;
		if (a[i] != t[j]) j = next[j - 1];
	}
}

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	scanf("%s%s", a, t);
	getNext();
	kmp();
	int lt = strlen(t);
	for (int i = 0; i < lt; i++) {
		printf("%d ", next[i]);
	}
}
