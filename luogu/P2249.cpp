#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int *find2(int *a, int b, int k) {
    if (b == 0) {
        if (*a == k)
            return a;
        return 0;
    }
    int c=b/2;
    return min(find2(a,c, k), find2(a +c, b, k));
}
int a[20000];
int b, c, d, e, n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (c = 0; c < n; c++) {
        scanf("%d", &a[c]);
    }
    for (c = 0; c < m; c++) {
        scanf("%d", &b);
        printf("%d", *find2(a, n, b) + 1);
    }
}