#include <cstdio>
#include <cstring>
#include <queue>

const int maxn = 1e1 + 8;
const int maxl = 26;

struct ACAutomaton {
#define word (str[i] - 'a')
#define pword 
    static const int root = 0;
    int a[maxn][maxl], v[maxn], fail[maxn], cnt = root;

    void insert(const char *str) {
        int p = root;
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            if (!a[p][word]) {
                a[p][word] = ++cnt;
            }
            p = a[p][word];
        }
        v[p]++;
    }

    void build() {
        std::queue<int> q;
        for (int i = 0; i < maxl; i++) {
            if (a[root][i]) {
                fail[a[root][i]] = root;
                q.push(a[root][i]);
            }
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < maxl; i++) {
                if (a[u][i]) 
                    fail[a[u][i]] = a[fail[u]][i], q.push(a[u][i]);
                else 
                    a[u][i] = a[fail[u]][i];
            }
        }
    }

    int query(const char *str) {
        int ans = 0;
        int now = root;
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            now = a[now][word];
            for (int j = now; j - 1 && ~v[j]; j = fail[j]) {
                ans += v[j], v[j] = -1;
            }
        }
        return ans;
    }
} AC;

char s[maxn];

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        AC.insert(s);
    }
    AC.build();
    scanf("%s", s);
    int ans = AC.query(s);
    printf("%d\n", ans);
    return 0;
}