#include <cstdio>
#include <queue>
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

const int maxn = 105;

struct ACAutomaton {
    struct Node {
        vector<int> a;
        bool c;
        int fail;
        Node() {
            a.assign(26, 0);
            c = 0;
            fail = 0;
        }
        int &operator[](int x) {
            return a[x];
        }
        
        bool &operator*() {
            return c;
        }

        bool operator++(int) {
            return c = true;
        }
    };

    Node none;
    vector<Node> a;
    static const int root = 0;

    size_t back() {
        return a.size() - 1;
    }

    ACAutomaton() {
        none = {};
        a.assign(1, none);
    }

    size_t add() {
        a.push_back(none);
        return back();
    }

    void insert(const string &s) {
        int p = root;
        for (int i : s) {
            i -= 'A';
            if (!a[p][i]) a[p][i] = add();
            p = a[p][i];
        }
        a[p]++;
    }

    void build() {
        std::queue<int> q;
        int p = root;
        for (int i = 0; i < 26; i++) {
            if (a[p][i]) {
                a[a[p][i]].fail = p;
                q.push(a[p][i]);
            }
        }
        while (!q.empty()) {
            p = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (a[p][i]) {
                    a[a[p][i]].fail = a[a[p].fail][i];
                    q.push(a[p][i]);
                    a[a[p][i]].c |= a[a[a[p].fail][i]].c;
                } else {
                    a[p][i] = a[a[p].fail][i];
                }
            }
        }
    }

    vector<vector<int>> dp;
    static const int M = 1e4 + 7;

    int query(int m) {
        int ans = 1;
        dp.assign(maxn, vector<int>(a.size(), 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            ans *= 26;
            ans %= M;
            for (int j = 0; j < a.size(); j++) {
                for (int k = 0; k < 26; k++) {
                    if (!a[a[j][k]].c)
                        dp[i + 1][a[j][k]] += dp[i][j];
                }
            }
        }
        for (int i = 0; i < a.size(); i++) {
            ans -= dp[m][i];
            ans += M;
            ans %= M;
        }
        return ans;
    }
} a;

void P4052() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        string s;
        std::cin >> s;
        a.insert(s);
    }
    printf("%d", a.query(m));
}


int main() {
    P4052();
    return 0;
}