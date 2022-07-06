#include <cstdio>
using namespace std;
int a[1000], b, c, n;
int main() {
    scanf("%d", &n);
    for (c = 0; c < n; c++) {
        scanf("%d", &a[c]);
    }
    printf("%d ", a[0]);
    for (c = 1; c < n; c++) {
        printf("%d ", a[c] += a[c - 1]);
    }
}