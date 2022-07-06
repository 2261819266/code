#include <cstdio>
#include <cstring>
#include <iostream>
const int maxn = 100, maxw = 10000;
int dp[maxn + 1][maxw + 1];
int n, w[maxn + 1], v[maxn + 1], W;

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> w[i] >> v[i];
    std::cin >> W;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= W; j++) {
            if (j < w[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    std::cout << dp[n][W] << std::endl;
}