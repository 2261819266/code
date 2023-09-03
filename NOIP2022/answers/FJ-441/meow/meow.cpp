#include<bits/stdc++.h>
using namespace std ;
int T , n , m , k , st[310] , top[310] , bot[310] , cnt , flg , a[310] , emp[310] ;
struct node{
	int op , l , r ;
}o[3010] ;
void dfs(int dep , int sum){
	if(flg) return ;
	if(dep == m || sum == 0){
		if(sum == 0){
			for(int i = 1 ; i <= cnt ; i++){
				if(o[i].op == 1) cout << o[i].op << " " << o[i].l << endl ; 
				else cout << o[i].op << " " << o[i].l << " " << o[i].r << endl ; 
			}
			flg = 1 ;
		}
		return ; 
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = i + 1 ; j <= n ; j++){
			if(st[bot[i]] == st[bot[j]] && emp[i] && emp[j]){
				if(bot[i] == top[i]) emp[i] = 0 ; 
				if(bot[j] == top[j]) emp[j] = 0 ; 
				bot[i]++ , bot[j]++ ; 
				o[++cnt].op = 2 , o[cnt].l = i , o[cnt].r = j ; 
				dfs(dep , sum - 2) ; 
				bot[i]-- , bot[j]-- ; 
				cnt-- ; 
				emp[i] = 1 , emp[j] = 1 ; 
			}
		}
	}
	for(int i = 1 ; i <= n ; i++){
		if(st[top[i]] == a[dep]){
			a[top[i]--] = 0 ;
			emp[i] = 1 ; 
			o[++cnt].op = 1 , o[cnt].l = i ;
			dfs(dep + 1 , sum - 2) ;
			top[i]++ ;  
			emp[i] = 0 ;
		}
		else{
			st[++top[i]] = a[dep] ;
			emp[i] = 1 ; 
			o[++cnt].op = 1 , o[cnt].l = i ;
			dfs(dep + 1 , sum) ;
			emp[i] = 0 ;  
			st[top[i]--] = 0 ; 
		}
		cnt-- ; 
	}
	
	return ;
} 
int main(){
	freopen("meow.in" , "r" , stdin) ; 
	freopen("meow.out" , "w" , stdout) ; 
	cin >> T ; 
	while(T--){
		flg = 0 ; 
		cin >> n >> m >> k ;
		for(int i = 1 ; i <= m ; i++){
			cin >> a[i] ; 
		}
		dfs(1 , m) ; 
	}
	return 0 ; 
}
