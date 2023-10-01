#include <iostream>
#include <vector>

using std::cin;
using std::vector;

const long long M = 1e9 + 7;

void sea() {
    int n;
    cin >> n;
    vector<int> a;
    long long ans = 1, cut = 1;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(y - x + 1);
        ans *= a.back();
        cut *= (a.back() - 1);
        ans %= M;
        cut %= M;
    }
    ans -= cut - M;
    ans %= M;
    std::cout << ans;
}

#define fo(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);

int main() {
    fo(sea)
    std::ios::sync_with_stdio(true);
    cin.tie(0);
    sea();
    return 0;
}