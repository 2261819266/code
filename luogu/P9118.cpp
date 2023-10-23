#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

#define ll long long 

const int maxn = 1e6;

ll square(ll x) { return x * x; }

void P9118() {
    ll n, k, ans = 0;
    cin >> n >> k;
    if (k == 1) {
        cout << n;
        return;
    }
    if (k <= 2) {
        ll x = sqrt(n);
        while (x * x > n) x--;
        ans += x;
    }
    if (k <= 3) {
        ll x = pow(n, 1.0 / 3);
        while (x * x * x > n) x--;
        ans += x;
    }
    {
        ll x = pow(n, 1.0 / 6);
        while (square(square(x)) * square(x) > n) x--;
        ans -= x; 
    }
    int K = std::max(k, 4ll);
    for (int i = 2; i < maxn; i++) {
        int t = 0, tt = 0;
        int ii = i;
        for (int j = 2; j <= ii; j++) {
            while (ii % j == 0) {
                if (t && t != j) {
                    t = 0;
                    break;
                }
                t = j;
                ii /= j;
                tt++;
            }
        }
        if (t && tt > 1) continue;
        ll x = 1;
        for (int j = 0; j < K; j++) {
            x *= i;
        }
        if (x > n) break;
        for (int j = K; x <= n; x *= i, j++) {
            if ((j % 2 != 0 || k > 2) && (j % 3 != 0 || k > 3)) {
                ans++;
                cout << i << " " << j << " " << x << "\n";
            }
        }
    }
    cout << ans;
}

int main() {
    P9118();
    return 0;
}
