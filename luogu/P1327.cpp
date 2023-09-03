#include <algorithm>
#include <iostream>
#include<cstdio>
using namespace std;

int a[1000000], b[1000000], c, d, e, n;
int main() {
    // 输入
    scanf("%d", &n);
    for (int c = 0; c < n; c++) {
        scanf("%d", &a[c]);
    }
    for (c = 0; c < n; c++) {
        b[c] = a[c];
    }

    // 排序
    sort(b, b + n);
    for (c = 0; c < n; c++) {
        if (a[c] != b[c]) {
            for (d = c+1; d < n; d++) {
                if (a[d] == b[c]) {
                    swap(a[d], a[c]);
                    e++;
                }
            }
        }
    }
    printf("%d", e);
    return 0;
}