#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> a;

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a.insert(std::lower_bound(a.begin(), a.end(), x), x);
        if (i % 2) {
            printf("%d\n", a[i / 2]);
        }
    }
}