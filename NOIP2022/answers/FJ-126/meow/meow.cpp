#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int T, n, m, k, a[N];
int las[N], cur[N];

template <class T>
inline void read(T &x) {
	x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while ('0' <= ch && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return ;
}

int tr1[310], tr2[310];
inline int query1(int x) {
	int res = 0;
	while (x) {
		res += tr1[x];
		x -= (x & -x);
	}
	return res;
}
inline void update1(int x, int val) {
	while (x <= n) {
		tr1[x] += val;
		x += (x & -x);
	} 
	return ;
}
inline int query2(int x) {
	int res = 0;
	while (x) {
		res += tr2[x];
		x -= (x & -x);
	}
	return res;
}
inline void update2(int x, int val) {
	while (x <= 301) {
		tr2[x] += val;
		x += (x & -x);
	} 
	return ;
}

inline int Bin1() {
	int l = 1, r = n;
	while (l < r) {
		int mid = l + r >> 1;
		if (query1(mid) < mid) r = mid;
		else l = mid + 1;
	}
	return l;
}
inline int Bin2() {
	int l = 1, r = n;
	while (l < r) {
		int mid = l + r >> 1;
		if (query2(mid) < mid) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	
	read(T);
	while (T --) {
		read(n); read(m); read(k);
		for (int i = 1; i <= m; ++ i)
			read(a[i]);
		memset(tr1, 0, sizeof tr1);
		memset(tr2, 0, sizeof tr2);
		
		for (int i = 1; i <= m; ++ i) {
			if (las[a[i]] == 0) {
				
				int tar = min(2 * Bin1() - 1, 2 * Bin2());
				las[a[i]] = tar;
				cur[tar] = a[i];
				if (tar % 2 == 0) {
					printf("1 %d\n", tar >> 1);
					update2(tar >> 1, 1);
				} else {
					printf("1 %d\n", (tar + 1) >> 1);
					update1((tar + 1) >> 1, 1);
				}
				
			} else {
				
				int tar = las[a[i]];
				if (tar % 2 == 0) {
					printf("1 %d\n", (tar >> 1));
					las[a[i]] = 0;
					cur[tar] = 0;
					update2(tar >> 1, -1);
				} else { 
					printf("1 %d\n", n);
					printf("2 %d %d\n", ((tar + 1) >> 1), n);
					if (cur[tar + 1]) {
						cur[tar] = cur[tar + 1];
						las[cur[tar + 1]] = tar;
						cur[tar + 1] = 0;
						las[a[i]] = 0;
						update2((tar + 1) >> 1, -1);
					} else {
						las[a[i]] = 0;
						cur[tar] = 0;
						update1((tar + 1) >> 1, -1);
					}
				}
			}
		}
		
	}
	return 0;
}
/*
2
2 4 2
1 2 1 2
4 12 6
1 2 3 4 5 6 1 3 2 5 4 6 

*/

