#include <cstdio>
#include <iostream>
#include <stack>
//维护一个单调递增的栈

struct P1165 {
    int data;
    int address;
    /* data */
};

int main() {
    // freopen("P1165.in","r",stdin);
    std::stack<P1165> a;
    int n, c, d = 0, e, k;
    scanf("%d", &n);

    for (c = 0; c < n; c++) {
        scanf("%d", &k);

        if (k == 0) {
            P1165 s;
            scanf("%d", &s.data);
            s.address = d++;
            if (a.empty()) {
                a.push(s);
                continue;
            }
            if (s.data < a.top().data)
                continue;
            a.push(s);
            continue;
        }
        if (k == 1) {
            if (!a.empty())
                if (a.top().address == --d)
                    a.pop();
            continue;
        }
        if (k == 2) {
            if (a.empty())
                printf("0\n");
            else
                printf("%d\n", a.top().data);
        }
    }
}