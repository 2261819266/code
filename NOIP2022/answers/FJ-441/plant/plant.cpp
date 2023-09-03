#include<bits/stdc++.h>
using namespace std ;
inline long long read(){
	long long x = 0 , f = 1 ; 
	char c = getchar() ; 
	while(c < '0' || c > '9'){
		if(c == '-') f = -1 ; 
		c = getchar() ; 
	}
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c - '0') ; 
		c = getchar() ; 
	}
	return x * f ; 
}
long long T , id , c , f , n , m , sum[1010][1010] , line[1010][1010] , tot[1010][1010] , ftot[1010][1010] ; 
char a[1010][1010] ; 
int main(){
	freopen("plant.in" , "r" , stdin) ; 
	freopen("plant.out" , "w" , stdout) ; 
	T = read() , id = read() ; 
	while(T--){
		memset(sum , 0 , sizeof(sum)) ; 
		memset(tot , 0 , sizeof(tot)) ; 
		memset(line , 0 , sizeof(line)) ; 
		memset(ftot , 0 , sizeof(ftot)) ; 
		n = read() , m = read() , c = read() , f = read() ; 
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				cin >> a[i][j] ;    
			}
		}
		for(int i = 1 ; i <= n ; i++){
			for(int j = m ; j >= 1 ; j--){
				if(a[i][j] == '0') sum[i][j] = sum[i][j + 1] + 1 ;
				else sum[i][j] = 0 ;  
			}
		}
		for(int j = 1 ; j <= m ; j++){
			for(int i = n ; i >= 1 ; i--){
				if(a[i][j] != '1') line[i][j] = line[i + 1][j] + 1 ; 
				else line[i][j] = 0 ; 
			}
		}
		for(int j = 1 ; j <= m ; j++){
			for(int i = 1 ; i <= n ; i++){
				if(a[i][j] == '0') tot[i][j] = tot[i - 1][j] + sum[i][j] ; 
				else tot[i][j] = 0 ; 			
			}
		}
		long long ans = 0 ; 
		if(c != 0){
			for(int i = 1 ; i < n - 1 ; i++){
				for(int j = 1 ; j <= m ; j++){
					if(a[i][j] == '1') continue ;
					for(int k = j - 1 ; k >= 1 ; k--){
						if(a[i][k] == '1') break ; 
						if(line[i][k] <= 1) continue ; 
						ans += tot[i + line[i][k] - 1][k] - tot[i + 1][k] - line[i][k] + 2 ; 
					} 
				}
			}
			cout << (ans % 998244353 * c % 998244353) % 998244353 << " " ; 
		}
		else cout << 0 << " " ; 
		ans = 0 ; 
		if(f != 0){
			for(int i = 1 ; i <= n ; i++){
				for(int j = 1 ; j <= m ; j++){
					sum[i][j] = (sum[i][j] - 1) * (line[i][j] - 1) ; 
				}
			}
			for(int j = 1 ; j <= m ; j++){
				for(int i = 1 ; i <= n ; i++){
					if(a[i][j] == '0') ftot[i][j] = ftot[i - 1][j] + sum[i][j] ; 
					else ftot[i][j] = 0 ; 			
				}
			}
			for(int i = 1 ; i <= n - 3 ; i++){
				for(int j = 1 ; j <= m ; j++){
					if(a[i][j] == '1') continue ;
					for(int k = j - 1 ; k >= 1 ; k--){
						if(a[i][k] == '1') break ; 
						if(line[i][k] <= 3) continue ; 
						ans += ftot[i + line[i][k] - 2][k] - ftot[i + 1][k] ; 
					} 
				}
			}
			cout << (ans % 998244353 * f % 998244353) % 998244353 << endl ; 
		}
		else cout << 0 << endl ; 
	}
	return 0 ; 
}
