#include <cstdio>
#include <iostream>

const int maxn = 100005;
int heap[maxn], heap_size;

void push(int d) {
    int now, next;
    heap[++heap_size] = d;
    now = heap_size;
    while (now > 1) {
        next = now >> 1;
        if (heap[now] >= heap[next])
            break;
        std::swap(heap[now], heap[next]);
        now = next;
    }
}

int pop() {
    int now = 1, next, res = heap[1];
    heap[1] = heap[heap_size--];
    while (now * 2 <= heap_size) {
        next = now * 2;
        if (next < heap_size && heap[next + 1] < heap[next])
            next++;
        if (heap[now] <= heap[next])
            break;
        std::swap(heap[now], heap[next]);
        now = next;
        /* code */
    }
    return res;
}

int main() {
    int n, c, b;
    scanf("%d", &n);
    for (c = 0; c < n; c++)
        scanf("%d", &b), push(b);
    for (c = 0; c < n; c++)
        printf("%d ", pop());
    return 0;
}