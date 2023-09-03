#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using std::string;
using std::cin;
using std::vector;

const int maxn = 1e5 + 8;
string s;
struct Point {
    using ll = long long;
    ll x, y;
    void read() { scanf("%d%d", &x, &y); }

    Point() { x = y = 0; }

    Point(ll _x, ll _y) { x = _x, y = _y; }

    Point operator+(const Point &b) const { return {x + b.x, y + b.y}; }

    Point operator+=(const Point &b) { return *this = *this + b; }

    Point operator*(ll n) const { return {x * n, y * n}; }

    Point operator*=(ll n) { return *this = *this * n; }

    friend Point operator*(ll n, const Point &b) {
        return b * n;
    }
} a, b;
vector<Point> vs;

template<typename t>
int lower_bound(int l, int r, t cmp) {
    while (l < r - 1) {
        int mid = (l + r - 1) / 2;
        if (cmp(mid)) l = mid + 1;
        else r = mid + 1;
    }
    return l;
}

Point w[128];

void init() {
    w['U'] = {0 ,  1};
    w['D'] = {0 , -1};
    w['R'] = {1 ,  0};
    w['L'] = {-1,  0};
    int i = 0;
    Point x;
    vs.push_back(x);
    for (char c : s) {
        x += w[c];
        vs.push_back(x);
    }
}

void CF1117C() {
    a.read();
    b.read();
    scanf("%*d");
    cin >> s;
    init();
    int x = lower_bound(1, 1e9 + 7, [](int x) -> bool {
        Point v = a + (x / s.size()) * vs.back() + vs[x % s.size()];
        int dis = std::abs(v.x - b.x) + std::abs(v.y - b.y);
        return dis > x;
    });
    if (x > 1e9) printf("-1");
    else printf("%d", x);
}

int main() {
    CF1117C();
    return 0;
}
