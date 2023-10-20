#include <algorithm>
#include <iostream>
#include  <vector>


using std::cin;
using std::vector;
vector<int> a, b;

int dfs(int x = 0, int y = 0, int z = 0) {
    if (x == a.size()) {
        if (x < 0 || y < 0) return -a.size();
        return 0;
    }
    return std::max(dfs(x + 1, y, z), dfs(x + 1, y - a[x], z - b[x]) + 1);
}

void sell() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        y -= x;
        z -= x;
        a.push_back(y);
        b.push_back(z);
    }
    std::cout << dfs() << "\n";
}

int main() {
    sell();
    return 0;
}
