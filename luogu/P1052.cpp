#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::vector;
using std::min;
// using std::max;
using std::cout;
using std::endl;


vector<int> stones, a, f;
const int buff = 20;

void P1052() {
    int l, s, t, m;
    cin >> l >> s >> t >> m;
    a.push_back(0);
    stones.push_back(0);
    for (int k = 0; k < m; k++) {
        int x;
        cin >> x;
        stones.push_back(x);
    }
    stones.push_back(l);
    int ls = 0;
    for (int x : stones) {
        if (x == 0) continue;
        int len = min(buff, x - ls - 1);
        for (int i = 0; i < len; i++) {
            a.push_back(0);
        }
        a.push_back(1);
        ls = x;
    }
    int n = a.size();
    a[n - 1] = 0;
    // for (int i = 0; i < t; i++) {
    //     a.push_back(0);
    // }
    f.assign(a.size(), m);
    f[0] = 0;
    for (int i = s; i < f.size(); i++) {
        for (int j = i - s; j >= i - t && j >= 0; j--) {
            f[i] = min(f[i], f[j] + a[i]);
        }
    }
    for (int i = f.size() - 1; i >= a.size() - 1 - t; i--) {
        f[f.size() - 1] = min(f.back(), f[i] + a.back());
    }
    cout << f.back() << endl;
}

int main() {
    P1052();
    return 0;
}
