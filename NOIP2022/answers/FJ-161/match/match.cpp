#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
const int MAXN = 3e5 + 10 ;
typedef unsigned long long ull ;
int T , n , q , a[MAXN] , b[MAXN] , st[MAXN] , tp ;
int la[MAXN] , ra[MAXN] , lb[MAXN] , rb[MAXN] ;
int main () {
	freopen ("match.in" , "r" , stdin) ;
	freopen ("match.out" , "w" , stdout) ;
	scanf ("%d%d" , &T , &n) ;
	for (int i = 1 ; i <= n ; i++) scanf ("%d" , &a[i]) ;
	for (int i = 1 ; i <= n ; i++) scanf ("%d" , &b[i]) ;
	scanf ("%d" , &q) ;
	while (q--) {
		int x , y ; scanf ("%d%d" , &x , &y) ; ull ans = 0 ;
		tp = 0 ;
		for (int i = x ; i <= y ; i++) {
			for (; tp && a[i] > a[st[tp]] ; tp--) ;
			la[i] = tp ? st[tp] : x - 1 ; st[++tp] = i ;
		}
		tp = 0 ;
		for (int i = y ; i >= x ; i--) {
			for (; tp && a[i] > a[st[tp]] ; tp--) ;
			ra[i] = tp ? st[tp] : y + 1 ; st[++tp] = i ;
		}
		tp = 0 ;
		for (int i = x ; i <= y ; i++) {
			for (; tp && b[i] > b[st[tp]] ; tp--) ;
			lb[i] = tp ? st[tp] : x - 1 ; st[++tp] = i ;
		}
		tp = 0 ;
		for (int i = y ; i >= x ; i--) {
			for (; tp && b[i] > b[st[tp]] ; tp--) ;
			rb[i] = tp ? st[tp] : y + 1 ; st[++tp] = i ;
		}
		for (int i = x ; i <= y ; i++)
			for (int j = x ; j <= y ; j++) {
				int t1 = max (la[i] , lb[j]) , t2 = min (ra[i] , rb[j]) ;	
				//printf ("%d %d:%d %d\n" , i , j , t1 , t2) ;
				if (t1 >= min (i , j) || t2 <= max (i , j)) continue ;
				ans += (ull)a[i] * b[j] * (min (i , j) - t1) * (t2 - max (i , j)) ;
			}
				
		printf ("%llu\n" , ans) ;
	}
	return 0 ;
}
