#include <cstdio>
#include <cstring>
#include <algorithm>

int n;
char a[1000], b[1000];
char u[10][1000], v[10][1000];

int solve(int d, char *s) {
    if (d > 10) return -1;
    if (strcmp(s, b) == 0) return d;
    char x[1000];
    int ans = 11;
    for (int i = 0; i < strlen(s); i++) {
        for (int j = 0; j < n; j++) {
            bool y = true;
            for (int k = 0; k < strlen(u[j]); k++) {
                if (s[i + k] != u[j][k]) y = false;
            }
            if (y) {
                int m = strlen(s) + strlen(v[j]) - strlen(u[j]);
                for (int k = 0, o = i + strlen(u[j]); k < m; k++) {
                    if (k < i) x[k] = s[k];
                    else if (k >= i && k < i + strlen(v[j])) x[k] = v[j][k - i];
                    else x[k] = s[o], o++;
                }
                ans = std::min(ans, solve(d + 1, x));
            }
        }
    }
    return ans;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%s%s", a, b);
    while (scanf("%s%s", u[n], v[n]) != -1) n++;
    int ans = solve(0, a);
    if (ans > 10 || ans < 0) printf("NO ANSWER!");
    else printf("%d", ans);
}