#include <cstdio>

int n;
char a[101], b[101];

int main() {
#ifdef LOCAL    
    LOCALfo
#endif
    scanf("%d", &n);
    scanf("%s%s", a, b);
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            printf("-1");
            return 0;
        }
    }
    printf("%s", b);
}