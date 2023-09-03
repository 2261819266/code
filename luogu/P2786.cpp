#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using std::vector;
using std::string;

struct Trie {
    int change(int c) {
        if (c >= '0' && c <= '9') return c - '0';
        if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
        return c - 'a' + 36;
    }

    struct Node {
        vector<int> a;
        int cnt;
        Node() {
            a.assign(62, 0);
            cnt = 0;
        }
        int &operator[](int x) {
            return a[x];
        }
    };

    vector<Node> a;
    static const int root = 0;
    Node none;

    Trie() {
        none = {};
        a.assign(1, none);
    }

    void insert(const string &s, int x) {
        int p = root;
        for (int i : s) {
            i = change(i);
            if (!a[p][i]) a[p][i] = a.size(), a.push_back(none);
            p = a[p][i];
        }
        a[p].cnt += x;
    }

    bool is_letter(char c) {
        return (c >= '0' && c <= '9') ||
            (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z');
    }

    int query(const string &s) {
        int p = root, ans = 0;
        for (int i : s) {                                                                                           
            if (!is_letter(i)) {
                if (~p) ans += a[p].cnt;
                p = root;
                continue;
            }
            if (!~p) continue;
            i = change(i);
            if (!a[p][i]) {
                p = -1;
                continue;
            }
            p = a[p][i];
        }
        if (~p) ans += a[p].cnt;
        return ans;
    }
} a;

void P2786() {
    using std::cin;
    using std::cout;
    int n, M, ans = 0;
    scanf("%d%d", &n, &M);
    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        a.insert(s, x);
    }
    string s;
    getwchar();
    while ((cin >> s)) {
        ans += a.query(s);
        ans %= M;
    }
    printf("%d", ans);
}
 
int main() {
    P2786();
    return 0;
}
