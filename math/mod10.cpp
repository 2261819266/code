#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>

bool St;
bool Ed;

int main() {
	std::cerr << (double)std::abs(&Ed - &St) / 1024.0 / 1024.0 << "Mb\n";
    long long n, m, num = 0;
    scanf("%lld", &n);
    std::vector<int> a;
    a.assign(n, 1);
    for (long long i = 2; i * i < n; i++) {
        if (!a[i]) continue;
        for (long long j = 2 * i; j < n; j += i) {
            a[j] = 0;
        }
        // printf("%d\n", i);
    }
    scanf("%lld", &m);
    std::vector<int> b;
    b.assign(m, 0);
    for (long long i = 2; i < n; i++) {
        if (a[i]) b[i % m]++, num++;
    }
    for (long long i = 0; i < m; i++) {
        printf("%d,%d,%.6lf%%\n", i, b[i], b[i] * 100.0 / num);
    }
    printf("%.2lf%%,%lld", num * 100.0 / n, num);
	std::cerr << "\n" << double(clock()) / CLOCKS_PER_SEC << "s\n";
}
