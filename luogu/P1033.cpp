#include <cstdio>
#include <cmath>
#include <algorithm>

const int maxn = 1e5 + 8;
const double K = 0.0001;
double h, s, v, l, k, n, *p = &h;

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    for (int i = 0; i < 6; i++) {
        scanf("%lf", p + i);
    }
    double time = sqrt((h - k) / 5);
    double ss = time * v;
    double L = s - ss, R = L + l;
    time = sqrt(h / 5);
    ss = time * v;
    L = s - ss + k / 100;
    L = std::max(0.0, L);
    R = std::min(n, R);
    int LL = ceil(L);
    int RR = floor(R);
    if (LL - L > 1 - K) 
        LL--;
    if (R - RR > 1 - K) 
        RR++;
    printf("%d", std::max(0, (int)(RR - LL + 1)));
}