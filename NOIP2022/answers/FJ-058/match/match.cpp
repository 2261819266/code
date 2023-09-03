#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
typedef pair<int, int> PII;
typedef long long LL;

const int N = 3e5 + 10;

template<typename T>
inline void read(T &X) {
	X = 0;
	bool f = 0;
	char ch = getchar();
	while(!isdigit(ch)) {
		f |= ch == '-';
		ch = getchar();
	}
	while(isdigit(ch)) {
		X = (X * 10) + (ch ^ 48);
		ch = getchar();
	}
	X = f ? -X : X;
}

int n, id;
int a[N], b[N];
int maxa[N][20], maxb[N][20];
int p[20];

void init() {
	p[0] = 1;
	for (int i = 1; i <= 19; ++i)
		p[i] = p[i - 1] << 1;
	for (int i = 1; i <= n; ++i)
		maxa[i][0] = a[i];
	for (int i = 1; i <= n; ++i)
		maxb[i][0] = b[i];
	for (int len = 1; len <= 19; ++len)
		for (int i = 1; i + p[len] - 1 <= n; ++i) {
			maxa[i][len] = max(maxa[i][len - 1], maxa[i + p[len - 1]][len - 1]);
		}
	for (int len = 1; len <= 19; ++len)
		for (int i = 1; i + p[len] - 1 <= n; ++i) {
			
			maxb[i][len] = max(maxb[i][len - 1], maxb[i + p[len - 1]][len - 1]);
		}
}

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	read(id), read(n);
	for (int i = 1; i <= n; ++i)
		read(a[i]);
	for (int i = 1; i <= n; ++i)
		read(b[i]);
	init();
	int q, l, r;
	read(q);
	while(q --) {
		read(l);
		read(r);
		LL res = 0;
		for (int len = 1; len <= r - l + 1; ++len)
			for (int i = l; i + len - 1 <= r; ++i) {
				int j = i + len - 1, k = 19;
				while(2 * p[k] > len - 1) --k;
				++k;
				int ma = max(maxa[i][k], maxa[j + 1 - p[k]][k]),
				mb = max(maxb[i][k], maxb[j + 1 - p[k]][k]);
				res += ma * mb;
			}
		cout << res<<endl;
	}
	return 0;
}
