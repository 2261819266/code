#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#define f(x, y, z) for (int x = y, __ = z; x < __; ++x)

const int maxn = 2e5 + 8, maxm = 2e6 + 8;

struct ACAutomata {
#define word (s[i] - 'a')
#define pw a[p][word]
#define pi a[p][i]
    int a[maxn][26], v[maxn], fail[maxn], cnt, t[maxn];
    void insert(const char *s) {
        int p = 0;
        f(i, 0, strlen(s)) {
            if (!pw) pw = ++cnt;
            p = pw;
        }
        v[p]++;
    }

    void build() {
        std::queue<int> q;
        f(i, 0, 26) {
            if (a[0][i]) q.push(a[0][i]);
        }
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            f(i, 0, 26) {
                if (pi) fail[pi] = a[fail[p]][i], q.push(pi);
                else pi = a[fail[p]][i];
            }
        }
    }

    void query(const char *s) {
        int p = 0;
        f(i, 0, strlen(s)) {
            p = pw;
            for (int j = p; j; j = fail[j]) {
                t[j] += v[j] > 0;
                if (!v[fail[p]]) fail[p] = fail[fail[p]];
            }
        }
    }

    void print(const char *s) {
        int p = 0;
        f(i, 0, strlen(s)) {
            p = pw;
        }
        printf("%d\n", t[p]);
    }
} AC;

std::string t[maxn];
char s[maxm];

int main() {
#ifdef LOCAL    
    LOCALfo
#endif
    int n;
    scanf("%d", &n);
    f(i, 0, n) {
        scanf("%s", s);
        t[i] = s;
        AC.insert(s);
    }
    scanf("%s", s);
    AC.build(), AC.query(s);
    
    f(i, 0, n) { 
        AC.print(t[i].c_str());
    }
}
