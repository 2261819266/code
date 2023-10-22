#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::min;
using std::max;

vector<int> turn(vector<int> a) {
    vector<int> b(a.begin() + 1, a.end());
    b.push_back(a.front());
    return b;
}

const int inf = 0x7fffffff;

void P9120() {
    int T, k;
    cin >> T >> k;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> a(k, vector<int>(n, 0));
        vector<vector<int>> b(k, vector<int>(n, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        if (k == 1) {
            int x = 0, y = inf;
            for (int j : a[0]) {
                x = max(x, j);
                y = min(y, j);
            }
            cout << x - y << "\n";
            continue;
        }
        vector<int> mx(k, 0);
        vector<int> mn(k, inf);
        for (int i = 0; i < k; i++) {
            mx[i] = mn[i] = a[i][0];
        }
        int minC = inf;
        for (int j = 1; j < n; j++) {
            vector<int> z(k);
            for (int l = 0; l < k; l++) {
                z[l] = a[l][j];
            }
            vector<int> nx = mx;
            vector<int> ny = mn;
            int nC = inf, now;
            for (int i = 0; i < k; i++) {
                vector<int> nnx = mx;
                vector<int> nny = mn;
                int C = 0;

                for (int l = 0; l < k; l++) {
                    if (z[l] > nnx[l]) nnx[l] = z[l];
                    if (z[l] < nny[l]) nny[l] = z[l];
                    C = max(C, nnx[l] - nny[l]);
                }
                if (C < nC) {
                    nC = C, now = i;
                    nx = nnx;
                    ny = nny;
                    minC = nC;
                }
                z = turn(z);
            }
            mx = nx;
            mn = ny;
        }
        cout << minC << "\n";
    }
}

int main() {
    P9120();
    return 0;
}
