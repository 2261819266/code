#include <iostream>
#include <queue>
#include <vector>

// using std::cin;
using std::cout;
using std::cerr;
typedef long long ll;
bool St;

template<typename t>
inline void read(t& a) {
	t s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch>'9')
	{
		if (ch == '-')
			w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	a = s * w;
}

void print(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int maxn = 1e5 + 5;
std::vector<ll> a(maxn, 0);
std::queue<ll> q, p;




void P6033() {
    int n;
    read(n);
    for (int i = 0; i < n; i++) {
        int x;
        read(x);
        // scanf("%d", &x);
        // cin >> x;
        a[x]++;
    }
    ll ans = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i]; j++) {
            q.push(i);
        }
    }
    for (int i = 1; i < n; i++) {
        ll u, v;
        if (p.empty() || (!q.empty() && p.front() > q.front())) {
            u = q.front();
            q.pop();
        } else {
            u = p.front();
            p.pop();
        }
        if (p.empty() || (!q.empty() && p.front() > q.front())) {
            v = q.front();
            q.pop();
        } else {
            v = p.front();
            p.pop();
        }
        p.push(u + v);
        ans += u + v;
    }
    cout << ans << "\n";
}

bool Ed;

int main() {
	cerr << (double)std::abs(&Ed - &St) / 1024.0 / 1024.0 << "Mb\n";
    // std::ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    P6033();
	cerr << "\n" << double(clock()) / CLOCKS_PER_SEC << "s\n";
}
