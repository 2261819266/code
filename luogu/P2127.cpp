#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::vector;
using std::sort;
using std::cout;
using std::lower_bound;

void P2127() {
    int n;
    cin >> n;
    vector<int> a, b, c, d; // a init  b sort  c change  d map

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
    
}

int main() {
    P2127();
    return 0;
}