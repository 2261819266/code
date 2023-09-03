#include <cstdio>
#include <functional>
#include <vector>
#include <queue>

using std::priority_queue;
using std::vector;

priority_queue<int> a;
priority_queue<int, vector<int>, std::greater<int>> b;


void add(int x) {
    if (a.empty()) return a.push(x);
    if (x <= a.top()) a.push(x);
    else b.push(x);
    int n = a.size() + b.size(), m = n / 2;
    if (b.size() > m) a.push(b.top()), b.pop();
    if (b.size() < m) b.push(a.top()), a.pop();
}

int query() {
    return a.top();
}

void P3871() {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        add(x);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        char s[10];
        int x;
        scanf("%s", s);
        if (*s == 'a') scanf("%d", &x), add(x);
        else printf("%d\n", query());
    }
}

int main() {
    P3871();
    return 0;
}
