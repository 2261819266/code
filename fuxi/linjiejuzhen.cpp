#include <cstdio>
#include <cstring>


using namespace std;



const int maxn = 1005;
int a[maxn][maxn];

int main() {

#ifdef LOCAL
    freopen("E:\\code\\in.in", "r", stdin);
    freopen("E:\\code\\out.out", "w", stdout);
#endif
    memset(a, 0, sizeof(a));
    
    int n, m, c, d, e, u, v, w = 1;
    scanf("%d%d", &n, &m);

    for (c = 0; c < m; c++) {
        scanf("%d%d", &u, &v);
        a[u][v] = w;
        a[v][u] = w; //有向图不需要这句
    }

    for (c = 1; c <= n; c++) {
        for (d = 1; d <= n; d++)
            printf("%d ", a[c][d]);
        printf("\n");
    }
}

