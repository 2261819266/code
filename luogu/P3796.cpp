#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define f(x, y, z) for (int x = y, __ = z; x < __; ++x)

const int maxn = 2e4;
const int maxm = 1e6 + 8;

struct ACAutomata {
#define word (s[i] - 'a')
#define pw a[p][word]
#define pi a[p][i]
    int a[maxn][26], v[maxn], fail[maxn], cnt, t[maxn];
    char *to[maxn];
    void init() {
        memset(a, 0, sizeof(a));
        memset(fail, 0, sizeof(fail));
        memset(v, 0, sizeof(v));
        memset(to, 0, sizeof(to));
        memset(t, 0, sizeof(t));
        cnt = 0;
    }
    void insert(char *s) {
        int p = 0;
        f(i, 0, strlen(s)) {
            if (!pw) pw = ++cnt;
            p = pw;
        }
        to[p] = s;
        v[p]++;
    }

    void build() {
        std::queue<int> q;
        f(i, 0, 26) if (a[0][i]) q.push(a[0][i]);
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            f(i, 0, 26) {
                if (pi) q.push(pi), fail[pi] = a[fail[p]][i];
                else pi = a[fail[p]][i];
            }
        } 
    }

    void query(const char *s) {
        int p = 0, ans = 0;
        f(i, 0, strlen(s)) {
            p = pw;
            for (int j = p; j; j = fail[j]) 
                t[j] += v[j];
        }
        // return ans;
    }
    
	// int query(const char *s) {
    //     int r = 0;
	// 	int p = r, ans = 0;
	// 	f(i, 0, strlen(s)) {
	// 		p = pw;
	// 		for (int j = p; j && ~v[j]; j = fail[j]) {
	// 			ans += v[j];
	// 			v[j] = -1;
	// 		}
	// 	}
	// 	return ans;
	// }
} AC;

char s[maxm];
char t[1510][710];

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n;
    scanf("%d", &n);
    while (n) {
        AC.init();
        f(i, 0, n) {
            scanf("%s", t[i]), AC.insert(t[i]);
        }
        AC.build();
        scanf("%s", s);
        AC.query(s);
        // printf("%d\n", AC.query(s));
        int i = 0;
        f(j, 1, AC.cnt + 1) {
            if (AC.t[i] < AC.t[j]) 
                i = j;
        }
        printf("%d\n", AC.t[i]);
        f(j, 1, AC.cnt + 1) if (AC.t[i] == AC.t[j]) printf("%s\n", AC.to[j]);
        scanf("%d", &n);
    }
}

