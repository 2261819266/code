#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) (ch == '-') && (f = 1);
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = (a * 10) + (ch - '0');
    f && (a = -a);
}
template <class T, class ...Y> void fr(T &a, Y &...b) { fr(a), fr(b...); }
int fr() { int a; return fr(a), a; }

const int N = 3e2, M = 2e6;

int n, m, k, flag = 0, cardtot, a[M + 10], cnt[2 * N + 10], Id[2 * N + 10];
deque<int> stk[N + 10];
struct Answer { int op, s1, s2; };
vector<Answer> ans;

void dfs(int cur) {
    // printf("cur = %d\n", cur);
    // for (int i = 1; i <= n; i++) {
    //     printf("stk[%d] : ", i);
    //     for (auto j : stk[i]) printf("%d ", j);
    //     puts("");
    // }
    if (flag) return ;
    if (cur == m + 1 && stk[1].size() == 0 && stk[2].size() == 0 && stk[3].size() == 0) return flag = 1, void();
    if (cur <= m) {
        for (int i = 1; i <= 3; i++) {
            if (stk[i].size() && stk[i].back() == a[cur]) {
                stk[i].pop_back(), ans.push_back({1, i, 0}), dfs(cur + 1);
                if (flag) return ;
                stk[i].push_back(a[cur]), ans.pop_back();
            }
            else {
                stk[i].push_back(a[cur]), ans.push_back({1, i, 0}), dfs(cur + 1);
                if (flag) return ;
                ans.pop_back(), stk[i].pop_back();
            }
            if (flag) return ;
        }
    }
        if (stk[1].size() && stk[2].size() && stk[1].front() == stk[2].front()) {
            int tmp = stk[1].front();
            stk[1].pop_back(), stk[2].pop_back(), ans.push_back({2, 1, 2}), dfs(cur);
            if (flag) return ;
            ans.pop_back(), stk[1].push_back(tmp), stk[2].push_back(tmp);
        }
        if (stk[1].size() && stk[3].size() && stk[1].front() == stk[3].front()) {
            int tmp = stk[1].front();
            stk[1].pop_back(), stk[3].pop_back(), ans.push_back({2, 1, 3}), dfs(cur);
            if (flag) return ;
            ans.pop_back(), stk[1].push_back(tmp), stk[3].push_back(tmp);
        }
        if (stk[3].size() && stk[2].size() && stk[3].front() == stk[2].front()) {
            int tmp = stk[3].front();
            stk[3].pop_back(), stk[2].pop_back(), ans.push_back({2, 3, 2}), dfs(cur);
            if (flag) return ;
            ans.pop_back(), stk[3].push_back(tmp), stk[2].push_back(tmp);
        }
}

void Push(Answer tmp) {
    int op = tmp.op, s1 = tmp.s1, s2 = tmp.s2, i;
    // printf("%d %d %d\n", tmp.op, tmp.s1, tmp.s2);
    if (op == 1) {
        i = ++cardtot;
        int id = s1;
        // printf("a[i] = %d\n", a[i]);
        if (stk[id].size() == 0) stk[id].push_back(a[i]), ans.push_back({1, id, 0});
        else if (stk[id].back() == a[i]) stk[id].pop_back(), ans.push_back({1, id, 0});
        else stk[id].push_back(a[i]), ans.push_back({1, id, 0});
    } else {
        ans.push_back(tmp);
        if (stk[s1].size() && stk[s2].size() && stk[s1].front() == stk[s2].front()) stk[s1].pop_front(), stk[s2].pop_front();
    }
}

struct OI {
    int RP, score;
} NOIP2022;

