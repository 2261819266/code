#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct lujing {
    int x;
    int sum;
    int u, v, w;
};


double minn;
double maxx = 0x7f;
int main() {
    int nn;
    int time[1001];
    lujing a[1001];
    int b[100001];
    // bool c[10001];
    int n, m, i, k,c,d,e;
    freopen("travel.in", "r", stdin);
    //	freopen("travel.out","w",stdout);

    cin >> n >> m;
    for (i = 1; i <= n; i++)
        cin >> time[i];
    for (i = 1; i <= m*2; i += 2) {
        int a1, a2, a3;
        scanf("%d%d%d", &a1, &a2, &a3);
        a[i].u = a[i + 1].v = a1;
        a[i + 1].v = a[i].v = a2;
        a[i].w = a[i + 1].w = a3;
        a[i].w += time[a[i].u];
        a[i + 1].w += time[a[i].u];
    }
    // memset(c, false, sizeof(c));
    // c[1] = 1;
    b[1] = 0;
}