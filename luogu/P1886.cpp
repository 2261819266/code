#include <cstdio>

const int maxn = 1000000+5;

struct queue {
    int a[maxn];
    int now[maxn];
    int kn = 0, k;
    int head = 0, tail = 0;

    int front() const { return a[head + 1]; }

    int back() const { return a[tail]; }

    bool empty() const { return head == tail; }

    void push(int s) { a[++tail] = s, now[tail] = kn + k; }

    void pop() { head++; }

    void tpop() { tail--; }

    int size() const { return tail - head; }

    /* data */
};

void getmin(queue a, int n, int k) {
    queue b;
    b.k = k;
    int c, d, e;

    for (c = 0; c < n; c++) {
        b.kn++;
        while (!b.empty() && b.back() > a.front())
            b.tpop();
        while (b.now[b.head + 1] == b.kn && !b.empty())
            b.pop();
        b.push(a.front());
        a.pop();
        if (c < k - 1)
            continue;
        printf("%d ", b.front());
    }
}
void getmax(queue a, int n, int k) {
    queue b;
    b.k = k;
    int c, d, e;

    for (c = 0; c < n; c++) {
        b.kn++;
        while (!b.empty() && b.back() < a.front())
            b.tpop();
        while (b.now[b.head + 1] == b.kn && !b.empty())
            b.pop();
        b.push(a.front());
        a.pop();
        if (c < k - 1)
            continue;
        printf("%d ", b.front());
    }
}

int main() {
    int n, k, s;
    queue a;
    scanf("%d%d", &n, &k);

    for (int c = 0; c < n; c++)
        scanf("%d", &s), a.push(s);

    getmin(a, n, k);
    printf("\n");

    getmax(a, n, k);
    printf("\n");
}