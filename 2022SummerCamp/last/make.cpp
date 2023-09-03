#include <cstdio>

int main(int argc, char **s) {
    // freopen("in.in", "r", stdin);
    freopen("ball.in", "w", stdout);
    
    int n, m;
    sscanf(s[1], "%d", &n);
    sscanf(s[2], "%d", &m);
    printf("%d\n", n);
    // for (int i = 0; i < n; i++) {
    //     printf("%d %d\n", m, i);
    // }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d %d\n", i, j);
        }
    }
}