#include <cstdio>
#include <cstring>
#include <vector>

const int maxn = 1e6 + 8;
char s[maxn], t[maxn];
int a[maxn], ns, nt;
std::vector<std::vector<int>> vl;


void P3375() {
	scanf("%s%s", s, t);
	ns = strlen(s);
	nt = strlen(t);
	int now = 0;
	for (int i = 1; i < nt; ) {
		if (t[i] == t[now]) {
			now++;
			a[i++] = now;
		} else if (now) {
			now = a[now - 1];
		} else {
			a[i++] = 0;
		}
	}
	for (int i = 0, j = 0; i < ns; ) {
		if (s[i] == t[j]) i++, j++;
		if (j == nt) printf("%d\n", i - j + 1);
		if (j == 0) i++;
		if (s[i] != t[j]) j = a[j - 1];
	}
	for (int i = 0; i < nt; i++) {
		printf("%d ", a[i]);
	}
}

int main() {
	P3375();
}