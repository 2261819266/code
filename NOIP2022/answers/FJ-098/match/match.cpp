#include "bits/stdc++.h"
using namespace std;

int a[260001], b[260001];
int lg[260001];
unsigned long long sta[260001][20], stb[260001][20];
unsigned long long ans[3005][3005], dp[3005][3005];
int main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T, n; cin >> T >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++) cin >> b[i];
	for(int i = 1; i <= 17; i ++) lg[1<<i] = lg[1<<(i - 1)] + 1;
	for(int i = 3; i <= n; i ++) {
		if(!lg[i]) lg[i] = lg[i - 1];
	} 
	for(int i = 1; i <= n; i ++) {
		sta[i][0] = a[i]; stb[i][0] = b[i];
	}
	for(int i = 1; i <= 17; i ++) {
		for(int j = 1; j <= n; j ++) {
			sta[j][i] = max(sta[j][i - 1], sta[j + (1 << (i - 1))][i - 1]);
			stb[j][i] = max(stb[j][i - 1], stb[j + (1 << (i - 1))][i - 1]);
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = i; j <= n; j ++) {
			int len = j - i + 1;
			ans[i][j] = max(sta[i][lg[len]], sta[j - (1 << lg[len]) + 1][lg[len]]) *
						max(stb[i][lg[len]], stb[j - (1 << lg[len]) + 1][lg[len]]);
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + ans[i][j];
		}
	}
	int Q; cin >> Q;
	while(Q --) {
		int l, r; cin >> l >> r;
		cout << dp[r][r] - dp[r][l - 1] - dp[l - 1][r] + dp[l - 1][l - 1] << endl;
	}
}
