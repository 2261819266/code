#include <cstdio>
#include <queue>
#include <set>
#include<string.h>

const int maxn = 100005, maxm = 1000005;
std::set<int> *a=new std::set<int>[maxn], *b=new std::set<int>[maxn];
bool *df=new bool[maxn], *bf=new bool[maxn];

void dfs(int k) {
    if (df[k])
        return;
    printf("%d ", k);
    df[k] = true;

    for (std::set<int>::iterator it = a[k].begin(); it != a[k].end(); it++)
        dfs(*it);
}

void bfs(int k) {
    std::set<int>::iterator it;
    std::queue<int> s;
    s.push(k);
    bf[k] = true;
    while (!s.empty()) {
        int x = s.front();
        for (it = a[x].begin(); it != a[x].end() && !bf[*it]; it++)
            bf[*it] = true, s.push(*it);
        printf("%d ", x);
        s.pop();
    }
}

int n, m, u, v, c, d, e;

int main() {
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    memset(df,false,maxn);
    memset(bf,false,maxn);
    for (c = 0; c < m; c++)
        scanf("%d%d", &u, &v), a[u].insert(v), b[v].insert(u);
    for (c = 1; c <= n; c++)
        if (b[c].size() == 0) {
            dfs(c);
            printf("\n");
            bfs(c);
            return 0;
        }
}