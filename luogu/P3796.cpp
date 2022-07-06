#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

const int maxn = 2e4 + 8;
const int maxlen = 1e6 + 8;

struct ACAutomata {
#define word (str[i] - 'a')
    int a[maxn][26], v[maxn], fail[maxn], cnt;
    char *to[maxn] = {};
    void init() {
        memset(a, 0, sizeof(a));
        memset(v, 0, sizeof(v));
        memset(fail, 0, sizeof(fail));
        memset(to, 0, sizeof(to));
        cnt = 0;
    }

    void insert(char *str) {
        int len = strlen(str);
        int now = 0;
        for (int i = 0; i < len; i++) {
            if (!a[now][word]) 
                a[now][word] = ++cnt;
            now = a[now][word];
        }
        to[now] = str;
    }

    void build() {
        std::queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (a[0][i]) q.push(a[0][i]);
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (a[u][i])
                    fail[a[u][i]] = a[fail[u]][i], q.push(a[u][i]);
                else
                    a[u][i] = a[fail[u]][i];
            }
        }
    }

    int query(const char *str) {
        int len = strlen(str);
        int now = 0;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            now = a[now][word];
            for (int j = now; j; j = fail[j]) {
                if (to[j]) v[j]++;
                if (v[j] > v[ans]) ans = j;
            }
        }
        return ans;
    }
}AC;

char s[151][71], t[maxlen];

bool solve(ACAutomata &x) {
    int n;
    scanf("%d", &n);
    x.init();
    if (!n) return false;
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        x.insert(s[i]);
    }
    x.build();
    scanf("%s", t);
    int ans = x.query(t);
    printf("%d\n", x.v[ans]);
    for (int i = 1; i < maxn; i++) {
        if (x.v[i] == x.v[ans]) {
            printf("%s\n", x.to[i]);
        } 
    }
    return ans;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    while (solve(AC));
    return 0;
}
