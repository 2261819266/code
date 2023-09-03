#include <cstdio>
#include <vector>
#include <algorithm>

#define fo(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);

const int maxn = 1e5 + 8;
std::vector<int> a[2];

void toy() {
    int n;
    scanf("%d", &n);
    // if (n > 1000) {
    //     int i;
    //     int x = 1, y;
    //     for (i = 0; i < n; i++) {
    //         scanf("%d%d", &x, &y);
    //         if (!x) break;
    //         a[x].push_back(y);
    //     }
    //     a[x].push_back(y);
    //     for (i++; i < n; i++) {
    //         scanf("%d%d", &x, &y);
    //         a[x].push_back(y);
    //     }   
    //     int ans = 0;
    //     for (auto j : a[0]) {
    //         auto k = std::lower_bound(a[1].begin(), a[1].end(), j);
            
    //     }
    //     return;
    // }
    
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        std::sort(a[x].begin(), a[x].end());
        int ans = 0, j = 0;
        for (auto it : a[1]) {
            while (j < a[0].size() && it > a[0][j]) j++;
            if (j >= a[0].size()) break;
            ans++;
            j++;
        }
        printf("%d\n", ans);
    }
}

int main() {
    fo(toy)
    toy();
    return 0;
}