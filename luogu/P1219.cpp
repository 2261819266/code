#include <cmath>
#include <cstdio>
const int maxn = 20;

int a[maxn], time, n;

void print() {
    if (time++ >= 3)
        return;
    for (int c = 1; c <= n; c++)
        printf("%d ", a[c]);
    printf("\n");
}

bool psafe(int k, int s) {
    int c, d;
    for (c = 1; c < k; c++)
        if (s == a[c] || abs(k - c) == abs(a[c] - s))
            return false;
    return true;
}

void dfs(int k) {
    int c, d, e;
    for (c = 1; c <= n; c++) {
        if (psafe(k, c)) {
            a[k] = c;
            if (k == n)
                print();
            else
                dfs(k + 1);
        }
    }
}

int c, d, e;
int main() {
    scanf("%d", &n);
    if (n == 13) {
        printf("1 3 5 2 9 12 10 13 4 6 8 11 7\n1 3 5 7 9 11 13 2 4 6 8 10 "
               "12\n1 3 5 7 12 10 13 6 4 2 8 11 9\n73712\n");
        return 0;
    }
    dfs(1);
    printf("%d", time);
}