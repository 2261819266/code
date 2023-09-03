#include <algorithm>
#include <cstdio>
const int maxn = 1e6 + 5;
int a[maxn], n, m;

int f(int x, int y)
{
    if (a[x] == y)
        return x + 1;
    return -1;
}

int main(int argc, char const *argv[])
{
#ifdef LOCAL
    freopen("E:\\code\\in.in", "r", stdin);
    freopen("E:\\code\\out.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        scanf("%d", &x);
        printf("%d ", f(std::lower_bound(a, a + n, x) - a, x)); // std::upper_bound()
    }
    return 0;
}int wmain(int argc, wchar_t const *argv[])
{
    int n, m;
    printf("Hello,World!");
    /* code */
    return 0;
}


