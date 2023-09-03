#include<bits/stdc++.h>
using namespace std;

const int N = 2.5e5 + 5;
typedef unsigned long long ULL;

int a[N], b[N];

int main(){
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	
	int T, n;
	scanf("%d%d", &T, &n);
	
	for(int i = 1; i <= n; i ++)scanf("%d", &a[i]);
	for(int i = 1; i <= n; i ++)scanf("%d", &b[i]);
	
	int q;
	scanf("%d", &q);
	
	for(int i = 1; i <= q; i ++){
		int l, r;
		scanf("%d%d", &l, &r);
		ULL ans = 0;
		for(int i = l; i <= r; i ++){
			ULL maxa = 0, maxb = 0;
			for(int j = i; j <= r; j ++){
				maxa = max(maxa, (ULL)a[j]);
				maxb = max(maxb, (ULL)b[j]);
				ans += maxa * maxb;
			}
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
