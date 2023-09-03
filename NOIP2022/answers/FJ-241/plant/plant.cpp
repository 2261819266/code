#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int T, id, n, m, c, f, s[1010][1010], t[1010][1010];
bool a[1010][1010];
void Pre_deal() {
	for(int i = 1; i <= n; ++i) {
		for(int j = m; j >= 1; --j) {
			if(a[i][j] == true) s[i][j] = s[i][j + 1] + 1;
		}
	}
	for(int  j = 1; j <= m; ++j) {
		for(int i = n; i >= 1; --i) {
			if(a[i][j] == true) t[i][j] = t[i + 1][j] + 1;
		}
	}
}
long long ans1, ans2;
long long sum[1010];
void ask_C() {
	memset(sum, 0, sizeof sum);
	vector<int> q[1010];
	int l, r;
	for(int j = 1; j <= m; ++j) {
		int d;
		q[j].push_back(0);
		for(int i = 1; i <= n; ++i) {
			if(s[i][j] < 2) continue;
			q[j].push_back(i);
			d = q[j].size() - 1;
			sum[d] = sum[d - 1] + s[i][j] - 1;
		}
		q[j].push_back(mod);
		d = q[j].size() - 1;
		for(int i = 1; i <= d - 1; ++i) {
			int x = q[j][i], y;
			l = i, r = d;
			int mid;
			while(l < r) {
				mid = (l + r) / 2;
				y = q[j][mid];
				if(y - x <= t[x][j]) l = mid + 1;
				else r = mid;
			} 
			l -= 1;
			y = q[j][l];
			if(y - x <= 1) continue;
			int gg = i;
			if(q[j][i] + 1 == q[j][i + 1]) gg++;
			ans1 += ((s[x][j] - 1) * (sum[l] - sum[gg])) % mod;
			ans1 %= mod;
		}
	}
}
long long qwq;
void ask_F() {
	memset(sum, 0, sizeof sum);
	vector<int> q[1010];
	int l, r;
	for(int j = 1; j <= m; ++j) {
		int d;
		q[j].push_back(0);
		for(int i = 1; i <= n; ++i) {
			if(s[i][j] < 2 || t[i][j] <= 1) continue;
			q[j].push_back(i);
			d = q[j].size() - 1;
			sum[d] = sum[d - 1] + (s[i][j] - 1) * (t[i][j] - 1);
		}
		q[j].push_back(mod);
		d = q[j].size() - 1;
		for(int i = 1; i <= d - 1; ++i) {
			int x = q[j][i], y;
			l = i, r = d;
			int mid;
			while(l < r) {
				mid = (l + r) / 2;
				y = q[j][mid];
				if(y - x <= t[x][j]) l = mid + 1;
				else r = mid;
			} 
			l -= 1;
			y = q[j][l];
			if(y - x <= 1) continue;
			int gg = i;
			if(q[j][i] + 1 == q[j][i + 1]) gg++; 
			ans2 += ((s[x][j] - 1) * (sum[l] - sum[gg])) % mod;
			ans2 %= mod;
		}
	}
}
int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	T = read(), id = read();
	while(T) {
		memset(s, 0, sizeof s);
		memset(t, 0, sizeof t);
		T -= 1;
		n = read();
		m = read();
		c = read();
		f = read();
		char ch;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				cin >> ch;
				if(ch == '0') a[i][j] = true;
				else a[i][j] = false;
			}
		}
		Pre_deal();
		ans1 = 0, ans2 = 0;
		if(c == 1) ask_C();
		if(f == 1) ask_F();
		cout << ans1 * c << " " << ans2 * f << endl;
	}
}
