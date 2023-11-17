#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

typedef long long ll;
vector<ll> a, b, c, d;

ll square(ll x) { return x * x; }

ll ans = 0x7fffffffffffffff;

// void dfs(int u = 1, ll sum = 0) {
    
// }

void P7962() {
    int n;
    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    c.assign(n, 0);
    d.assign(n, 0);
    ll sum = 0, f = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        b[i] = a[i] - a[i - 1];
    }
    std::sort(b.begin(), b.end());
    for (int I = 1; I < n; I++) {
        int i, j;
        // if (n % 2) {
        //     i = n / 2;
        //     j = i + 1;
        // } else {
        //     i = j = n / 2;
        // }
        i = j = I;
        for (auto k = b.begin() + 1; k < b.end();) {
            if (i == j) {
                c[i--] = c[j++] = *k;
                k++;
                continue;
            } else 
            if (i == 0) c[j++] = *k++;
            else if (j == n) c[i--] = *k++;
            else {
                c[i--] = *k++;
                c[j++] = *k++;
            }
        }
        sum = f = 0;
        for (int k = 1; k < n; k++) {
            d[k] = d[k - 1] + c[k];
            sum += d[k];
        }
        for (int k = 0; k < n; k++) {
            f += square(sum - 4 * d[k]);
        }


        if (f < ans) ans = f;
    }    
    
    cout << ans / 4;
}

int main() {
    P7962();
    return 0;
}