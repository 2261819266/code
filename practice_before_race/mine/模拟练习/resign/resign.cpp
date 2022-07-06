#include<cstdio>
const int m = 1e9 + 7;

int main() {
	freopen("resign.in","r",stdin);
//	freopen("resign.out","w",stdout);
	long long n, ans = 1;
	scanf("%lld", &n);
	for (int c = 2; c <= n; c++) {
		long long x = c * c % m * c % m;
		ans ^= x;
//		printf("%lld\n",x);
	}
	printf("%lld", ans);
}
 
