#include <cstdio>
#include <iostream>

// 小根堆  每个数据大于0且小于int型范围

const int maxn = 10005;
int heap[maxn], top;

void push(int x) {
    int c;
    heap[++top] = x;
    for (c = top; c > 1;)
        if (heap[c] < heap[c / 2])
            std::swap(heap[c], heap[c / 2]), c /= 2;
        else
            return;
}

void pop(int add = 1) {
    if (!top)
        return;
    int c;
    heap[add] = heap[top--];
    for (c = add; c <= top;) {
        bool k1 = heap[c] > heap[2 * c] && 2 * c <= top;
        bool k2 = heap[c] > heap[2 * c + 1] && 2 * c + 1 <= top;
        bool k3 = heap[2 * c] <= heap[2 * c + 1];
        if (k1 && k2) {
            std::swap(heap[c], k3 ? heap[2 * c] : heap[2 * c + 1]);
            c = k3 ? 2 * c : 2 * c + 1;
        } else {
            if (k1)
                std::swap(heap[c], heap[2 * c]), c = 2 * c;
            if (k2)
                std::swap(heap[c], heap[2 * c + 1]), c = 2 * c + 1;
            if (!(k1 || k2))
                return;
        }
    }
}

int b, c, d, e, n, m;

int main() {
    scanf("%d%d", &n, &m);
    for (c = 0; c < n; c++)
        scanf("%d", &b), push(b);
    for (d = 0; d <= m; d++) {
        for (c = 1; c <= top; c++)
            printf("%d ", heap[c]);
        printf("\n");
        pop();
    }
}
