#include <cstdio>
#include <cmath>
#include <algorithm>

const char str[2][10] = {"No", "Yes"};
int ans = 0;
bool dp[100][20][10000];

// void dfs(int m, int s, int t) {

// }

bool f(int m, int s, int t) {
    bool k = false;
    int x = std::min(m / 10, t);
    s -= x * 60;
    m -= x * 10;
    t -= x;
    if (t == 0 && s) return false;
    switch (m) {
        case 2: s -= 60, t -= 3; break;
        case 4: s -= 120, t -= 6; break;
        case 6: s -= 60, t -= 2; break;
        case 8: s -= 120, t -= 5; break;
    }
    s -= 120 * (t / 7);
    t %= 7;
    s -= 17 * t;
    return s <= 0;
}

int f0(int m, int t) {
    int ans = 0;
    int x = std::min(m / 10, t);
    ans += x * 60;
    m -= x * 10;
    t -= x;
    switch (m) {
        case 2: ans += 60, t -= 3; break;
        case 4: ans += 120, t -= 6; break;
        case 6: ans += 60, t -= 2; break;
        case 8: ans += 120, t -= 5; break;
    }
    ans += t / 7 * 120;
    t %= 7;
    ans += 17 * t;
    return ans;
}

int f1(int m, int s) {
    bool k = false;
    int x = std::min(m / 10, s / 60);
    s -= x * 60;
    m -= x * 10;
    ans += x;
    if (s <= 17) return ans + 1;
    if (s <= 34) return ans + 2;
    if (m >= 6) m -= 6, ans += 2, s -= 60;
    if (s <= 17) return ans + 1;
    if (s <= 34) return ans + 2;
    if (s <= 51) return ans + 3;
    if (m >= 2) m -= 2, ans += 3, s -= 60;
    if (s <= 17) return ans + 1;
    if (s <= 34) return ans + 2;
    if (s <= 51) return ans + 3;
    if (m >= 2) m -= 2, ans += 3, s -= 60;
    // switch (m) {
    //     case 2: s -= 60, ans += 3; break;
    //     case 4: s -= 120, ans += 6; break;
    //     case 6: s -= 60, ans += 2; break;
    //     case 8: s -= 120, ans += 5; break;
    // }
    ans += s / 120 * 7;
    s %= 120;
    ans += ceil(s / 17.0);
    return ans;
}

void P1095() {
    int m, s, t;
    bool k = false;
    scanf("%d%d%d", &m, &s, &t);
    m -= m % 2;
    int x = std::min(m / 10, t);
    if (x * 60 >= s) {
        ans = ceil(s / 60.0);
        k = true;
        // return;
    }
    else {
        k = f(m, s, t);
        if (!k) ans = f0(m, t);
        else ans = f1(m, s);
    }
    printf("%s\n%d", str[k], ans);
}


int main() {
#ifdef LOCAL
    LOCALfo
#endif
    P1095();
    return 0;
}