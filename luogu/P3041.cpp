#include <algorithm>
#include <cstdio>
#include <queue>

const int maxn = 1e3 + 8;
struct ACAutomata {
#define word (s[i] - 'A')
#define pw a[p][word]
#define pi a[p][i]
    int a[maxn][3], v[maxn], fail[maxn], cnt, dp[maxn][maxn], vis[maxn][maxn];
    void insert(const char *s) {
        int p = 0;
        for (int i = 0; s[i]; i++) {
            if (!pw) pw = ++cnt;
            p = pw;
        }
        v[p]++;
    }

    void build() {
        std::queue<int> q;
        for (int i = 0; i < 3; i++) {
            if (a[0][i]) q.push(a[0][i]);
        }
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            for (int i = 0; i < 3; i++) {
                if (pi) fail[pi] = a[fail[p]][i];
                else pi = a[fail[p]][i];
            }
        }
    }

    int proc(int cur,int val){//跳fail指针求值
        while(cur) val+=v[cur],cur=fail[cur];
        return val;
    }

    int query(int n) {
        vis[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= cnt; j++) {
                if (vis[i][j]) continue;
                for (int k = 0; k < 3; k++) {
                    dp[i][a[j][k]] = std::max(dp[i][a[j][k]], proc(a[j][k], dp[i - 1][j]));
                }
                vis[i][j] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i <= cnt; i++) {
            ans = std::max(ans, dp[n][i]);
        }
        return ans;
    }
} AC;

char s[maxn];

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        AC.insert(s);
    }
    AC.build();
    printf("%d", AC.query(m));
}