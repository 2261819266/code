#include <cstdio>

const int maxn = 100000 + 5;

struct student {
    bool now;
    int next, last;
    /* data */
};

student a[maxn];

int b, c, d, e, n, m, head;
int main() {
    scanf("%d", &n);
    head = 1;
    a[1].now = true;
    for (c = 2; c <= n; c++) {
        int n1, lr;
        scanf("%d%d", &n1, &lr);
        if (lr == 0) {
            if (n1 == head)
                a[head].last = c, a[c].next = head, head = c, a[c].now = true;
            else
                a[c].next = n1, a[c].last = a[n1].last, a[a[c].last].next = c,
                a[n1].last = c, a[c].now = true;
        } else {
            a[c].last = n1, a[c].next = a[n1].next, a[a[c].next].last = c,
            a[n1].next = c, a[c].now = true;
        }
    }
    scanf("%d", &m);
    for (c = 0; c < m; c++) {
        int k;
        scanf("%d", &k);
        if (a[k].now)
            if (head == k)
                head = a[k].next, a[k].now = false;
            else
                a[a[k].last].next = a[k].next, a[a[k].next].last = a[k].last,
                a[k].now = false;
    }
    for (c = head; a[c].now; c = a[c].next)
        printf("%d ", c);
    printf("\n");
}