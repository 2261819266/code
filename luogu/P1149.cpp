#include <cstdio>
#include <cstring>

const int p10[] = {1, 10, 100, 1000, 10000};
const int number[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int num(int x) {
    int ans = 0;
    char s[10];
    sprintf(s, "%d", x);
    for (int i = 0; i < strlen(s); i++) {
        ans += number[s[i] - '0'];
    }
    return ans;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n, ans = 0;
    scanf("%d%d", &n);
    n -= 4;
    for (int i = 0; i < p10[3]; i++) {
        // int m = n - num(i);
        // if (m < 4) continue;
        for (int j = 0; j < p10[3]; j++) {
            if (num(i) + num(j) + num(i + j) == n) ans++;
        }
    }
    printf("%d", ans);
}