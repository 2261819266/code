#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;

typedef long long ll;

ll n, d, k;

void check(int g) {
    
}

vector<ll> x, s;

ll solve() {
    cin >> n >> d >> k;
    ll ck = 0;
    
    for (int i = 0; i < n; i++) {
        ll X, S;
        cin >> X >> S;
        x.push_back(X);
        s.push_back(S);
        if (S > 0) ck += S;
    }
    if (ck < k) return -1;
    
    return -1;
}

void P3957() {
    cout << solve() << "\n";
}

int main() {
    P3957();
    return 0;
}
