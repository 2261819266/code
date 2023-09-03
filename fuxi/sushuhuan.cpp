#include <cstdio>

bool su(int k) {
    int e = 0;
    if (k > 1) {
        e++;
        for (int c = 2; c * c <= k; c++) {
            if (k % c == 0)
                e++;
        }
    }
    if (e == 1)
        return true;
    return false;
}
const int n = 18;

int a[n + 1], zt[n + 1];

void print() {
    for (int c = 1; c <= n; c++)
        printf("%d ", a[c]);
    printf("\n");
}

void search(int k) {
    int c, d, e;
    if (k == n) {
        for (c = 2; c <= n; c++)
            if (!zt[c])
                if (su(c + 1) && su(c + a[k - 1]))
                    a[k] = c, print();
                else
                    return;
        return;
    }
    for (c = 2; c <= n; c++) {
        if (!zt[c] && su(a[k - 1] + c)) {
            a[k] = c;
            zt[c] = true;
            search(k + 1);
            zt[c] = false;
        }
    }
}

int c, d, e;

int main() {
    freopen("sushuhuan.out","w",stdout);
    a[1] = 1;
    zt[1] = true;
    search(2);
}