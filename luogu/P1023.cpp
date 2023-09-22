#include <algorithm>
#include <iostream>
#include <cstdio>
#include <ostream>
#include <utility>
#include <vector>
#include <cmath>

using std::cin;
using std::vector;
using std::pair;
using std::max;
using std::min;
using std::cout;
using std::endl;

const int minx = -1e5, maxx = 1e5;
struct Block {
    int l, r;
    Block() {
        l = minx;
        r = maxx;
    }

    Block(int x, int y) {
        l = max(minx, x);
        r = min(maxx, y);
    }


    bool operator!() const {
        return l > r;
    }

    operator bool() const {
        return l <= r;
    }

    Block operator+(const Block &b) const {
        if (!*this) return b;
        if (!b) return *this;
        return Block(min(l, b.l), max(r, b.r));
    }

    Block operator*(const Block &b) const {
        return Block(max(l, b.l), min(r, b.r));
    }

    Block operator*=(const Block &b) {
        return *this = *this * b;
    }
};

int change(int x, int y) {
    int f = 1;
    if (x < 0) x = -x, f *= -1;
    if (y < 0) y = -y, f *= -1;
    int z = x / y;
    if (z * y != x) z++;
    return z * f;
}

void P1023() {
    int final;
    cin >> final;
    vector<pair<int, int>> lev;
    while (true) {
        int x, y;
        cin >> x >> y;
        if (!~x) break;
        lev.push_back({x, y});
    }
    int t;
    cin >> t;
    int minxx = lev[0].first;
    vector<int> a;
    a.push_back(lev[0].second);
    for (pair<int, int> i : lev) {
        i.first -= minxx;
    }
    int n = lev.size();
    for (int i = 1; i < n; i++) {
        int len = (lev[i].first - lev[i - 1].first);
        int buff = (lev[i - 1].second - lev[i].second) / len;
        int x = lev[i - 1].second;
        while (len--) {
            x -= buff;
            a.push_back(x);
        }
    }
    // for (int i : a) {
    //     cout << i << endl;
    // }
    const int maxn = 1e6 + 8;
    while (a.size() < maxn) {
        a.push_back(std::max(0, a.back() - t));
    }

    final -= minxx;
    if (a[final] <= 0) {
        cout << "NO SOLUTION" << endl;
        return;
    }
    Block ans;
    for (int i = 0; i < maxn - 1 && a[i] >= 0; i++) {
        if (i == final) continue;
        int x = change((a[final] * final - a[i] * i), (a[i] - a[final]));
        Block y;
        if (i < final) y.r =x;
        if (i >= final) y.l = x;
        ans = ans * y;
    }
    // cout << ans.l - final << endl << ans.r - final;
    int l = ans.l, r = ans.r;
    if (l <= 0 && r >= 0) cout << 0 << endl;
    else if (l > r) cout << "NO SOLUTION" << endl;
    else if (l > 0) cout << l << endl;
    else cout << r << endl;
}   

int main() {
    P1023();
    return 0;
}