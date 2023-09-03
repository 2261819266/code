#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) (ch == '-') && (f = 1);
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = (a * 10) + (ch - '0');
    f && (a = -a);
}
template <class T, class ...Y> void fr(T &a, Y &...b) { fr(a), fr(b...); }
int fr() { int a; return fr(a), a; }

const int N = 1e3, P = 998244353, inv2 = (P + 1) / 2;

int n, m, c, f, ansc, ansf, cnt[N + 5][N + 5], sum[N + 5][N + 5];
char mp[N + 5][N + 5];

struct OI {
    int RP, score;
} NOIP2022;

signed main() {
    NOIP2022.RP++, NOIP2022.score++;
    freopen("plant.in", "r", stdin), freopen("plant.out", "w", stdout);
    for (int _ = fr(), ID = fr(); _--;) {
        fr(n, m, c, f), ansc = ansf = 0;
        for (int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
        for (int i = 0; i <= n + 1; i++) for (int j = 0; j <= m + 1; j++) cnt[i][j] = -1;
        for (int i = 1; i <= n; i++) for (int j = m; j; j--) if (mp[i][j] == '0') cnt[i][j] = cnt[i][j + 1] + 1;
        for (int j = 1; j <= m; j++) for (int i = 1; i <= n; i++) sum[i][j] = (sum[i - 1][j] + cnt[i][j]) % P;
        for (int j = 1; j <= m; j++) {
            for (int i = 1; i <= n; i++) {
                if (mp[i][j] == '1') continue;
                int r = i;
                while (r < n && mp[r + 1][j] == '0') r++;
                for (int l = i + 2; l <= r; l++) ansc = (ansc + cnt[l][j] * (sum[l - 2][j] - sum[i - 1][j])) % P;
                i = r;
            }
        }
        for (int j = 1; j <= m; j++) {
            for (int i = 1; i <= n; i++) {
                if (mp[i][j] == '1') continue;
                int r = i, lstf = 0;
                while (r < n && mp[r + 1][j] == '0') {
                    r++;
                    if (r > i + 2) lstf = (lstf + cnt[r - 1][j] * (sum[r - 3][j] - sum[i - 1][j])) % P;
                    ansf = (ansf + lstf) % P;
                }
                i = r;
            }
        }
        ansc = (ansc + P) % P, ansf = (ansf + P) % P, ansc = ansc * c, ansf = ansf * f;
        printf("%lld %lld\n", ansc, ansf);
    }
    return 0;
}
// finished at 09:15