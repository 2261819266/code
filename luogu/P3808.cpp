#include <iostream>
#include <vector>
#include <string>
#include <queue>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::queue;

struct ACAutomaton {
#define word (s[i] - 'a')
#define pw a[p][word]
    struct Trie {
        int a[26];
        int fail;
        int &operator[](int x) {
            return a[x];
        }

        int operator++(int) {
            return fail += 1;
        }
    };

    vector<Trie> a;
    vector<int> v;
    int cnt = 1;

    void init() {
        a.assign(100000, {});
        v.assign(100000, 0);
    }

    void insert(const string &s) {
        int p = 1;
        for (int i = 0; i < s.size(); i++) {
            if (!pw) pw = ++cnt;
            p = pw;
        }
        a[p]++;
    }

    void build() {
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (a[1][i]) {
                q.push(a[1][i]);
                a[a[1][i]].fail = 1;
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (a[u][i]) {
                    q.push(a[u][i]);
                    a[a[u][i]].fail = a[a[u].fail][i];
                } else {
                    a[a[u][i]].fail = a[a[u].fail][i];
                }
            }
        }
    }

    int query(const string &s) {
        int p = 1, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            p = pw;
            for (int j = p; j >= 1; j = a[j].fail) {
                ans += v[j];
                v[j] = 0;
            }
        }
        return ans;
    }
} a;

void P3808() {
    int n;
    cin >> n;
    a.init();
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        a.insert(s);
    }
    cin >> s;
    cout << a.query(s);
}

int main() {
    P3808();
    return 0;
}