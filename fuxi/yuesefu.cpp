// 约瑟夫问题 输出n-1的循序
#include <cstdio>
#include <iostream>
#include <queue>

int n, c, d, e, k;
std::queue<int> a, b;
int main() {
    scanf("%d%d", &n, &k);
    for (c = 0; c < n; c++) {
        b.push(c + 1);
    }
    d = 1;
    // printf("%d", b.size());
    for (; b.size() != 1;) {
        for (; !b.empty();) {
            if (d)
                a.push(b.front());
            else
                printf("%d ", b.front());
            b.pop();

            ++d %= k;
        }
        std::swap(a, b);
    }
}