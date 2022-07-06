#include <cstdio>

int b, c, d, e, f, n;

int main() {
    scanf("%d", &n);
    for (c = 0; c < n; c++) {
        scanf("%d%d", &b, &d);
        if (b > d)
            e++;
        if (d > b)
            f++;
    }
    if (e > f)
        printf("Mishka\n");
    if (f > e)
        printf("Chris\n");
    if (e == f)
        printf("Friendship is magic!^^\n");
}