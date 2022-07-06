#include <cstdio>
#include <iostream>

const int maxn = 10000 + 5;
int a[maxn], top;

void push(int x) {
    a[++top] = x;
    int now = top, next;
    while (now > 1) {
        next = now >> 1;
        if (a[now] < a[next])
            std::swap(a[now], a[next]), now = next;
        else
            return;
    }
}

int pop() {
    int res = a[1], now = 1, next;
    a[1] = a[top--];
    while (now * 2 <= top) {
        next = now << 1;
        if (a[next] > a[next + 1] && next < top)
            next++;
        if (a[now] < a[next])
            break;
        std::swap(a[next], a[now]);
        now = next;
    }
    return res;
}

int main() {
    int n, b, c, x, y, e = 0;
    scanf("%d", &n);
    for (c = 0; c < n; c++)
        scanf("%d", &b), push(b);
    while (top > 1)
        x = pop(), y = pop(), push(x + y), e += x + y;
    printf("%d ", e);
}