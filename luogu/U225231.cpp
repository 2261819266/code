#include <cstdio>

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int a, b;
    scanf("%d%d", &a, &b);
    int x = (b / a);
    printf("%.9lf", x * 1.0 / b);
}