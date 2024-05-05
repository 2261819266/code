#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::max;

template<typename t>
int LIS(vector<t> a) {
    int n = a.size(), ans = 1;
    vector<int> f(n, 0);
    f[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && f[j] + 1 > f[i]) f[i] = f[j] + 1;
        }
        ans = max(ans, f[i]);
    }
    return ans;
}

int n;
string s;
vector<int> a;
int ans;

void update() {
    vector<string> strs;
    string t;
    for (int i = 0; i <= n; i++) {
        if (a[i]) {
            strs.push_back(t);
            t.clear();
        }
        if (i < n) t.push_back(s[i]);
    }
    int _ans = LIS(strs);
    ans = max(ans, _ans);
    return;
}

void dfs(int i = 1) {
    if (i == n) {
        update();
        return;
    }
    a[i] = 0;
    dfs(i + 1);
    a[i] = 1;
    dfs(i + 1);
}

void solve() {
    cin >> n >> s;
    a.assign(n, 0);
    a.push_back(1);
    dfs();
    cout << ans;
}

int main() {
    solve();
    return 0;
}