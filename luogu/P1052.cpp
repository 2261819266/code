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
    }
}

int main() {
    P1052();
    return 0;
}
