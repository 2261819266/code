#include <iostream>

using std::cin;
using std::cout;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ans = 0, p = 0;
    while (n) {
        if (n % 3 == 1 && !p) p = ans + 1;
        n = n * 2 / 3; 
        ans++;
    }
    cout << ans << " " << p;
}
