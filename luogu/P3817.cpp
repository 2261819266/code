#include <iostream>
using namespace std;
#ifdef LOCAL
const int maxn = 6;
#else
const int maxn = 2e5 + 5;
#endif
int n, x, a[maxn], b[maxn], sum;
int px(int y, int z) {
    return max(min(y, z), 0);
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    LOCALfo
#endif
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0)
            b[i - 1] = a[i] + a[i - 1];
    }
    for (int i = 1; i < n - 1; i++) {
        int c = px(a[i], max(b[i], b[i - 1]) - x);
        sum += c;
        b[i] -= c;
        b[i - 1] -= c;
    }
    sum += px(a[0], b[0] - x);
    sum += px(a[n - 1], b[n - 2] - x);
    cout << sum;
    return 0;
}
