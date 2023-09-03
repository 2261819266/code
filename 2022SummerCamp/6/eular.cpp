#include "../../template/edgetable"
#include <stack>
#include <cstdio>


const int maxn = 1e5 + 8;
int vis[maxn];
std::stack<int> stk;

EdgeTable a;

void dfs(int u) {
    for (auto i = a.begin(u); i; i++) {
        if (vis[i.to]) {
            continue;
        }
        vis[i.to] = 1;
        dfs(i.to);
    }
    stk.push(u);
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif  
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        a.add_edge(u, v);
    }
    dfs(1);
    while (stk.size()) {
        printf("%d ", stk.top());
        stk.pop();
    }
}