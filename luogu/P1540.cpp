#include <cstdio>

const int maxn = 1005;

struct queue {
    int a[maxn];
    int n;
    int front, back;

    bool empty() { return front == back; }

    void push(int k) { a[++back] = k; }

    void pop() { front++; }

    int size() { return back - front; }

    bool find(int x) {
        for (int c = 1; c <= size(); c++)
            if (a[c + front] == x)
                return true;
        return false;
    }
};
queue a;

int n, m, b, c, d, e;
int main() {
    scanf("%d%d", &n, &m);

    for (c = 0; c < m; c++) {
        int k;

        scanf("%d", &k);
        if (!a.find(k)) {
            if (a.size() == n)
                a.pop();
            a.push(k);
            e++;
        }
    }
    printf("%d",e);
}