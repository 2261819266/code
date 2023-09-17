#include <algorithm>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <vector>

using std::cin;

void P1664() {
    int n;
    cin >> n;
    int d = 0, t = 0, ans = 0;
    while (n--) {
        bool x;
        cin >> x;
        if (x) {
            if (t) {
                d -= (1 << std::min(t - 1, 30));
                t = 0;
            }
            if (d < 0) d = 0;
            d++;
            ans += 1 + (d > 2) + (d > 6) + (d > 29) + (d > 119) + (d > 364);
        } else {
            t++;
        }
    }
    std::cout << ans <<std::endl;
}

int main() {
    P1664();
    return 0;
}
