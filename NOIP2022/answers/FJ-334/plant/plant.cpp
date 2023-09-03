#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 998244353;
int T, id, n, m, c, f, h[1005][1005], l[1005][1005];
ll dph[1005][1005], dpl[1005][1005], ansc, ansf;
bool a[1005][1005];

int main() {
    freopen("plant.in", "r", stdin);
    freopen("plant.out", "w", stdout);
    
    scanf("%d %d", &T, &id);
    
    while (T--) {
        memset(h, 0, sizeof(h));
        memset(l, 0, sizeof(l));
        memset(dph, 0, sizeof(dph));
        memset(dpl, 0, sizeof(dpl));
        ansc = ansf = 0;
        scanf("%d %d %d %d", &n, &m, &c, &f);
        
        for (int i = 1; i <= n; ++i) {
            scanf("\r\n");
            
            for (int j = 1; j <= m; ++j)
                a[i][j] = getchar() - '0';
        }
        
        for (int i = n; i > 0; --i)
            for (int j = m; j > 0; --j)
                if (!a[i][j]) {
                    h[i][j] = h[i][j + 1] + 1;
                    l[i][j] = l[i + 1][j] + 1;
                }
        
        for (int i = n - 2; i > 0; --i)
            for (int j = m - 1; j > 0; --j)
                if (!a[i][j] && l[i][j] >= 3) {
                    dph[i][j] = (dph[i + 1][j] + h[i + 2][j] - 1) % mod;
                    dpl[i][j] = (dpl[i + 1][j] + ll(h[i + 2][j] - 1) * (l[i + 2][j] - 1) % mod) % mod;
                }
        
        for (int i = 1; i < n - 1; ++i)
            for (int j = 1; j < m; ++j)
                if (!a[i][j]) {
                    ansc = (ansc + (h[i][j] - 1) * dph[i][j] % mod) % mod;
                    ansf = (ansf + (h[i][j] - 1) * dpl[i][j] % mod) % mod;
                }
        
        printf("%lld %lld\n", (c * ansc % mod + mod) % mod, ((f * ansf % mod + mod) % mod));
    }
    
    return 0;
}
