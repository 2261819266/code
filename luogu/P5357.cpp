#include <cstdio>
#include <cstring>
#include <queue>

const int maxn = 2e5 + 8;
const int maxm = 2e6 + 8;

struct ACAutomata {
#define word (str[i] - 'a')
#define anu a[u][i]
    int a[maxn][26], fail[maxn], v[maxn], cnt, time[maxn], st[maxn];
    void insert(const char *str) {
        int len = strlen(str), now = 0;
        for (int i = 0; i < len; i++) {
            if (!a[now][word])
                a[now][word] = ++cnt;
            now = a[now][word];
        }
        v[now]++;
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
                if (anu)
                    fail[anu] = a[fail[u]][i], q.push(anu);
                else
                    anu = a[fail[u]][i];
            }
        }
    }

    void query(const char *str) {
        int len = strlen(str), now = 0;
        for (int i = 0; i < len; i++) {
            now = a[now][word];
            int j;
            for (j = now; j; j = fail[j]) {
                st[fail[j]] = j;
                if (v[j]) time[j]++;
            }
            if (!v[fail[now]]) 
                fail[now] = fail[fail[now]];
        }
    }

    void print(const char *str, int n) {
        for (int i = 0; i < n; i++) {
            int now = 0;
            for (int i = 0; str[i]; i++) {
                now = a[now][word];
            }
            printf("%d\n", time[now]);
            str += strlen(str) + 1;
        }
    }
} AC;

char s[maxm];
char str[maxm], *p = str;

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s), AC.insert(s);
        strcpy(p, s);
        p += strlen(p) + 1;
    }

    AC.build();
    scanf("%s", s);
    AC.query(s);
    AC.print(str, n);
}