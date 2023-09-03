#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int n;

const int maxn = 1e6 + 8;

long long x[maxn << 2];
int s[4];
int flag;
long long t[maxn][4], a[maxn << 4];
int main()
{
    freopen("score.in", "r", stdin);
    freopen("score.out", "w", stdout);
    cin >> n;
    int n4;
    n4 = 4 * n;
    for (int i = 1; i <= n4; i++)
    {
        cin >> x[i];
    }
    sort(x + 1, x + n4 + 1, greater<int>());
    for (int i = 0; i < 4; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            t[i][j] = x[4 * (i - 1) + j + 1] + s[j];
        }
    }
    int k[4];
    for (int i = 1; i <= n; i++)
    {
        std::sort(t[i], t[i] + 4, [](int x, int y) { return x > y; });
        for (int j = 0; j < 4; j++)
        {
            a[4 * (i - 1) + j + 1] = t[i][j];
        }
    }
    for (int i = 1; i <= n4; i++)
    {
        if (i % 6 == 1)
            cout << a[i] << " ";
    }
    return 0;
}