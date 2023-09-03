#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using std::vector;
using std::string;
using std::queue;
using std::cin;

struct ACAutomaton {
    struct Node {
        vector<int> a;
        int cnt, fail, t;
        string s;
        Node () {
            a.assign(26, 0);
            cnt = fail = t = 0;
        }
        int &operator[](int x) {
            return a[x];
        }
    };

    vector<Node> a;

    ACAutomaton() {
        a.assign(1, {});
    }

    void clear() {
        a.assign(1, {});
    }

    void insert(const string &s) {
        int p = 0;
        for (int i : s) {
            i -= 'a';
            if (!a[p][i]) {
                a[p][i] = a.size();
                a.push_back({});
            }
            p = a[p][i];
        }
        a[p].cnt++;
        a[p].s = s;
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

    void query(const string &s) {
        int p = 0;
        for (int i : s) {
            i -= 'a';
            p = a[p][i];
            for (int j = p; j; j = a[j].fail) {
                a[j].t += a[j].cnt;
            }
        }
    }

    void print() {
        int ans = 0;
        for (Node i : a) {
            if (i.t > ans) ans = i.t;
        }
        printf("%d\n", ans);
        for (Node i : a) {
            if (ans == i.t) puts(i.s.c_str());
        }
    }
} a;

void solve() {
    string s;
    while (true) {
        int n;
        scanf("%d", &n);
        if (!n) return;
        for (int i = 0; i < n; i++) {
            cin >> s;
            a.insert(s);
        }
        cin >> s;
        a.query(s);
        a.print();
        a.clear();
    }
}

int main() {
    solve();
    return 0;
}