signed main() {
    NOIP2022.RP++, NOIP2022.score++;
     freopen("meow.in", "r", stdin), freopen("meow.out", "w", stdout);
    for (int _ = fr(); _--;) {
        fr(n, m, k), ans.clear(), ans.shrink_to_fit();
        for (int i = 1; i <= m; i++) fr(a[i]);
        cardtot = 0;
        if (k == 2 * n - 2) {
            for (int i = 1; i <= m; i++) {
                int id = (a[i] + 1) / 2;
                if (stk[id].size() == 0) stk[id].push_back(a[i]), ans.push_back({1, id, 0});
                else if (stk[id].back() == a[i]) stk[id].pop_back(), ans.push_back({1, id, 0});
                else if (stk[id].front() == a[i]) stk[id].pop_front(), ans.push_back({1, n, 0}), ans.push_back({2, id, n});
                else stk[id].push_back(a[i]), ans.push_back({1, id, 0});
                // for (int j = 1; j <= n; j++) {
                //     printf("stk[%d] : ", j);
                //     for (auto k : stk[j]) printf("%d ", k);
                //     puts("");
                // }
            }
            int up = ans.size();
            printf("%d\n", up);
            for (int i = 0; i < up; i++) {
                if (ans[i].op == 1) printf("%d %d\n", ans[i].op, ans[i].s1);
                else printf("%d %d %d\n", ans[i].op, ans[i].s1, ans[i].s2);
            }
        } else if (k == 3) {
            Id[1] = Id[2] = 1, Id[3] = 2;
            for (int i = 1; i <= m; i++) {
                if (a[i] == 3) {
                    int r = i, cnt1 = 0, cnt2 = 0, fst = 0;
                    while (r <= m && a[r + 1] != 3) {
                        r++;
                        if (fst == 0) fst = a[r];
                        if (a[r] == 1) cnt1++;
                        else cnt2++;
                    }
                    if (Id[1] == 1) {
                        if ((cnt1 % 2 == 0) && (cnt2 % 2 == 0)) {
                            Push({1, 2, 0});
                            for (int j = i + 1; j <= r; j++) Push({1, a[j], 0});
                            Push({1, 2, 0});
                        } else if ((cnt1 % 2 == 1) && (cnt2 % 2 == 1)) {
                            if (stk[1].size() == 0) {
                                Push({1, 2, 0});
                                for (int j = i + 1, tot1 = 0, tot2 = 0; j <= r; j++) {
                                    if (a[j] == 1) tot1++;
                                    else tot2++;
                                    if (tot2 == cnt2) Push({1, 1, 0});
                                    else Push({1, a[j], 0});
                                }
                                Push({1, 2, 0});
                            } else if (fst == 1) {
                                if (stk[1].size() == 1) {
                                    if (fst == stk[1].back()) {
                                        Push({1, 2, 0}), Push({1, 1, 0});
                                        for (int j = i + 2; j <= r; j++) Push({1, 3 - a[j], 0});
                                        Push({1, 2, 0});
                                    } else {
                                        Push({1, 1, 0});
                                        for (int j = i + 1; j <= r; j++) Push({1, a[j], 0});
                                        Push({2, 1, 2}), Push({1, 2, 0}), Push({2, 1, 2}), Id[1] = Id[2] = 2, Id[3] = 1;
                                    }
                                } else if (stk[1].size() == 2) {
                                    if (fst == stk[1].back()) {
                                        Push({1, 2, 0}), Push({1, 1, 0});
                                        for (int j = i + 2; j <= r; j++) Push({1, 3 - a[j], 0});
                                        Push({1, 2, 0});
                                    } else {
                                        Push({1, 1, 0}), Push({1, 2, 0}), Push({2, 1, 2});
                                        for (int j = i + 2; j <= r; j++) Push({1, a[j], 0});
                                        Push({1, 1, 0});
                                    }
                                }
                            } else if (fst == 2) {
                                if (stk[1].size() == 1) {
                                    if (fst == stk[1].back()) {
                                        Push({1, 2, 0}), Push({1, 1, 0});
                                        for (int j = i + 2; j <= r; j++) Push({1, a[j], 0});
                                        Push({1, 2, 0});
                                    } else {
                                        Push({1, 1, 0});
                                        for (int j = i + 1; j <= r; j++) Push({1, 3 - a[j], 0});
                                        Push({2, 1, 2}), Push({1, 2, 0}), Push({2, 1, 2}), Id[1] = Id[2] = 2, Id[3] = 1;
                                    }
                                } else if (stk[1].size() == 2) {
                                    if (fst == stk[1].back()) {
                                        Push({1, 2, 0}), Push({1, 1, 0});
                                        for (int j = i + 2; j <= r; j++) Push({1, a[j], 0});
                                        Push({1, 2, 0});
                                    } else {
                                        Push({1, 1, 0}), Push({1, 2, 0}), Push({2, 1, 2});
                                        for (int j = i + 2; j <= r; j++) Push({1, 3 - a[j], 0});
                                        Push({1, 1, 0});
                                    }
                                }
                            }
                        } else if (cnt1 % 2 == 1) {
                            Push({1, 2, 0});
                            for (int j = i + 1; j <= r; j++) Push({1, a[j], 0});
                            Push({1, 2, 0});
                        } else if (cnt2 % 2 == 1) {
                            Push({1, 2, 0});
                            for (int j = i + 1; j <= r; j++) Push({1, 3 - a[j], 0});
                            Push({1, 2, 0});
                        }
                    } else if (Id[1] == 2) {
                        if ((cnt1 % 2 == 0) && (cnt2 % 2 == 0)) {
                            Push({1, 3 - 2, 0});
                            for (int j = i + 1; j <= r; j++) Push({1, 3 - a[j], 0});
                            Push({1, 3 - 2, 0});
                        } else if ((cnt1 % 2 == 1) && (cnt2 % 2 == 1)) {
                            if (stk[1].size() == 0) {
                                Push({1, 3 - 2, 0});
                                for (int j = i + 1, tot1 = 0, tot2 = 0; j <= r; j++) {
                                    if (a[j] == 1) tot1++;
                                    else tot2++;
                                    if (tot2 == cnt2) Push({1, 3 - 1, 0});
                                    else Push({1, 3 - a[j], 0});
                                }
                                Push({1, 3 - 2, 0});
                            } else if (fst == 1) {
                                if (stk[1].size() == 1) {
                                    if (fst == stk[1].back()) {
                                        Push({1, 3 - 2, 0}), Push({1, 3 - 1, 0});
                                        for (int j = i + 2; j <= r; j++) Push({1, 3 - (3 - a[j]), 0});
                                        Push({1, 3 - 2, 0});
                                    } else {
                                        Push({1, 3 - 1, 0});
                                        for (int j = i + 1; j <= r; j++) Push({1, 3 - a[j], 0});
                                        Push({2, 1, 2}), Push({1, 3 - 2, 0}), Push({2, 1, 2}), Id[1] = Id[2] = 1, Id[3] = 2;
                                    }
                                } else if (stk[1].size() == 2) {
                                    if (fst == stk[1].back()) {
                                        Push({1, 3 - 2, 0}), Push({1, 3 - 1, 0});
                                        for (int j = i + 2; j <= r; j++) Push({1, 3 - (3 - a[j]), 0});
                                        Push({1, 3 - 2, 0});
                                    } else {
                                        Push({1, 3 - 1, 0}), Push({1, 3 - 2, 0}), Push({2, 3 - 1, 2});
                                        for (int j = i + 2; j <= r; j++) Push({1, 3 - a[j], 0});
                                        Push({1, 3 - 1, 0});
                                    }
                                }
                            } else if (fst == 2) {
                                if (stk[1].size() == 1) {
                                    if (fst == stk[1].back()) {
                                        Push({1, 3 - 2, 0}), Push({1, 3 - 1, 0});
                                        for (int j = i + 2; j <= r; j++) Push({1, 3 - a[j], 0});
                                        Push({1, 3 - 2, 0});
                                    } else {
                                        Push({1, 3 - 1, 0});
                                        for (int j = i + 1; j <= r; j++) Push({1, 3 - (3 - a[j]), 0});
                                        Push({2, 1, 2}), Push({1, 3 - 2, 0}), Push({2, 1, 2}), Id[1] = Id[2] = 2, Id[3] = 1;
                                    }
                                } else if (stk[1].size() == 2) {
                                    if (fst == stk[1].back()) {
                                        Push({1, 3 - 2, 0}), Push({1, 3 - 1, 0});
                                        for (int j = i + 2; j <= r; j++) Push({1, 3 - a[j], 0});
                                        Push({1, 3 - 2, 0});
                                    } else {
                                        Push({1, 3 - 1, 0}), Push({1, 3 - 2, 0}), Push({2, 1, 2});
                                        for (int j = i + 2; j <= r; j++) Push({1, 3 - (3 - a[j]), 0});
                                        Push({1, 3 - 1, 0});
                                    }
                                }
                            }
                        } else if (cnt1 % 2 == 1) {
                            Push({1, 3 - 2, 0});
                            for (int j = i + 1; j <= r; j++) Push({1, 3 - a[j], 0});
                            Push({1, 3 - 2, 0});
                        } else if (cnt2 % 2 == 1) {
                            Push({1, 3 - 2, 0});
                            for (int j = i + 1; j <= r; j++) Push({1, 3 - (3 - a[j]), 0});
                            Push({1, 3 - 2, 0});
                        }
                    }
                    // for (int i = 1; i <= n; i++) {
                    //     printf("stk[%d] : ", i);
                    //     for (auto j : stk[i]) printf("%d ", j);
                    //     puts("");
                    // }
                    while (stk[1].size() && stk[2].size() && stk[1].front() == stk[2].front()) Push({2, 1, 2});
                    i = r + 1;
                } else {
                    int id = Id[a[i]];
                    cardtot++;
                    if (stk[id].size() == 0) stk[id].push_back(a[i]), ans.push_back({1, id, 0});
                    else if (stk[id].back() == a[i]) stk[id].pop_back(), ans.push_back({1, id, 0});
                    else if (stk[id].front() == a[i]) stk[id].pop_front(), ans.push_back({1, Id[3], 0}), ans.push_back({2, id, Id[3]});
                    else stk[id].push_back(a[i]), ans.push_back({1, id, 0});
                }
            }
            int up = ans.size();
            printf("%d\n", up);
            for (int i = 0; i < up; i++) {
                if (ans[i].op == 1) printf("%d %d\n", ans[i].op, ans[i].s1);
                else printf("%d %d %d\n", ans[i].op, ans[i].s1, ans[i].s2);
            }
        } else if (n == 3) {
            flag = 0, dfs(1);
            int up = ans.size();
            printf("%d\n", up);
            for (int i = 0; i < up; i++) {
                if (ans[i].op == 1) printf("%d %d\n", ans[i].op, ans[i].s1);
                else printf("%d %d %d\n", ans[i].op, ans[i].s1, ans[i].s2);
            }
        }
    }
    return 0;
}
