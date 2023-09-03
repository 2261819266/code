#include <string>
#include <queue>

using std::vector;
using std::string;
using std::queue;

struct ACAutomaton {
    struct Node {
        vector<int> a;
        size_t cnt;
        int fail;
        string s;
        Node () {
            a.clear();
            a.assign(26, -1);
            cnt = 0;
            fail = -1;
        }
        int &operator[](int x) {
            return a[x];
        }
    } ;
    vector<Node> a;
    static const int root = 0;
    void clear() {
        a.clear();
        a.push_back({});
    }

    ACAutomaton() {
		clear();
    }

    int add() {
        a.push_back({});
        return a.size() - 1;
    }

    void insert(const string &s) {
        int p = root;
        for (char i : s) {
            i -= 'a';
            if (!~a[p][i]) a[p][i] = add();
            p = a[p][i];
        }
        a[p].cnt++;
        a[p].s = s;
    }

    void build() {
        queue<int> q;
        int p = root;
        a[0].fail = 0;
        for (int i = 0; i < 26; i++) {
            if (~a[p][i]) {
                a[a[p][i]].fail = p;
                q.push(a[p][i]);
            } else a[p][i] = 0;
        }
        while (!q.empty()) {
            p = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (~a[p][i]) {
                    a[a[p][i]].fail = a[a[p].fail][i];
                    q.push(a[p][i]);
                } else {
                    a[p][i] = a[a[p].fail][i];
                }
            }
        }
    }

    size_t query(const string &s) const {
        vector<bool> vis(a.size(), false);
        size_t ans = 0;
        int p = root;
        for (char i : s) {
            i -= 'a';
            p = a[p].a[i];
            for (int j = p; j > root && !vis[j]; j = a[j].fail) {
                ans += a[j].cnt;
                vis[j] = true;
            }
        }
        return ans;
    }

    vector<size_t> query_times(const string &s) const {
        vector<size_t> t;
        int p = root;
        for (char i : s) {
            i -= 'a';
            p = a[p].a[i];
            for (int j = p;j > root; j = a[j].fail) {
                t[j] += a[j].cnt;
            }
        }
        return t;
    }

    std::pair<size_t, vector<string>> find_max(const vector<size_t> t) {
        int max_id;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] > t[max_id]) max_id = i;
        }
        vector<string> args;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == t[max_id])
                args.push_back(a[i].s);
        }
        return {t[max_id], args};
    }

    void print_string_list(const vector<string> &args) {
        for (string i : args) {
            printf("%s\n", i.c_str());
        }
    }
} a;

size_t solve(const string t, const vector<string> &s) {
    a.clear();
    for (string i : s) {
        a.insert(i);
    }
    a.build();
    return a.query(t);
}

void solve_get_max_times(const string t, const vector<string> &s) {
    a.clear();
    for (string i : s) {
        a.insert(i);
    }
    a.build();
    vector<size_t> times = a.query_times(t);
    std::pair<size_t, vector<string>> x = a.find_max(times);
    printf("%llu\n", x.first);
    a.print_string_list(x.second);
}

