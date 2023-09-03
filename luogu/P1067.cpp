#include <cstdio>

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n;
    scanf("%d", &n);
    for (int i = n; i >= 0; i--) {
        int x;
        scanf("%d", &x);
        if (x) {
            if (n - i && x > 0) printf("+");
            if (!i) printf("%d", x);
            else if (x == -1) printf("-");
            else if (x != 1) printf("%d", x); 
            if (i) printf("x");
            if (i > 1) printf("^%d", i);  
        }
    }
}