#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

vector<int> a;

void solve() {
    int n, m;
    cin >> n >> m;
    a.assign(n, 0);
    for (int &x : a) {
        cin >> x;
    }
    while (m--) {
        int l, r;
        long long ans = 0;
        cin >> l >> r;
        l--;
        r--;
        for (int i = l; i <= r; i++) {
            for (int j = i; j <= r; j++) {
                ans ^= (a[i] + a[j]);
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    solve();
    return 0;
}