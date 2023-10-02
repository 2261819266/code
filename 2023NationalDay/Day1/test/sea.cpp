#include <ctime>
#include <iostream>
#include <vector>

using std::cin;
using std::cerr;
using std::vector;

const long long M = 1e9 + 7;

void sea() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long ans = 1, cut = 1;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        // scanf("%d%d", &x, &y);
        a[i] = y - x + 1;
        // a.push_back(y - x + 1);
        ans *= a[i];
        cut *= (a[i] - 1);
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
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    sea();
    cerr << (double)clock() / CLOCKS_PER_SEC << "s\n";
    return 0;
}