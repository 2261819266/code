#include <cstdio>
#include <vector>

using Pair = std::pair<int, int>;
using Vector = std::vector<int>;

const int maxn = 1e6 + 8;
Vector a;
int n, m;

int dfs(Pair out, Pair in, char *ans, int k = 0, int leftNeedIn = -1) {
    if (k == n - 1) return 1;
    int x;
    const int d[4] = {out.first + 1, in.first - 1, in.second + 1, out.second - 1};
    if (a[d[0]] == a[d[1]] && d[0] < d[1] && (in.first--) || a[d[0]] == a[d[2]] && (in.second++)) {
        out.first++;
        ans[k + 1] = 'L';
        x = dfs(out, in, ans, k + 1);
        if (x) return x; 
    }
    out = {d[0] - 1, d[3] + 1};
    in = {d[1] + 1, d[2] - 1};
    if (a[d[3]] == a[d[1]]) in.first--;
    else if (a[d[3]] == a[d[2]] && d[2] <= d[3]) in.second++;
    else return false;
    out.second--;
    ans[k + 1] = 'R';
    x = dfs(out, in, ans, k + 1);
    if (x) return x;
    return 0;
}

void merge(char *s) {
    Vector data;
    int l = 0, r = m - 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            data.push_back(a[l++]);
        } else {
            data.push_back(a[r--]);
        }
    }
    for (int i = n, j = i - 1; i < m; i++, j--) {
        if (data[j] == a[l]) {
            s[i] = 'L';
            l++;
        } else {
            s[i] = 'R';
            r--;
        }
    }
}

void solve() {
    char *ans = new char[maxn]();
    *ans = 'L';
    bool k;
    for (int i = 1; i < m; i++) {
        if (a[0] == a[i]) {
            k = dfs({0, m}, {i, i}, ans);
            if (k) {
                merge(ans);
                printf("%s\n", ans);
                return;
            }
        }
    }
    *ans = 'R';
    for (int i = 0; i < m - 1; i++) {
        if (a[m - 1] == a[i]) {
            k = dfs({-1, m - 1}, {i, i}, ans);
            if (k) {
                merge(ans);
                printf("%s\n", ans);
                return;
            }
        }
    }
    printf("-1\n");
}

void P7915() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        a.clear();
        m = n * 2;
        for (int i = 0; i < n * 2; i++) {
            int x;
            scanf("%d", &x);
            a.push_back(x);
        }
        solve();
    }
}

int main() {
    P7915();
    return 0;
}