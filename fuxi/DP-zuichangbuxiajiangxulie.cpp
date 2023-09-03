#include <cstdio>
#include<string.h>
const int N = 15;
const int inf = 0x7fffffff;
int n, len, a[N], f[N], pre[N], ans[N], c, d; // f为状态描述，pre记录决策树
int main() {
    // freopen("DP.in", "r", stdin);
    // memset(f, 0, sizeof(f));
    // memset(pre, 0, sizeof(pre));
    scanf("%d", &n);
    for (c = 1; c <= n; c++)
        scanf("%d", &a[c]);

    // a[0] = -inf-1; //尽管a[0]不存在，因为f[1]要与a[0]比较，因此设为最小

    for (c = 1; c <= n; c++) {
        pre[c] = 0; //初始化决策
        for (d = 1; d < c; d++)
            if (a[d] <= a[c] && f[d] > f[pre[c]])
                pre[c] = d; //记录决策

        f[c] = f[pre[c]] + 1; //更新最优值
        // e = std::max(e, f[c]);
    }
    // printf("%d", e);
    int tail = 0;
    for (c = 1; c < n; c++) //找到最长子序列的位置
        if (f[tail] <= f[c])
            tail = c;

    while (tail) //将最优子序列逆序放入ans中
        ans[++len] = tail, tail = pre[tail];

    printf("%d\n", len);

    while (len)
        printf("%d ", a[ans[len--]]);
    printf("\n");
    return 0;
}