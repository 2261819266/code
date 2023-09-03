#include<bits/stdc++.h>
using namespace std;
constexpr int maxm = 1e6 + 10, maxn = 666;
int a[maxm], T, n, m, k;
int t[maxn];
inline int read() {
	int out = 0;
	bool flag = false;
	char cc = getchar();
	while (cc < '0' || cc > '9') {
		if (cc == '-') {
			flag = true;
		}
		cc = getchar();
	}
	while (cc >= '0' && cc <= '9') {
		out = (out << 3) + (out << 1) + (cc ^ 48);
		cc = getchar();
	}
	return flag ? -out : out;
}
void work1() {
	int s1[maxm], s2[maxm], cnt = 0;
	int dep1 = 0, dep2 = 0; 
	deque<int> opr, st1;
	deque<pair<int, int>> st2;
	s1[++dep1] = a[1];
	cnt++;
	opr.push_back(1);
	st1.push_back(1);
	for (int i = 2; i <= m; i++) {
		if (a[i] == s1[dep1]) {
			s1[dep1] = 0;
			cnt++;
			opr.push_back(1);
			st1.push_back(1);
		} else if (a[i] == s2[dep2]) {
			s2[dep2] = 0;
			cnt++;
			opr.push_back(1);
			st1.push_back(2);
		} else if (dep1 == 0 && dep2 && a[i] != s2[dep2]) {
			s1[++dep1] = a[i];
			cnt++;
			opr.push_back(1);
			st1.push_back(1);
			if (s1[dep1] == s2[1]) {
				cnt++;
				opr.push_back(2);
				st2.push_back({1, 2});
			}
		} else if (dep2 == 0 && dep1 && a[i] != s1[dep1]) {
			s2[++dep2] = a[i];
			cnt++;
			opr.push_back(1);
			st1.push_back(2);
			if (s2[dep2] == s1[1]) {
				cnt++;
				opr.push_back(2);
				st2.push_back({1, 2});
			}
		} else {
			s2[++dep1] = a[i];
			cnt++;
			opr.push_back(1);
			st1.push_back(1);
		}
	}
	cout << cnt << endl;
	int t1 = 0;
	int t2 = 0;
	for (int i = 1; i <= cnt; i++) {
		cout << opr.front() << ' ';
		if (opr.front() == 1) {
			cout << st1.front() << endl;
			st1.pop_front();
		} else {
			cout << st2[++t2].first << ' ' << st2[t2].second << endl;
			st2.pop_front();
		}
		opr.pop_front();
	}
}
void work2() {
	int s1[maxm], s2[maxm], s3[maxm], cnt = 0;
	deque<int> opr, st1;
	deque<pair<int, int>> st2;
	int dep1 = 0, dep2 = 0, dep3 = 0;
	s1[++dep1] = a[1];
	cnt++;
	opr.push_back(1);
	st1.push_back(1);
	for (int i = 2; i <= m; i++) {
		if (a[i] == s1[dep1]) {
			cnt++;
			opr.push_back(1);
			st1.push_back(1);
		} else if (a[i] == s2[dep2]) {
			cnt++;
			opr.push_back(1);
			st1.push_back(2);
		} else if (a[i] == s3[dep3]) {
			cnt++;
			opr.push_back(1);
			st1.push_back(3);
		} else if (dep1 == 0 && a[i] != s2[dep2] && a[i] != s3[dep3]) {
			s1[++dep1] = a[i];
			cnt++;
			opr.push_back(1);
			st1.push_back(1);
			if (s1[1] == s2[1]) {
				cnt++;
				opr.push_back(2);
				st2.push_back({1, 2});
			} else if (s1[1] == s3[1]) {
				cnt++;
				opr.push_back(2);
				st2.push_back({1, 3});
			}
		} else if (dep2 == 0 && a[i] != s1[dep1] && a[i] != s3[dep3]) {
			s2[++dep2] = a[i];
			cnt++;
			opr.push_back(1);
			st1.push_back(2);
			if (s1[1] == s2[1]) {
				cnt++;
				opr.push_back(2);
				st2.push_back({1, 2});
			} else if (s2[1] == s3[1]) {
				cnt++;
				opr.push_back(2);
				st2.push_back({2, 3});
			}
		} else if (dep3 == 0 && a[i] != s2[dep2] && a[i] != s1[dep1]) {
			s3[++dep3] = a[i];
			cnt++;
			opr.push_back(1);
			st1.push_back(3);
			if (s2[1] == s3[1]) {
				cnt++;
				opr.push_back(2);
				st2.push_back({2, 3});
			} else if (s1[1] == s3[1]) {
				cnt++;
				opr.push_back(3);
				st2.push_back({1, 3});
			}
		} 
	}
	cout << cnt << endl;
	int t1 = 0, t2 = 0;
	for (int i = 1; i <= cnt; i++) {
		cout << opr.front() << ' ';
		if (opr.front() == 1) {
			cout << st1.front() << endl;
			st1.pop_front();
		} else {
			cout << st2[++t2].first << ' ' << st2[t2].second << endl;
			st2.pop_front();
		}
		opr.pop_front();
	}
}
int main() {
	freopen ("meow.in", "r", stdin);
	freopen ("meow.out" , "w", stdout);
	T = read();
	while (T--) {
		n = read(), m = read(), k = read();
		for (int i = 1; i <= m; i++) {
			a[i] = read();
		}
		if (n == 2)  {
			int mid = m / 2;
			bool flag = true;
			for (int i = 1; i <= mid; i++) {
				if (a[i] != a[i + mid]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << 1.5 * m << endl;
				for (int i = 1; i <= mid; i++) {
					cout << 1 << ' ' << 1 << endl;
				}
				for (int i = mid + 1; i <= m; i++) {
					cout << 1 << ' ' << 2 << endl;
					cout << 2 << ' ' << 1 << ' ' << 2 << endl;
				}
				continue;
			}
			work1();
		} else if (n == 3) {
			work2();
		} else {
			puts("Oklia");
		}
	}
	return 0;
}

