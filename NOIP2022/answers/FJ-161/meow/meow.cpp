#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std ;
const int MAXN = 2e6 + 10 ;
int T , n , m , K , a[MAXN] , typ , c1[310] , c2[310] , cnt , st[310] , tp , fl ;
int vis[610] , pp[610] ;
struct node {
	int opt , x , y ;
	node (int optt = 0 , int xx = 0 , int yy = 0) : opt(optt) , x(xx) , y(yy) {} ;
} ans[MAXN * 2] ;
deque <int> p[310] ;
void dfs (int x) {
	if (x > m) {
		int ff = 0 ;
		for (int i = 1 ; i <= n ; i++)
			if (!p[i].empty ()) ff = 1 ;
		if (!ff) fl = 1 ;
		return ;
	}
	int las = cnt ;
	for (int i = 1 ; i <= n ; i++) {
		p[i].push_back (a[x]) ; ans[++cnt] = node (1 , i) ;
		int tt = -1 ;
		if (p[i].size () == 1) {
			for (int j = 1 ; j <= n ; j++)
				if (j != i && p[j].front () == a[x]) {
					tt = j ; p[i].pop_front () ; p[j].pop_front () ;
					ans[++cnt] = node (2 , i , j) ;
					break ;
				} 
		}
		dfs (x + 1) ; 
		if (fl) return ;
		if (~tt) p[tt].push_front (a[x]) ;
		else p[i].pop_back () ;
		cnt = las ;
	}
}
int main () {
	freopen ("meow.in" , "r" , stdin) ;
	freopen ("meow.out" , "w" , stdout) ; 
	scanf ("%d" , &T) ; typ = T % 10 ;
	while (T--) {
		scanf ("%d%d%d" , &n , &m , &K) ; cnt = 0 ; tp = 0 ;
		for (int i = 1 ; i <= K ; i++) vis[i] = 0 ;
		for (int i = 1 ; i <= m ; i++) scanf ("%d" , &a[i]) ;
		for (int i = 1 ; i < n ; i++) c1[i] = c2[i] = 0 , st[++tp] = i ;
		if (typ == 3) {
			fl = 0 ; dfs (1) ;
		}
		else {
			for (int i = 1 ; i <= m ; i++) {
				if (vis[a[i]]) {
					int x = pp[a[i]] ;
					if (!c2[x]) ans[++cnt] = node (1 , x) , c1[x] = 0 ;
					else if (c2[x] == a[i]) ans[++cnt] = node (1 , x) , c2[x] = 0 , st[++tp] = x ;
					else ans[++cnt] = node (1 , n) , ans[++cnt] = node (2 , x , n) , c1[x] = c2[x] , c2[x] = 0 , st[++tp] = x ; 
					vis[a[i]] = pp[a[i]] = 0 ;
					continue ;
				}
				int nw = st[tp] ;
				ans[++cnt] = node (1 , nw) ; vis[a[i]] = 1 ; pp[a[i]] = nw ;
				if (!c1[nw]) c1[nw] = a[i] ;
				else c2[nw] = a[i] ;
				if (c2[nw]) tp-- ;
			}
		}
		printf ("%d\n" , cnt) ;
		for (int i = 1 ; i <= cnt ; i++) {
			if (ans[i].opt == 1) printf ("1 %d\n" , ans[i].x) ;
			else printf ("2 %d %d\n" , ans[i].x , ans[i].y) ;
		}
	}
	return 0 ;
}
