// #include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int inf = 1 << 30;
int n, m, s, t;
struct Node {
    int v;
    int val;
    int next;
} node[201010];
int top = 1, head[101010]; //top必须从一个奇数开始，一般用-1但我不习惯，解释见下方
inline void addedge(int u, int v, int val) {
    node[++top].v = v;
    node[top].val = val;
    node[top].next = head[u];
    head[u] = top;
}
inline int Read() {
    int x = 0;
    char c = getchar();
    while (c > '9' || c < '0')
        c = getchar();
    while (c >= '0' && c <= '9')
        x = x * 10 + c - '0', c = getchar();
    return x;
}
int inque[101010]; //点是访问过里
struct Pre {
    int v;    //该点的前一个点（从起点过来）
    int edge; //与该点相连的边（靠近起点的）
} pre[101010];
inline bool bfs() {
    queue<int> q;
    memset(inque, 0, sizeof(inque));
    memset(pre, -1, sizeof(pre));
    inque[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = node[i].next) {
            int d = node[i].v;
            if (!inque[d] && node[i].val)
            { //node[i].val==0则已经该路径满了
                pre[d].v = u;
                pre[d].edge = i;
                if (d == t)
                    return 1;
                inque[d] = 1;
                q.push(d);
            }
        }
    }
    return 0;
} //是否有增广路
int EK() {
    int ans = 0;
    while (bfs())
    {
        int mi = inf;
        for (int i = t; i != s; i = pre[i].v)
        {
            mi = min(mi, node[pre[i].edge].val); //每次只能增加增广路上最小的边的权值
        }
        for (int i = t; i != s; i = pre[i].v)
        {
            node[pre[i].edge].val -= mi;
            node[pre[i].edge ^ 1].val += mi;
            //反向的边的编号是正向边的编号^1
            //这就是为什么top开始时必须是奇数
        }
        ans += mi;
    }
    return ans;
}
int main() {
#ifdef LOCAL
    LOCALfo
#endif
    register int i;
    n = Read(), m = Read(), s = Read(), t = Read();
    int u, v, w;
    for (i = 1; i <= m; i++)
        u = Read(), v = Read(), w = Read(), addedge(u, v, w), addedge(v, u, 0);
    printf("%d", EK());
    return 0;
}