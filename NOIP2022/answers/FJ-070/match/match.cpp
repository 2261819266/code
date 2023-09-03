#include <bits/stdc++.h>

using namespace std;

const int N1 = 3000 + 5;
const int N = 250000 + 10;

int read() {
	int num = 0;
	char ch = getchar();
	while (!isdigit(ch)) {
		ch = getchar();
	}
	while (isdigit(ch)) {
		num = (num << 1) + (num << 3) + (ch - '0');
		ch = getchar();
	}
	return num;
}

int T, n, Q;
int a[N], b[N];
int apre[N], anxt[N], bpre[N], bnxt[N];
int am[N1][N1], bm[N1][N1];
unsigned long long sum[N1][N1];
stack<int> st;

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%d%d", &T, &n);
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		b[i] = read();
	}
	if (n <= 30) {
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				for (int k = i; k <= j; k++) {
					am[i][j] = max(am[i][j], a[k]);
					bm[i][j] = max(bm[i][j], b[k]);
				}
			}
		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				cout << am[i][j] << "\t";
//			}
//			cout << endl;
//		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				cout << bm[i][j] << "\t";
//			}
//			cout << endl;
//		}
		scanf("%d", &T);
		while (T--) {
			int l, r;
			scanf("%d%d", &l, &r);
			unsigned long long ans = 0llu;
			for (int i = l ; i <= r; i++) {
				for (int j = i; j <= r; j++) {
					ans = ans + 1llu * am[i][j] * bm[i][j];
				}
			}
			printf("%llu\n", ans);
		}
	} else {
		while (!st.empty()) st.pop();
		for (int i = 1; i <= n; i++) {
			anxt[i] = n;
		}
		st.push(1);
		for (int i = 2; i <= n; i++) {
			while (!st.empty() && a[st.top()] < a[i]) {
				anxt[st.top()] = i - 1;
				st.pop();
			}
			st.push(i);
		}
		
		while (!st.empty()) st.pop();
		for (int i = 1; i <= n; i++) {
			apre[i] = 1;
		}
		st.push(n);
		for (int i = n - 1; i >= 1; i--) {
			while (!st.empty() && a[st.top()] < a[i]) {
				apre[st.top()] = i + 1;
				st.pop();
			}
			st.push(i);
		}
		while (!st.empty()) st.pop();
		for (int i = 1; i <= n; i++) {
			bnxt[i] = n;
		}
		st.push(1);
		for (int i = 2; i <= n; i++) {
			while (!st.empty() && b[st.top()] < b[i]) {
				bnxt[st.top()] = i - 1;
				st.pop();
			}
			st.push(i);
		}
		
		while (!st.empty()) st.pop();
		for (int i = 1; i <= n; i++) {
			bpre[i] = 1;
		}
		st.push(n);
		for (int i = n - 1; i >= 1; i--) {
			while (!st.empty() && b[st.top()] < b[i]) {
				bpre[st.top()] = i + 1;
				st.pop();
			}
			st.push(i);
		}
//		(pre[i], i) -> (i, nxt[i])
//		for (int i = 1; i <= n; i++) {
//			cout << apre[i] << "," << i << " " << i << "," << anxt[i] << endl;
//		}
//		for (int i = 1; i <= n; i++) {
//			cout << bpre[i] << "," << i << " " << i << "," << bnxt[i] << endl;
//		}
		for (int u = 1; u <= n; u++) {
			for (int i = apre[u]; i <= u; i++) {
				for (int j = u; j <= anxt[u]; j++) {
					am[i][j] = a[u];
				}
			}
		}
		for (int u = 1; u <= n; u++) {
			for (int i = bpre[u]; i <= u; i++) {
				for (int j = u; j <= bnxt[u]; j++) {
					bm[i][j] = b[u];
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + 1llu * am[i][j] * bm[i][j];
			}
		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				cout << am[i][j] << "\t";
//			}
//			cout << endl;
//		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				cout << bm[i][j] << "\t";
//			}
//			cout << endl;
//		}
		scanf("%d", &T);
		while (T--) {
			int l, r;
			scanf("%d%d", &l, &r);
			unsigned long long ans = sum[r][r] - sum[r][l - 1] - sum[l - 1][r] + sum[l - 1][l - 1];
			printf("%llu\n", ans);
		}
	}
	return 0;
}
