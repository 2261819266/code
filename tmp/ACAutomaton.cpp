#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using std::vector;
using std::string;
using std::queue;
using std::cin;

struct ACAutomaton {
    struct Node {
        vector<int> a;
        int cnt, fail;
        Node() {
            a.assign(26, 0);
            cnt = fail = 0;
        }

        int &operator[](int x) {
            return a[x];
        }
    };

    vector<Node> a;

    ACAutomaton() {
        a.assign(2, {});
    }

    void insert(const string &s) {
        int p = 0;
        for (int i : s) {
            i -= 'a';
            if (!a[p][i]) a[p][i] = a.size(), a.push_back({});
            p = a[p][i];
        }
        a[p].cnt++;
    }

    void build() {
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (a[0][i]) {
                q.push(a[0][i]);
                a[a[0][i]].fail = 0;
            }
        }
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (a[p][i]) {
                    a[a[p][i]].fail = a[a[p].fail][i];
                    q.push(a[p][i]);
                } else {
                    a[p][i] = a[a[p].fail][i];
                }
            }
        }
    }

    int query(const string &s) {
        int ans = 0, p = 0;
        for (int i : s) {
            i -= 'a';
            p = a[p][i];
            for (int j = p; j && ~a[j].cnt; j = a[j].fail) {
                ans += a[j].cnt;
                a[j].cnt = -1;
            }
        }
        return ans;
    }
} a;

void solve() {
    int n;
    string s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> s;
        a.insert(s);
    }
    a.build();
    cin >> s;
    printf("%d", a.query(s));
}

int main() {
    solve();
    return 0;
}