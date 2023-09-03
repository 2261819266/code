#include <cstdio>

const int maxn = 1e5 + 8;
int a[maxn], b[maxn], s[maxn];

int main(int argc, char const *argv[]) {
    int n = 4;
    // scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", s + i);
    }
    // for(int i = 1; i <= n; i++) {
    //     scanf("%d", b + i);
    // }
    for(int i = 1; i <= n; i++) {
        int ans1 = 0, ans2 = 0;
        for(int j = 1; j <= n; j++) {
            ans1 += s[i] & s[j];
            ans2 += s[i] | s[j];
        }
        printf("%d %d\n", ans1, ans2);
    }
    // printf("%d", 2 & 5 & 1 & 4 & 2 & 2 & 2 & 2);
    return 0;
}
