#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 500010;

inline int read(){
	int num = 0;
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') num = num * 10 + c - '0', c = getchar();
	return num; 
}

inline int max(int a, int b){
	return a > b ? a : b;
}
inline int min(int a, int b){
	return a < b ? a : b;
}

int T, n, Q, a[N], b[N], stk[N], tp, la[N], ra[N], lb[N], rb[N];
ull ans, sum[3];

int main(){
	
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	
	T = read(), n = read();
	for(int i = 1; i <= n; i++)
		a[i] = read();
	for(int i = 1; i <= n; i++)
		b[i] = read();
	tp = 0;
	for(int i = 1; i <= n; i++){
		while(tp && a[stk[tp]] < a[i]) tp--;
		if(tp) la[i] = stk[tp] + 1;
		else la[i] = 1;
		stk[++tp] = i;
	}
	tp = 0;
	for(int i = n; i >= 1; i--){
		while(tp && a[stk[tp]] <= a[i]) tp--;
		if(tp) ra[i] = stk[tp] - 1;
		else ra[i] = n;
		stk[++tp] = i;
	}
	tp = 0;
	for(int i = 1; i <= n; i++){
		while(tp && b[stk[tp]] < b[i]) tp--;
		if(tp) lb[i] = stk[tp] + 1;
		else lb[i] = 1;
		stk[++tp] = i;
	}
	tp = 0;
	for(int i = n; i >= 1; i--){
		while(tp && b[stk[tp]] <= b[i]) tp--;
		if(tp) rb[i] = stk[tp] - 1;
		else rb[i] = n;
		stk[++tp] = i;
	}
	Q = read();
	for(int q = 1, l, r; q <= Q; q++){
		l = read(), r = read();
		sum[1] = sum[2] = ans = 0;
		for(int i = l, L, R; i <= r; i++){
			L = max(la[i], l), R = min(ra[i], r);
			sum[1] = 1llu * a[i], sum[2] = 0;
			for(int k = L, LL, RR; k <= R; k++){
				LL = max(lb[k], L), RR = min(rb[k], R);
				if(LL > i || RR < i) continue;
				if(k > i) sum[2] += 1llu * (i - LL + 1) * (RR - k + 1) * b[k];
				else sum[2] += 1llu * (k - LL + 1) * (RR - i + 1) * b[k];
			}
			ans += sum[1] * sum[2];
		}
		printf("%llu\n", ans);
	}
	
	return 0;
}
