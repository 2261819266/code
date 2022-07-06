#include <cstdio>
#include <cstring>

const int maxn = 1e6 + 8;

int next[maxn], n;
char t[maxn];

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d", &n);
    scanf("%s", t);
    int now = 0;
    int l = strlen(t);
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
    printf("%d", n - next[n - 1]);
}