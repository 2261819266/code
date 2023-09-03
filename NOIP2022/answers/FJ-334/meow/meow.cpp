#include <bits/stdc++.h>

using namespace std;

int T, n, m, k, p[2000005], now, q[3][2000005], s[3], e[3], ans, cc[2000005][3], cnt[605];
bool flag;

bool cant(int g) {
    if (cnt[g]) {
        for (int j = 0; j < n; ++j)
            if (s[j] <= e[j] && q[j][e[j]] == g)
                return 0;
        
        for (int j = 0; j < n; ++j)
            if (s[j] > e[j])
                return 0;
    } else
        return 0;
    
    return 1;
}

int main() {
    freopen("meow.in", "r", stdin);
    freopen("meow.out", "w", stdout);
    
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d %d %d", &n, &m, &k);
        
        for (int i = 0; i < n; ++i)
            s[i] = 1, e[i] = 0;
        
        for (int i = 1; i <= m; ++i)
            scanf("%d", &p[i]);
        
        for (int i = 1; i < m; ++i) {
            flag = 0;
            
            for (int j = 0; j < n; ++j)
                if (s[j] <= e[j] && q[j][e[j]] == p[i]) {
                    flag = 1;
                    --e[j];
                    cnt[p[i]] = 0;
                    cc[++ans][0] = 1;
                    cc[ans][1] = j + 1;
                    
                    break;
                }
            
            if (!flag)
                for (int j = 0; j < n; ++j)
                    if (s[j] > e[j]) {
                        flag = 1;
                        q[j][++e[j]] = p[i];
                        cc[++ans][0] = 1;
                        cc[ans][1] = j + 1;
                        cnt[p[i]] = 1;
                        
                        for (int k = 0; k < n; ++k)
                            if (j != k && s[k] <= e[k] && q[k][s[k]] == p[i]) {
                                ++s[k];
                                --e[j];
                                cc[++ans][0] = 2;
                                cc[ans][1] = j + 1;
                                cc[ans][2] = k + 1;
                                cnt[p[i]] = 0;
                            }
                        
                        break;
                    }
            
            cnt[p[i]] = 1;
            
            if (!flag)
                for (int j = 0; j < n; ++j) {
                    q[j][++e[j]] = p[i];
                    
                    if (!cant(p[i + 1])) {
                        cc[++ans][0] = 1;
                        cc[ans][1] = j + 1;
                        
                        break;
                    } else
                        --e[j];
                }
        }
        
        for (int j = 0; j < n; ++j)
            if (s[j] <= e[j] && q[j][e[j]] == p[m]) {
                --e[j];
                cnt[p[m]] = 0;
                cc[++ans][0] = 1;
                cc[ans][1] = j + 1;
                
                break;
            }
        
        printf("%d\n", ans);
        
        for (int i = 1; i <= ans; ++i) {
            printf("%d ", cc[i][0]);
            
            if (cc[i][0] == 1)
                printf("%d\n", cc[i][1]);
            else
                printf("%d %d\n", cc[i][1], cc[i][2]);
        }
    }
    
    return 0;
}
