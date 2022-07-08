#include <cstdio>
#include <queue>
#include <cstring>
#include <stack>
#include <algorithm>
#define ll long long
// the problem is on "https://www.luogu.com.cn/problem/P3376".
// the way can get 73pts of 100pts.

using std::queue;
using std::stack;

const int maxn = 205, maxm = 5005;
struct E {
    int to, next;
} edge[maxm << 2];
ll a[maxn][maxn];
int cnt, head[maxn];

void init() { memset(head, -1, sizeof(head)); }

void addedge(int u, int v) {
    edge[cnt] = (E) {v, head[u]};
    head[u] = cnt++;
}

stack<int> findWay(int s, int t) {
    int last[maxn];
    memset(last, -1, sizeof(last));
    last[s] = 0;
    queue<int> q;
    stack<int> ans;
    q.push(s);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == t) {
            while (x - s) {
                ans.push(x);
                x = last[x];
            }
            return ans;
        }
        for (int i = head[x]; ~i; i = edge[i].next) {
            int to = edge[i].to;
            if (a[x][to] && !~last[to]) {
                last[to] = x;
                q.push(to);
            }
        }
    }
    return ans;
}

int n, m, s, t;

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    init();
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v);
        a[u][v] += w;
    }
    ll ans = 0;
    for (stack<int> i = findWay(s, t); !i.empty(); i = findWay(s, t)) {
        stack<int> j = i;
        ll min = 0x7fffffffff;
        for (int k = s, l = j.top(); !j.empty(); k = l) {
            l = j.top();
            j.pop();
            min = std::min(min, a[k][l]);
        }
        j = i;
        for (int k = s, l = j.top(); !j.empty(); k = l) {
            l = j.top();
            j.pop();
            a[k][l] -= min;
        }
        ans += min;
    }
    printf("%lld", ans);
}