#include <iostream>
#include <vector>

const int M = 998244353;

#define ll long long 

ll pow(ll x, ll y) {
    if (!y) return 1;
    ll z = pow(x, y / 2) % M;
    return ((y % 2) * x * z % M) * z % M;
}

using std::vector;
using std::cout;
using std::cin;

const int maxn = 1e4 + 1;

vector<int> i2z, z2i(maxn, -1);

void init() {
    for (int i = 2; i < maxn; i++) {
        int k = false;
        for (int j = 2; j * j <= i && !k; j++) {
            if (i % j == 0) k = true;
        }
        if (!k) {
            z2i[i] = i2z.size();
            i2z.push_back(i);
        }
    }
    // for (int i : i2z) {
    //     cout << i << "\n";
    // }
}

struct Data {
    vector<int> a;
    void init() { a.assign(i2z.size(), 0); }

    Data operator=(int x) {
        init();
        for (int i : i2z) {
            if (z2i[x] >= 0) {
                a[z2i[x]]++;
                return *this;
            }
            while (x % i == 0) {
                a[z2i[i]]++;
                x /= i;
            }
            if (x == 1) return *this;
        }
        return *this;
    }

    Data(int x) { *this = x; }

    ll operator*() {
        ll ans = 1;
        for (int i : a) {
            ans *= i + 1;
            ans %= M;
        }
        return ans;
    }

    int &operator[](int x) { return a[x]; }

    Data operator*=(int x) {
        if (z2i[x] < 0) return -1;
        a[z2i[x]]++;
        return *this;
    }
};

void T392400() {
    int n, w;
    cin >> n >> w;
    vector<Data> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    Data x = w;
    for (int i = 0; i < x.a.size(); i++) {
        int u = x[i];
        for (int j = 0; j < u; j++) {
            int id = 0;
            for (int k = 1; k < a.size(); k++) {
                if (a[k][i] < a[id][i]) id = k;
            }
            a[id][i]++;
        }
    }

    ll ans = 1;
    for (Data i : a) {
        ans = ans * *i % M;
    }
    cout << ans;
}

int main() {
    init();
    T392400();
    return 0;
}