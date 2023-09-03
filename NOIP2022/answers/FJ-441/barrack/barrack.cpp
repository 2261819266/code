#include<bits/stdc++.h>
using namespace std ;
long long mod = 1000000007 ; 
long long C(long long n , long long m){
	long long ans = n ; 
	for(int i = n - 1 ; i >= n - m + 1 ; i--) ans *= i , ans %= mod ; 
	return ans / m % mod ; 
}
int main(){
	freopen("barrack.in" , "r" , stdin) ; 
	freopen("barrack.out" , "w" , stdout) ; 
	int n , m ; 
	cin >> n >> m ; 
	for(int i = 1 , u , v ; i <= m ; i++){
		cin >> u >> v ; 
//		add(u , v) ; 
//		add(v , u) ; 
	}
	long long ans = 1 ; 
	for(int i = 1 ; i <= m ; i++){
		ans += C(m , i) ; 
	}
	cout << ans * n % mod << endl ; 
	return 0 ; 
}
