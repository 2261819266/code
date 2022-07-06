#include <cstdio>
#include <queue>
#define f4 for (int i = 0; i < 4; i++)

const int maxn = 1e5 + 8;
int a[4][maxn], n[4], qt;
std::priority_queue<int> q[4];

int main () {
#ifdef LOCAL
    LOCALfo
#endif
    f4 scanf("%d", n + i);
    f4 for (int j = 0; j < n[i]; j++) {
        int x;
        scanf("%d", &x);
        q[i].push(x);
    }
    scanf("%d", &qt);
    for (int i = 0; i < qt; i++) {
        int x[3];
        scanf("%d%d%d", x, x + 1, x + 2);
        int ans = q->top();
        q->pop();
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < x[j]; k++) {
                ans += q[j + 1].top();
                q[j + 1].pop();
            }
        }
        printf("%.2lf\n", ans * 1.0 / 11);
    }
}