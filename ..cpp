#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::cerr;

const int _K = 4;

#define ll long long 
#define sa (b + c)
#define sb (a + c)
#define sc (a + b)
#define ma (sb * sc)
#define mb (sa * sc)
#define mc (sb * sa)

template<typename t = double>
t fl(t a, t b, t c) {

    return a / sa + b / sb + c / sc;
}

template<typename t = ll> 
t gl(t a, t b, t c) {
    return a * ma + b * mb + c * mc;
}

template<typename t = ll> 
t gr(t a, t b, t c) {
    return sa * mc * _K;
}

template<typename t = ll> 
t checker(t a, t b, t c) {
    return gl(a, b, c) - gr(a, b, c);
}

int main() {
    const double e = 1e-9;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int nxt = 1;
        for (int j = i; j <= n; j++) {
            for (int k = nxt; k <= n; k++) {
                double s = fl<double>(i, j, k);
                if (s > 4.01) break;
                if (s > 3.5) nxt = k;
                if (fabs(s - _K) < e) {
                    ll d = checker(i, j, k);

                    cout << i << " " << j << " " << k << " " << s - 4 
                        << " " << d << " " << d * 1.0 / gr(i, j, k) << "\n";

                    cerr << i << " " << j << " " << k << " " << s - 4 
                        << " " << d << " " << d * 1.0 / gr(i, j, k) << "\n";
                }
                // cout << s << "\n";
            }
        }
    }
}