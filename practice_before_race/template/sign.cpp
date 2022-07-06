#include <bits/stdc++.h>
using namespace std ;
#define Lowbit(X) ((X)&-(X))
int main() {
    //freopen( "sign.in" , "r" , stdin ) ;
	//freopen( "sign.out" , "w" , stdout ) ;
	int T ; 
	scanf( "%d" , &T ) ; 
	while( T-- ) 
	{
		int N ; 
		scanf( "%d" , &N ) ;
		while( N != Lowbit(N) ) 
		   N ^= Lowbit(N) ;
		printf( "%d\n" , N - 1 ) ;
	}
	return 0 ;
}
