#include <cstdio>

int m, d;
const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int f(int m, int d) {
    if (m > 0 && m <= 12 && d > 0 && d <= days[m]) return 0;
    int ans = 0;
    if (m > 12 && m < 20) ans++, m = 12;
    if (m >= 20) {
        if (m % 10 == 2) m = 12;
        if (m % 10 == 0) m = 10;
        if (m % 10 == 1) m = 1;
        if (m % 10 > 2) m %= 10;
        ans++;
    }
    if (d > days[m]) ans++;
    return ans;
}

int main() {
    scanf("%d-%d", &m, &d);
    printf("%d", f(m, d));
}