#include <iostream>

#define ll long long 

using std::cin;
using std::cout;

ll solve(int n, ll x) {
    int y = 0;
    const int z = x;
    while (x % 2 == 0) {
        y++;
        x /= 2;
    }
    if (y >= n - 2) return z;
    return x << (n - 2);
}

void P9532() {
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        ll ans = 0;

        cout << solve(n, x) << "\n";
    }
}

int main() {
    P9532();
    return 0;
}
