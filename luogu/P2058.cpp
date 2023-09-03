#include <cstdio>
#include <vector>
#include <queue>

const int maxn = 3e5 + 8, DayTime = 86400;
struct Ship {
    int t;
    std::vector<int> v;
    int size() const {
        return v.size();
    }

    void push_back(int x) {
        v.push_back(x);
    }

    operator int() const {
        return t;
    }

    auto begin() const { return v.begin(); }

    auto end() const { return v.end(); }
} ;
std::queue<Ship> q;
int t[maxn], ans;

void P2058() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int n;
        Ship s;
        scanf("%d%d", &s.t, &n);
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            s.push_back(x);
            if (!t[x]) ans++;
            t[x]++;
        }
        q.push(s);
        while (q.front() <= q.back() - DayTime) {
            for (auto j : q.front()) {
                t[j]--;
                if (!t[j]) ans--;
            }
            q.pop();
        }
        printf("%d\n", ans);
    }
}


int main() {
#ifdef LOCAL
    LOCALfo
#endif
    P2058();
    return 0;
}