#include <cstdio>
#include <queue>

struct node {
    int data;
    bool operator<(const node &a) const { return data >a.data; }
    /* data */
};

std::priority_queue<int> a;
std::priority_queue<node> b;
int c, d, e, n, x, y;
int main() {
    scanf("%d", &n);
    for (c = 0; c < n; c++)
        scanf("%d", &d), a.push(d), b.push((node){d});
    e = 0;
    while (b.size() > 1)
        x = b.top().data, b.pop(), y = b.top().data, b.pop(), b.push((node){x + y}), e += x + y;
    printf("%d\n", e);
    e = 0;
    while (a.size() > 1)
        x = a.top(), a.pop(), y = a.top(), a.pop(), a.push(x + y), e += x + y;
    printf("%d\n", e);
}