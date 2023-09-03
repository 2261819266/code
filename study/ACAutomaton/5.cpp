#include <cstdio>
#include <string>
#include <queue>
#include <iostream>

const int maxn = 1e6 + 8;
using std::string;

class ACAutomaton {
#define word (i - 'a')
#define pw a[p][word]
    static const int root = 0;
public:
    int a[maxn][26], b[maxn], f[maxn], cnt = root;
    void insert(const string &s) {
        int p = root;
        for (int i : s) {
            if (!pw) pw = ++cnt;
            p = pw;
        }
        b[p]++;
    }

    void build() {
        std::queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (a[root][i]) {
                f[a[root][i]] = root;
                q.push(a[root][i]);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (a[u][i]) {
                    f[a[u][i]] = a[f[u]][i];
                    q.push(a[u][i]);
                } else a[u][i] = a[f[u]][i];
            }
        }
    }

    int query(const string &s) {
        int ans = 0, p = root;
        for (int i : s) {
            p = pw;
            for (int j = p; j - root && ~b[j]; j = f[j]) {
                ans += b[j];
                b[j] = -1;
            }
        }
        return ans;
    }
} a;

int main() {
    int n;
    scanf("%d", &n);
    string s;
    while (n--) {
        std::cin >> s;
        a.insert(s);
    }
    a.build();
    std::cin >> s;
    std::cout << a.query(s) << "\n";
}
