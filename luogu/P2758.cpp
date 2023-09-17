#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::min;

int min(int x, int y, int z) {
    return min(x, min(y, z));
}

int main() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = (i == 0 ? i : 
                (j == 0 ? j : 
                    ( a[i - 1] == b[j - 1] ? f[i - 1][j - 1] :
                        min(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]) + 1
                    )
                ));

            // printf("%d ", f[i][j]);
        }
        // putchar(10);
    }

    printf("%d\n", f[n][m]);
}
