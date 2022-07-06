#include <cstdio>
#include <iostream>

const int maxn = 100000 + 5;
int a[maxn], top;

void push(int x) {
    int c;
    a[++top] = x;
    for (c = top; c > 1;)
        if (a[c] < a[c / 2])
            std::swap(a[c], a[c / 2]), c /= 2;
        else
            return;
}

void swap1(int &c, bool k) {
    std::swap(a[c], k ? a[2 * c] : a[2 * c + 1]), k ? c *= 2 : c += c + 1;
}

int pop(int add = 1) {
    if (!top)
        return 0;
    int res = a[add];
    a[add] = a[top--];
    int c;
    for (c = add; c <= top;) {
        bool k1 = a[c] > a[2 * c] && 2 * c <= top;
        bool k2 = a[c] > a[2 * c + 1] && 2 * c + 1 <= top;
        bool k3 = a[2 * c] <= a[2 * c + 1];
        if (k1 && k2)
            swap1(c, k3);
        else if (k1)
            swap1(c, 1);
        else if (k2)
            swap1(c, 0);
        else
            break;
    }
    return res;
}

int b, c, d, e, n;

int main() {
    scanf("%d", &n);
    for (c = 0; c < n; c++)
        scanf("%d", &b), push(b);
    // for (c = 1; c <= n; c++)
    //     printf("%d ", pop());
    for (b = e = 0; top>1; b = 0)
        b += a[1], pop(), b += a[1], pop(), e += b, push(b);
    printf("%d", e);
}
