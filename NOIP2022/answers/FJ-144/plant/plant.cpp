#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
#define int long long
const int Mod = 998244353;
const int N = 1005;
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

bool st;
int r[N][N] , a[N][N] , d[N][N] , D[N][N] , Dd[N][N] , T , id , resc , resf , n , m , c , f;
char s[N]; 
bool ed;
inline int Add(int x , int y) {return x + y >= Mod ? x + y - Mod : x + y;}
inline int Dec(int x , int y) {return x < y ? x - y + Mod : x - y;}
inline int power(int x , int y) {
	int res = 1;
	for(;y;y >>= 1) {
		if(y & 1) res = res * x % Mod;
		x = x * x % Mod;
	}
	return res;
}

inline int inv(int x) {return power(x , Mod - 2) % Mod;}
signed main () {
	freopen("plant.in" , "r" , stdin); freopen("plant.out" , "w" , stdout);
//	cerr << (&st - &ed) / 1048576.0 << "MB" << endl; 
	T = read(); id = read();
	while(T--) {
		n = read(); m = read(); c = read(); f = read();	resc = resf = 0;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) r[i][j] = d[i][j] = D[i][j] = 0;
		}
		for(int i = 1;i <= n;i++) {
			scanf("%s" , s + 1);
			for(int j = 1;j <= m;j++) a[i][j] = s[j] - '0';
		}
		for(int i = 1;i <= n;i++) {
			for(int j = m;j >= 1;j--) {
				if(a[i][j]) r[i][j] = 0;
				else {
					if(j == m || (a[i][j + 1] == 1)) r[i][j] = 1;
					else r[i][j] = r[i][j + 1] + 1;
				}
			}
		}
		for(int j = 1;j <= m;j++) {
			for(int i = n;i >= 1;i--) {
				if(a[i][j]) d[i][j] = 0;
				else {
					if(i == n || a[i + 1][j] == 1) d[i][j] = 1 , D[i][j] = 0;
					else {
						d[i][j] = d[i + 1][j] + 1;
						if(r[i + 1][j] > 1) {
							D[i][j] = Add(D[i + 1][j] , (r[i + 1][j] - 1));
							Dd[i][j] = Add(Dd[i + 1][j] , (r[i + 1][j] - 1) * (d[i + 1][j] - 1) % Mod);
						}
						else D[i][j] = D[i + 1][j] , Dd[i][j] = Dd[i + 1][j];
					}
				}
			}
		}
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				if(a[i][j]) continue; if(d[i][j] <= 2) continue;
				if(r[i][j] < 2) continue;  
				int nw = D[i][j] , Nw = Dd[i][j]; 
				if(r[i + 1][j] > 1) nw = Dec(nw , (r[i + 1][j] - 1)) , Nw = Dec(Nw , (r[i + 1][j] - 1) * (d[i + 1][j] - 1) % Mod);
				nw = (r[i][j] - 1) * nw % Mod; Nw = (r[i][j] - 1) * Nw % Mod; 
				resc = Add(resc , nw); resf = Add(resf , Nw);
			}
		}
		if(c) printf("%lld " , resc); else {putchar('0'); putchar(' ');}
		if(f) printf("%lld\n" , resf); else {putchar('0'); puts("");}
	}
	return 0;
} 
