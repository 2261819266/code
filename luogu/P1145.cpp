#include <cstdio>
#include <string>

struct Node {
    bool k;
    int next;
    int last;
}a[21];

void init(int n) {
    int cnt = 0;
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < n; i++) {
            a[cnt++] = (Node) {!k, k * n + i + 1, k * n + i - 1};
        }
    }
    a[2 * n - 1].next = 0;
    a[0].last = 2 * n - 1;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n;
    scanf("%d", &n);
    bool ans = false;
    for (int i = 1;; i++) {
        // if 
        ans = true;
        init(n);
        for (int j = 0, now = a[0].last; j < n; j++) {
            for (int k = 0; k < i; k++) {
                now = a[now].next;
            }
            if (a[now].k) {
                ans = false;
                break;
            }
            a[a[now].last].next = a[now].next;
            a[a[now].next].last = a[now].last;
        }
        if (ans) {
            printf("%d", i);
            return 0;
        }
    }
}