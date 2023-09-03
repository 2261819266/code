#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;
long long p = 998244353;

char aa[1005][1005];
long long t, id, n, m, c, f, ans = 0, wf = 0;
long long a[1005][1005], b[1005][1005];
int ii[1005][1005];

int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	scanf("%lld%lld", &t, &id);
	while (t--) {
		scanf("%lld%lld%lld%lld", &n, &m, &c, &f);
		for (int i = 1; i <= n; i++)
		  scanf("%s", aa[i] + 1);
		for (int i = 1; i <= n; i++)
		  for (int j = 1; j <= m; j++)
		    a[i][j] = aa[i][j] - 48;
		for (int i = 1; i <= n; i++)
		  for (int j = m; j ; j--)
		    if (!a[i][j] && !a[i][j + 1] && j != m) b[i][j] = b[i][j + 1] + 1;
		for (int j = 1; j <= m; j++)
		  for (int i = n - 1; i ; i--)
		    if (a[i + 1][j]) ii[i][j] = 0;
		      else ii[i][j] = ii[i + 1][j] + 1;
		for (int j = 1; j <= m; j++) {
			long long sum[1005];
			memset(sum, 0, sizeof sum);
			sum[1] = b[1][j];
			for (int i = 2; i <= n; i++) {
			if (a[i][j]) sum[i] = 0;
			else {
				sum[i] = b[i][j] + sum[i - 1];
			}
			if ((!a[i][j]) && (!a[i - 1][j]) && (!a[i - 2][j])) {
				ans = (ans + sum[i - 2] * b[i][j]) % p;
				if (ii[i][j]) wf = (wf + (sum[i - 2] * b[i][j] * ii[i][j]) % p) % p;
			}
			}
		}
		printf("%lld %lld\n", (ans * c) % p, (wf * f) % p);
	}
}
