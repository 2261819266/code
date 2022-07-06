#include <cstdio>
#include <iostream>
using namespace std;
int a[1005][1005], c, d, e, n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (c = 1; c <= n; c++) {
        for (d = 1; d <= m; d++) {
            scanf("%d", &a[c][d]);
            printf("%d ",
                   a[c][d] += a[c - 1][d] + a[c][d - 1] - a[c - 1][d - 1]);
        }
        printf("\n");
    }
    system("pause");
}