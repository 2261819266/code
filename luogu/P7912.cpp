#include <cstdio>

const int maxn = 2e5 + 8;
struct Node {
    Node *next, *last, *to, *lto;
    int data, id;
} *f = new Node();


int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n;
    scanf("%d", &n);
    Node *now = f, *x = f;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &now->data);
        now->id = i;
        if (i - n) now->next = new Node(),
        now->next->last = now;
        if (x->data ^ now->data) x->to = now, now->lto = x, x = now;
        now = now->next;
    }
    while (f) {
        Node *i;
        for (i = f; i->to; i = i->to)
            printf("%d ", i->id);
        printf("%d\n", i->to->id);
        for (; i; i = i->lto) {
            while (i->data ^ i->next->data) {
                i->to = 
            }
        }
    }
}