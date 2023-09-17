#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;
using std::max;
using std::min;

bool St;

int f1(const vector<int> &a) {
    int n = a.size();
    vector<int> f(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    return f[n - 1];
}

int f2(const vector<int> &a) {
    int n = a.size();
    vector<int> f(n, 1);
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[i]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    return f[0];
}

vector<int> a;
void P1091() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    
    for (int i = 0; i < n; i++) {
        vector<int> x(a.begin(), a.begin() + i + 1), y(a.begin() + i, a.end());
        ans = max(ans, f1(x) + f2(y) - 1);
    }

    cout << n - ans << endl;
}

bool Ed;

int main() {
	cerr << (double)std::abs(&Ed - &St) / 1024.0 / 1024.0 << "Mb\n";
    P1091();
	cerr << "\n" << double(clock()) / CLOCKS_PER_SEC << "s\n";
    return 0;
}

