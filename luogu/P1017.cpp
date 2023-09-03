#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

int a[100], d[100], ans[100], w = 0;

void init(int B, int x) {
    d[0] = a[0] = 1;
    for (int i = 1; abs(a[i - 3]) < abs(x); i++) {
        d[i] = a[i] = a[i - 1] * B;
    }
    for (int i = 0; d[i]; i++) {
        d[i] += d[i - 2];
    }
}

int to2(const char *a) {
    int ans = 0;
    for (int i = 0; i < strlen(a); i++) {
        int x = a[i] - '0';
        ans *= -10;
        ans += x;
    }
    return ans;
}

void f(int x, int B) {
    if (!x) return;
    int i = x > 0 ? 0 : 1;
    for (; abs(d[i]) * (-1 - B) < abs(x); i += 2) ;
    w =std::max(w, i);
    ans[i]++;
    f(x - a[i], B);
}

int main() {
#ifdef LOCAL
	LOCALfo
#endif
    int x, b;
    scanf("%d%d", &x, &b);
    init(b, x);
    f(x, b);
    printf("%d=", x);
    for (int i = w; i >= 0; i--) {
        printf("%c", ans[i] > 9 ? "ABCDEFGHIJ"[ans[i] - 10] : ans[i] + '0');
    }
    printf("(base%d)", b);
}