#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#define maxn 10005
#define maxm 10005

struct E {
    int to, next;
};
E edge[maxm];
int head[maxn], top, p[maxn], pre[maxn];

void init() { memset(head, -1, sizeof(head)); }

void addedge(int u, int v) {
    edge[top] = (E){v, head[u]};
    head[u] = top++;
    edge[top] = (E){v, head[v]};
    head[v] = top++;
}

int bfs(int x, int y) {
    std::queue<int> a;
    a.push(x);
    p[x] = true;
    while (!a.empty()) {
        int k = a.front();
        if (k == y)
            return k;
        for (int c = head[k]; c != -1; c = edge[c].next) {
            int *j = &edge[c].to;
            if (!p[*j])
                p[*j] = true, a.push(*j), pre[*j] = k;
        }
        a.pop();
    }
    return -1;
}

void print(int x, int y) {
    std::stack<int> a;
    int c;
    a.push(y);
    c = y;
    while (true) {
        if (a.top() == x)
            break;
        c = pre[c];
        a.push(c);
    }
    while (!a.empty())
        printf("%c", a.top() + 64), a.pop();
}

int main() {
#ifdef LOCAL
    freopen("E:\\code\\in.in", "r", stdin);
    freopen("E:\\code\\out.out", "w", stdout);
#endif
    init();
    int n, m;
    scanf("%d%d", &n, &m);
    for (int c = 0; c < m; c++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u, v);
    }
    int k = bfs(1, n);
    print(1, k);
}