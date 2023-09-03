#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
int a[N], b[N], st1[N][21], st2[N][21];
int t, n;
typedef unsigned long long LL;


int query(int op, int l, int r){
    int k = log(r - l + 1) / log(2);
	if(op == 1){
		return max(st1[l][k], st1[r - (1 << k) + 1][k]);
	}else{
		return max(st2[l][k], st2[r - (1 << k) + 1][k]);
	}
}

int main(){
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%d%d", &t, &n);
	for(int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++ i) scanf("%d", &b[i]);
	if((t >= 1 && t <= 9) || (t >= 14 && t <= 17) || (t == 0)){
		int k = log(n)/log(2) + 1;
		for(int i = 1; i <= n; ++ i){
			st1[i][0] = a[i];
			st2[i][0] = b[i];
		}
		for(int i = 1; i <= k; ++ i){
			for(int j = 1; j + (1 << i) - 1 <= n; ++ j){
				st1[j][i] = max(st1[j][i - 1], st1[j + (1 << (i - 1))][i - 1]);
				st2[j][i] = max(st2[j][i - 1], st2[j + (1 << (i - 1))][i - 1]);
			}
		}
		
		int q, l, r;
		scanf("%d", &q);
		LL ans1 = 0;
		while(q --){
			scanf("%d%d", &l, &r);
			ans1 = 0;
			for(int p = l; p <= r; ++ p){
				for(int q = p; q <= r; ++ q){
					int a = query(1, p, q);
					int b = query(2, p, q);
					ans1 += a * b;
				}
			}
			printf("%lld\n", ans1);
		}
		
	}
	return 0;
}

