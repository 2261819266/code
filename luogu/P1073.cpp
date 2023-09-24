#include <iostream>
#include <vector>

using std::cin;
using std::vector;

const int maxn = 1e5 + 8;

vector<int> e[maxn], a;


void P1073() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }
    for (int i = 0; i < m; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        e[u].push_back(v);
        if (k == 2) e[v].push_back(u);
    }

    
}

int main() {
    P1073();
    return 0;
}

