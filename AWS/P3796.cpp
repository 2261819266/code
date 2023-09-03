#include <cstdio>
#include <string>
#include <iostream>
#include <queue>
#include <vector>

const int maxn = 1e5;
using std::string;

class ACAutomaton {
#define word (i - 'a')
#define pw a[p][word]
    static const int root = 0;
public:
    int a[maxn][26] = {}, b[maxn] = {}, f[maxn], cnt = root, t[maxn] = {};
    string str[maxn];
    void insert(const string &s) {
        int p = root;
        for (int i : s) {
            if (!pw) pw = ++cnt;
            p = pw;
        }
        b[p]++;
        str[p] = s;
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

    std::vector<string> query(const string &s) {
        int p = root;
        for (int i : s) {
            p = pw;
            for (int j = p; j - root; j = f[j]) {
                if (b[j]) t[j]++;
            }
        }
        std::vector<string> ans;
        int tt = 0;
        for (int i : t) {
            tt = std::max(i, tt);
        }
        for (int i = 0; i <= cnt; i++) {
            if (t[i] == tt) ans.push_back(str[i]);
        }
        std::cout << tt << "\n";
        return ans;
    }
} ;

int main() {
    while (true) {
        int n;
        scanf("%d", &n);
        if (!n) return 0;
        string s;
        ACAutomaton a;
        while (n--) {
            std::cin >> s;
            a.insert(s);
        }
        a.build();
        std::cin >> s;
        std::vector<string> ans = a.query(s);
        for (string &i : ans) {
            std::cout << i << "\n";
        }
    }
}
