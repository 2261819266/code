#include <algorithm>
#include <cstdio>
#include <cstring>
#define ll long long
#define f(x, y, z) for (int x = y, __ = z; x < z; ++x)

const int maxn = 1e3 + 8, B = 1e9 + 7;

char s[maxn];
int next[maxn];
ll num[maxn];
int n;

void kmp() {
    next[0] = 0; int now = 0;
    for (int i = 1, j = 0; i < strlen(s); i++) {
		while (j && s[i] != s[j]) {
			j = next[j - 1];
		}
		if (s[i] == s[j]) {
			next[i] = ++j;
		}
	}
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif  
    scanf("%d", &n); 
    for (int i = 0; i < n; i++) {
        ll ans = 1;
        scanf("%s", s);
        kmp();
        f(i, 1, (int) strlen(s)) {
            int j = 0;
            while (j && s[j + 1] != s[i]) j = next[j] - 1;
            if (s[i] == s[j + 1]) j++;
            while (j * 2 > i) j = next[j] - 1;
            ans *= num[i] + 1;
            ans %= B;
        }
        printf("%lld\n", ans);
    }
}