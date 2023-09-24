#include <iostream>
#include <type_traits>
#include <vector>
#include <algorithm>

using std::cin;
using std::vector;
using std::sort;
using std::cout;
using std::lower_bound;

// a init  b sort  c change  d map
// a 8 4 5 3 2 7
// b 2 3 4 5 7 8
// c 5 2 3 1 0 4
// d 4 3 1 2 5 0
vector<int> a, b, c, d; 

void theSwap(int x, int y) {
    std::swap(c[x], c[y]);
    std::swap(d[c[x]], d[c[y]]);
}

void P2127() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    b = a;
    sort(b.begin(), b.end());
    c.assign(n, 0);
    d.assign(n, 0);
    for (int i = 0; i < n; i++) {
        c[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        d[c[i]] = i;
    }
    // for (int i : d) { cout << i << " "; }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        const int &now = d[i];
        while (now != c[now]) {
            int to = d[now];
            ans += b[c[now]] + b[c[to]];
            theSwap(now, to);
        }
    }
    cout << ans;
}

int main() {
    P2127();
    return 0;
}