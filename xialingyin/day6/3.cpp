#include <cstdio>
#include <iostream>
int a[1000001], b, c, d, e, n;
int main() {
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    scanf("%d", &n);
    for (c = 0; c < n; c++) {
        scanf("%d", &a[c]);
    }
    for (c = 0; c * 2 < n; c++) {
        if (a[c] != a[n - c - 1]) {
            int k=a[c];
            for(d=c;d<n-c-1;d++){
                if(a[d]==k)a[d]=a[n-c-1];
            }
            e++;
        }
    }
    printf("%d", e);
}