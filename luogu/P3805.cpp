#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 1.1e7 + 8;
char a[maxn], b[maxn] = "1";
int ans[maxn] = {1, 1};

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%s", a);
    int n = strlen(a), m = 2 * n + 2;
    memset(b, 48, sizeof(b));
    b[0] = 49;
    b[m] = 50;
    b[m + 1] = 0;
    for (int i = 0; i < n; i++) {
        b[2 * i + 2] = a[i];
    }
    int mid = 1, len = 1;
    for (int i = 1; i < m; i++) {
        int k = std::max(1, ans[std::max(1, mid - (i - mid))]);
        while (b[i - k] == b[i + k]) k++;
        if (k > len) mid = i, len = k;
        ans[i] = k;
        // printf("%c %d\n", b[i], k);
    }
    printf("%d", len - 1);
}