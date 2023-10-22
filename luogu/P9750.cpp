#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::ostream;
using std::string;

int gcd(int x, int y) {
    if (x < y) return gcd(y, x);
    if (y == 0) return x;
    return gcd(y, x % y);
}

struct QNumber {
    int p, q, f;
    QNumber() {
        p = 0;
        q = f = 1;
    }

    void check() {
        int d = gcd(p, q);
        if (p < 0) p = -p, f = -f;
        if (q < 0) q = -q, f = -f;
        if (d > 1) {
            p /= d;
            q /= d;
        }
    }

    QNumber operator+(int x) const {
        QNumber y = *this;
        y.p += x * f * q;
        y.check();
        return y;
    }

    QNumber operator+=(int x) {
        return *this = *this + x;
    }

    QNumber operator*=(int x) {
        p *= x;
        check();
        return *this;
    }

    QNumber operator/=(int x) {
        q *= x;
        check();
        return *this;
    }

    string get_print() {
        if (p == 0) return "0";
        string s;
        if (f < 0) 
    }
};

ostream &operator<<(ostream o, const QNumber &x) {

}

void solve(int a, int b, int c) {
    if (a < 0) solve(-a, -b, -c);
    
}

void P9750() {
    int n, m;
    cin >> n >> m;
    while (n--) {
        int a, b, c;
        cin >> a >> b >>c;
        solve(a, b, c);
    }
}

int main() {
    P9750();
    return 0;
}