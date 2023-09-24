#include <algorithm>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::stack;
using std::max;

bool isNumber(char c) {
    return c >= '0' && c <= '9';
}

template<typename t>
int find(vector<t> list, t x) {
    int j = 0;
    for (t i : list) {
        if (x == i) return j;
        j++;
    }
    return -1;
}

struct Sentens {
    bool func; // 1 F 2 E
    string i, x, y;
    int l, r;
    bool isx, isy;
    int O, next;

    int get(vector<string> &var) {
        char f;
        cin >> f;
        func = f == 'F';
        if (func) {
            cin >> i >> x >> y;
            for (string j : var) {
                if (i == j) return O = -1;
            }
            var.push_back(i);
            isx = isy = false;
            if (isNumber(x.front())) {
                sscanf(x.c_str(), "%d", &l);
                isx = true;
            }
            if (isNumber(y.front())) {
                sscanf(y.c_str(), "%d", &r);
                isy = true;
            }
            if (isx && isy) {
                if (l > r) return O = -3;
                return O = 0;
            }
            if (isx) {
                return O = 1;
            }
            if (isy) {
                return O = -3;
            }
            return O = 0;
        } else return O = -2;
    }

    operator bool () {
        return func;
    }
};

void ERR() {
    cout << "ERR\n";
}

void Yes() {
    cout << "Yes\n";
}

void No() {
    cout << "No\n";
}

void solve() {
    string s;
    int n, t;
    scanf("%d O(", &n);
    cin >> s;
    s.pop_back();
    if (s.size() == 1) t = 0;
    else {
        sscanf(s.c_str(), "n^%d", &t);
    }
    vector<string> var;
    vector<Sentens> a;
    stack<int> ss;
    int st = 0;
    for (int i = 0; i < n; i++) {
        Sentens x;
        int ret = x.get(var);
        if (ret == -1) {
            for (int j = i + 1; j < n; j++) {
                char ch;
                cin >> ch;
                string sss;
                if (ch == 'F') {
                    for (int k = 0; k < 3; k++) {
                        cin >> sss;
                    }
                }
            }
            return ERR();
        }
        if (ret == -2) {
            st--;
            if (st < 0) {
                for (int j = i + 1; j < n; j++) {
                    char ch;
                    cin >> ch;
                    string sss;
                    if (ch == 'F') {
                        for (int k = 0; k < 3; k++) {
                            cin >> sss;
                        }
                    }
                }
                return ERR();
            }
            var.pop_back();
            a[ss.top()].next = a.size();
            x.next = ss.top();
            ss.pop();
        }
        else st++, ss.push(a.size());
        a.push_back(x);
    }
    if (st != 0) return ERR();
    int ans = 0, now = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].O == 1) now++;
        if (a[i].O == -3) {
            i = a[i].next;
            continue;
        }
        ans = max(ans, now);
        if (a[i].O == -2 && a[a[i].next].O == 1) now--;
    }
    if (ans == t) return Yes();
    else return No();
    return;
}

void P3952() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

int main() {
    P3952();
}
