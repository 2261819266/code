#include <cstdio>
#include <cstring>

char a[26], b[26];
int c, d, e;
int main() {
    scanf("%s%s", a, b);
    for (c = 1; c < strlen(a); c++)
        for (d = 1; d < strlen(b); d++)
            if (a[c] == b[d - 1] && a[c - 1] == b[d])
                e++;
    printf("%lld", 1 << e);
}