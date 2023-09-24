#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long 

using std::cin;
using std::cout;
using std::vector;
using std::max;

vector<vector<int>> a;
vector<vector<vector<ll>>> f; // 0 down 1 up 2 right

int to[3][2] = {{1, 0}, {-1, 0}, {0, 1}};
int n, m, inf = 0x3f3f3f3f;


ll dfs(int x, int y, int z) {
    if (x == n - 1 && y == m - 1) return f[x][y][z] = a[x][y];
    if (f[x][y][z] != -inf) return f[x][y][z];
    ll ans = -inf;
    for (int i = 0; i < 3; i++) {
        if (i == !z && z < 2) continue;
        int tx = x + to[i][0];
        int ty = y + to[i][1];
        int tz = i;
        if (tx < 0 || tx == n || ty < 0 || ty == m) continue;
        ans = max(ans, dfs(tx, ty, tz));
    }
    return f[x][y][z] = ans + a[x][y];
}

void P7074() {
    cin >> n >> m;
    a.assign(n, vector<int>(m, 0));
    f.assign(n, vector<vector<ll>>(m, vector<ll>(3, -inf)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cout << dfs(0, 0, 2);
}

int main() {
    P7074();
    return 0;
}
