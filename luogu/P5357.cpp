#include <cstdio>
#include <string>
#include <queue>
#include <iostream>

using std::string;
const int maxn = 2e5 + 8;

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

    void query(const string &s, std::vector<string> ss) {
        int p = root;
        for (int i : s) {
            p = pw;
            for (int j = p; j - root; j = f[j]) {
                if (b[j]) t[j]++;
                if (!b[f[p]]) f[p] = f[f[p]];
            }
        }
        for (string j : ss) {
            p = root;
            for (int i : j) {
                p = pw;
            }
            std::cout << t[p] << std::endl;
        }
    }
} a;

std::vector<string> s;

int main() {
    int n;
    string str;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        std::cin >> str;
        s.push_back(str);
        a.insert(s[i]);
    }
    a.build();
    std::cin >> str;
    a.query(str, s);
}