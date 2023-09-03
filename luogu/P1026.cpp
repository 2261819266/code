#include <cstdio>
#include <string>  
#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::cin;

struct Trie {
#define word (ch - 'a')
#define pw a[p][word]
    struct Node {
        vector<int> c;
        int cnt;
        Node() {
            c.clear();
            c.assign(26, -1);
            cnt = 0;
        }

        int &operator[](int x) {
            return c[x];
        }
    } ;
    static const int root = 0;
    vector<Node> a;
    Trie() {
        a.clear();
        a.push_back({});
    }

    int add() {
        a.push_back({});
        return a.size() - 1;
    }

    void insert(const string &s) {
        int p = root;
        for (char ch : s) {
            if (!~pw) pw = add();
            p = pw;
        }
        a[p].cnt++;
    }   

    bool find(const string &s, int k) {
        int p = root, dis = 0;
        for (char ch : s) {
            if (a[p].cnt) return true;
            if (!~pw || dis == k) return false;
            p = pw;
            dis++;
        }
        return a[p].cnt;
    }
} a;

const int maxn = 208;
int n, k, m;
int ans[maxn][maxn], dp[maxn][maxn];
string s;

void P1026() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        s += x;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        string x;
        cin >> x;
        a.insert(x);
    }
    for (int j = 0; j < s.size(); j++) {
        for (int i = j; i >= 0; i--) {
            ans[i][j] = ans[i + 1][j];
            if (a.find(&*s.begin() + i, j - i + 1))
                ans[i][j]++;
        }
    }
    // for (int i = 0; i < s.size(); i++) {
    //     for (int j = 0; j < s.size(); j++) {
    //         printf("%d ", ans[i][j]);
    //     }
    //     putchar(10);
    // }
    for (int i = 0; i < s.size(); i++) {
        dp[i][1] = ans[0][i];
        for (int j = 2; j <= k; j++) {
            for (int r = j - 2; r < i; r++) {
                dp[i][j] = std::max(dp[i][j], dp[r][j - 1] + ans[r + 1][i]);
            }
        }
        // for (int j = 1; j <= k; j++) {
        //     printf("%d\t", dp[i][j]);
        // }
        // putchar(10);
    }
    printf("%d", dp[s.size() - 1][k]);
}

int main() {
    P1026();
    return 0;
}