#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<ctime>

using namespace std;

const int N = 1e4 + 10;

int t, n, Q;
int a[N], b[N], pow[50], lg[N];
long long fa[N][50], fb[N][50];

int main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	
	/*for (int i = 2; i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				cout << i << " ";
				n /= i;
			}
		}
	}*/
	scanf("%d%d", &t, &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	
	pow[0] = 1;
	lg[1] = 0;
	
	for (int i = 1; i <= 30; i++) pow[i] = 2 * pow[i - 1];
	for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
	
	for (int i = 1; i <= n; i++) fa[i][0] = a[i];
	for (int i = 1; i <= n; i++) fb[i][0] = b[i];
	
	for (int i = 1; pow[i] <= n; i++) {
		int len = pow[i - 1];
		for (int l = 1; l + len - 1 <= n; l++) {
			fa[l][i] = max(fa[l][i - 1], fa[l + len][i - 1]);
		}
	}
	
	for (int i = 1; pow[i] <= n; i++) {
		int len = pow[i - 1];
		for (int l = 1; l + len - 1 <= n; l++) {
			fb[l][i] = max(fb[l][i - 1], fb[l + len][i - 1]);
		}
	}
	
	scanf("%d", &Q);
	while (Q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		unsigned long long res = 0;
		
		for (int p = l; p <= r; p++) {
			for (int q = p; q <= r; q++) {
				int len = lg[q - p + 1];
				long long maxa = max(fa[p][len], fa[q - pow[len] + 1][len]);
				long long maxb = max(fb[p][len], fb[q - pow[len] + 1][len]);
				res += maxa * maxb;
			}
		}
		
		cout << res << endl;
	}
	return 0;
}
