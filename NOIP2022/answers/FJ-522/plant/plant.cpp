#include<bits/stdc++.h>
using namespace std;
int T, id;
int n, m, c, f;
long long ans = 0, sum = 0, pos = 0;
int Map[1005][1005];
int a[1005][1005], b[1005][1005];
long long dp[1005][1005];

void init(){
	for(int i = n; i >= 1; i --)
		for(int j = m; j >= 1; j --){
			if(Map[i][j]) a[i][j] = -1, b[i][j] = -1;
			else a[i][j] = j == m ? 0 : a[i][j + 1] + 1,
			     b[i][j] = i == n ? 0 : b[i + 1][j] + 1;
		}
}

int main(){
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	scanf("%d%d", &T, &id);
	while(T --){
		scanf("%d%d%d%d", &n, &m, &c, &f);
		if(c == 0 && f == 0) cout << 0 << ' ' << 0;
		for(int i = 1; i <= n; i ++){
			string s;
			cin >> s;
			for(int j = 1; j <= m; j ++)
				Map[i][j] = s[j - 1] - '0';
		}
		init();
		for(int i = 1; i <= n - 2; i ++){
			for(int j = 1, k = i + 1, fr = 0; j < m; j ++){
				pos = 0;
				if(Map[i][j] || Map[i + 1][j] || Map[i][j + 1])
					continue;
				for(int k = i + 2; k <= n && !Map[k][j]; k ++){
					dp[i][j] += a[k][j];
					pos += (dp[i][j] - fr) * b[k][j];
					fr = dp[i][j];
				}
				ans += dp[i][j] * a[i][j];
				sum += pos * a[i][j];
			}
		}
		cout << ans * c % 998244353 << ' ' << sum * f % 998244353 << endl;
	}
	
	return 0;
}	
/*
1 0
4 3 1 1
001
010
000
000

1 0
6 6 1 1
000010
011000
000110
010000
011000
000000

52ccf(qaq
*/
