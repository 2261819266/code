#include <istream>
#include <ostream>
#include <vector>
#include <iostream>
#include <string>

using std::string;
using std::vector;
using std::istream;
using std::ostream;

class BigInteger {
private:
    vector<int> a;
public:
    template<typename T = int>
    BigInteger(T x = 0) {
        if (!x) {
            a.assign(1, 0);
            return;
        }
        a.clear();
        while (x) {
            a.push_back(x % 10);
            x /= 10;
        }
    }

    BigInteger operator=(const string &s) {
        int k = 0;
        while (s[k] == '0' && s.length() > k + 1) k++; 
        int n = s.length() - k;
        a.assign(n, 0);
        for (int i = k; i < n; i++) {
            a[i - k] = s[n - i + k - 1] - '0';
        }
        return *this;
    }

    operator string() {
        string s;
        for (int i = a.size() - 1; i >= 0; i--) {
            s.push_back(a[i] + '0');
        }
        return s;
    }

    friend istream &operator>>(istream &in, BigInteger &x) {
        string s;
        in >> s;
        x = s;
        return in;
    }

    friend ostream &operator<<(ostream &out, BigInteger x) {
        string s = x;
        out << s;
        return out;
    }
};

using std::cin;
using std::cout;

int main() {
    BigInteger x;
    cin >> x;
    cout << x;
}