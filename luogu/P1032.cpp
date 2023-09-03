#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>
#include <map>

using std::cin;
// using std::cout;
using std::string;

std::map<string, bool> m;

string s, t, a[10], b[10];
int n, min = 1e5, max;

void dfs(string now, int k = 0) {
    string x;
    if (k > max) return; 
    if (now == t) {
        // printf("%d", k);
        min = std::min(min, k);
        return;
    }
    for (int i = 0; i < n; i++) {
        int pos = 0;
        while (pos < now.size() && now.find(a[i], pos) != string::npos) {
            x = now;
            auto y = now.find(a[i], pos);
            pos = y + 1;
            x.replace(y, a[i].size(), b[i]);
            if (m[x]) continue;
            m[x] = true;
            dfs(x, k + 1);
        }
    }
}

void P1032() {
    cin >> s >> t;
    for (int i = 0; cin >> a[i] >> b[i]; i++, n = i) ;
    dfs(s);
    for (max = 1; max <= 10; max++) {
        m.clear();
        dfs(s);
        if (min < 11) {
            printf("%d", min);
            return;
        }
    }
    printf("NO ANSWER!");
    // s.replace(s.begin(), s.begin() + 3, b[0]);
    // cout << s;
}

int main() {
    P1032();
}