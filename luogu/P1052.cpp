#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::vector;
using std::min;
using std::max;
using std::cout;
using std::endl;


vector<int> a, f;

void P1052() {
    int l, s, t, m;
    cin >> l >> s >> t >> m;
    a.assign(l + 1, 0);
    f.assign(l + 1, m);
    while (m--) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    f[0] = 0;
    for (int i = s; i <= l; i++) {
        int L = max(0, i - t);
        for (int j = L; j <= i - s; j++) {
            f[i] = min(f[i], f[j]) + a[i];
        }
    }
    cout << f[l] << endl;
}

int main() {
    P1052();
    return 0;
}
