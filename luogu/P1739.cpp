#include <cstdio>
#include <stack>

char s;
int a, b, c, d, e, n;

int main() {
    for (scanf("%c", &s); s != '@'; scanf("%c", &s)) {
        if (s == '(')
            a++;
        if (s == ')') {
            if (a == 0) {
                printf("NO");
                return 0;
            }
            a--;
        }
    }
    if (a > 0)
        printf("NO");
    else
        printf("YES");
}