#include <cstdio>
#include <iostream>
#include <ostream>
#include <vector>
#include <queue>

using std::vector;

struct Point {
    int x, y;
    bool operator==(const Point &p) const {
        return x == p.x && y == p.y;
    }
};

void AT_dfs_a() {
    int n, m;
    Point s, g;
    std::cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<int> p(128);
    p['s'] = 1;
    p['g'] = 2;
    p['.'] = 0;
    p['#'] = -1;
    for (int i = 0; i < n; i++) {
        for (int  j = 0; j < m; j++) {
            char x;
            std::cin >> x;
            a[i][j] = p[x];
            if (p[x] == 1) s = {i, j};
            if (p[x] == 2) g = {i, j};
        }
    }
    
    std::queue<Point> q;
    q.push(s);
    a[s.x][s.y] = -1;
    int to[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
    while (!q.empty()) {
        Point u = q.front();
        q.pop();
        int x = u.x;
        int y = u.y;
        if (u == g) {
            std::cout << "Yes" << std::endl;
            return;
        }

        for (int *i : to) {
            if (x + i[0] < n && y + i[1] < m && x + i[0] >= 0 && y + i[1] >= 0 && ~a[x + i[0]][y + i[1]]) {
                q.push({x + i[0], y + i[1]});
                a[x + i[0]][y + i[1]] = -1;  
            }
        }
    }
    std::cout << "No" << std::endl;
}

int main() {
    AT_dfs_a();
    return 0;
}