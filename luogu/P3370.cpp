#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long

const int M = 1e9 + 7;
const int B = 223;
const int maxn = 1e4 + 8;

ll getHash(const char *str) {
    int res = 0;
    for (int i = 0; i < strlen(str); i++) {
        res = (res * B + str[i]) % M;
    }
    return res;
}

char s[maxn];
ll a[maxn];

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        a[i] = getHash(s);
    }
    std::sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += a[i] == a[i - 1] ? 0 : 1;
    }
    printf("%d\n", ans);
    return 0;
}