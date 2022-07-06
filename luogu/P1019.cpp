#include <cstdio>
#include <cstring>

const int maxn = 21;
int a[maxn][maxn], n, l[maxn];
char s[maxn][100];

int main() {
#ifdef LOCAL
	LOCALfo
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        l[i] = strlen(s[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 1; k < l[i] && k < l[j]; k++) {
                for (int m = 0; m < k; m++) {
                    if (s[i][l[i] - m - 1] != s[j][m]) {
                        a[i][j] = 0;
                        bre
                    }
                }
            }
        }
    }
}