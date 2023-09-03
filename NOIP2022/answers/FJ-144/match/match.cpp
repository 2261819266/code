#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 500005;
const int INF = 0x3f3f3f3f; 
typedef unsigned long long ull; 
inline int read() {
	int x = 0 , ff = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') ff = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar(); 
	}
	return x * ff;
}

int a[N] , b[N] , T , q , n;
inline void solve(int l , int r) {
	ull res = 0; 
	for(int L = l;L <= r;L++) {
		ull mx = 0 , Mx = 0;
		for(int R = L;R <= r;R++) {
			mx = max(mx , (ull)a[R]); Mx = max(Mx , (ull)b[R]); 
			res = res + mx * Mx;
		}
	} 
	printf("%llu\n" , res);
}

int main () {
	freopen("match.in" , "r" , stdin); freopen("match.out" , "w" , stdout);
	T = read(); n = read();
	if(n <= 3000) {
		for(int i = 1;i <= n;i++) a[i] = read();
		for(int i = 1;i <= n;i++) b[i] = read();
		q = read();
		while(q--) {
			int l , r; l = read(); r = read();
			solve(l , r);
		}
		return 0;
	}
}

