#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

vector<int> p;

template<typename GET>
vector<vector<int>> init(vector<int> h, GET get) {
    int n = h.size(), m = 20;
    p.assign(20, 1);
    for (int i = 1; i < m; i++) {
        p[i] = p[i - 1] * 2;
    }
    vector<vector<int>> a(n, vector<int>(m, 0)); // a[i][j] = cmp(From a[i] to a[i + (0 << m)])
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n && i + p[j] <= n; i++) {
            if (j == 0) a[i][j] = h[i];
            else {
                a[i][j] = get(a[i][j - 1], a[i + p[j - 1]][j - 1]);
            }
        }
    }
    return a;
}

void P2880() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    auto get1 = [](int x, int y) { return std::min(x, y); };
    auto get2 = [](int x, int y) { return std::max(x, y); };
    vector<vector<int>> min = init(a, get1);
    vector<vector<int>> max = init(a, get2);
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (u == v) {
            cout << "0\n";
            continue;
        }
        int x, y, k;
        for (k = 19; k >= 0; k--) {
            if (v - u + 1 >= p[k]) break;
        }
        u--, v--;
        x = get1(min[u][k], min[v - p[k] + 1][k]);
        y = get2(max[u][k], max[v - p[k] + 1][k]);
        cout << y - x << "\n";
    }
}

int main() {
    P2880();
    return 0;
}