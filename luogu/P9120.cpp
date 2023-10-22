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
vector<vector<int>> a;
int T, k;
int n;

bool check(int x) {
    vector<vector<int>> b(k, vector<int>(2, 0));
    for (int j = 0; j < n; j++) {
        if (j == 0) {
            for (int i = 0; i < k; i++) {
                b[i][0] = b[i][1] = a[i][j];
            }
        } else {
            for (int y = 0; y < k; y++) {
                bool ans = true;
                for (int i = 0; i < k; i++) {
                    int z = (y + i) % k;
                    if ()
                }
            }
        }
    }
}

void P9120() {
    cin >> T >> k;
    while (T--) {
        cin >> n;
        a.assign(k, vector<int>(n, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

    }
}

int main() {
    P9120();
    return 0;
}
