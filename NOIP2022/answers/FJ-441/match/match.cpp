#include<bits/stdc++.h>
using namespace std ;
unsigned long long a[250010] , b[250010] , T , n , q , sum , ans , mod = (1 << 64) ; 
struct node{
	unsigned long long a , b ; 
}w[250010 << 4] ;
void pushup(int u){
	w[u].a = max(w[u << 1].a , w[u << 1 | 1].a) ; 
	w[u].b = max(w[u << 1].b , w[u << 1 | 1].b) ; 
}
void build(int u , int l , int r){
	if(l == r){
		w[u].a = a[l] ; 
		w[u].b = b[l] ; 
		return ; 
	}
	int mid = (l + r) >> 1 ; 
	build(u << 1 , l , mid) ; 
	build(u << 1 | 1 , mid + 1 , r) ; 
	pushup(u) ; 
}
bool inrange(int L , int R , int l , int r){
	return (L <= l) && (r <= R) ; 
}
bool outorange(int L , int R , int l , int r){
	return (r < L) || (l > R) ; 
}
node query(int u , int l , int r , int L , int R){
	if(inrange(L , R , l , r)){
		return w[u] ; 
	}
	else if(!outorange(L , R , l , r)){
		int mid = (l + r) >> 1 ;
		node ls = query(u << 1 , l , mid , L , R) , rs = query(u << 1 | 1 , mid + 1 , r , L , R) , ans ; 
		ans.a = max(ls.a , rs.a) , ans.b = max(ls.b , rs.b) ; 
		return ans ;  
	}
}
int main(){
	freopen("match.in" , "r" , stdin) ; 
	freopen("match.out" , "w" , stdout) ; 
	cin >> T >> n ; 
	for(int i = 1 ; i <= n ; i++) cin >> a[i] ; 
	for(int i = 1 ; i <= n ; i++) cin >> b[i] ; 
	build(1 , 1 , n) ; 
	cin >> q ; 
	while(q--){
		ans = 0 ; 
		int l , r ; 
		cin >> l >> r ; 
		for(int i = l ; i <= r ; i++){
			for(int j = i ; j <= r ; j++){
				node sum = query(1 , 1 , n , i , j) ; 
				ans += (sum.a % mod * sum.b % mod) % mod ; 
			}
		}
		cout << ans % mod << endl ; 
	}
	return 0 ; 
}
