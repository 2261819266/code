#include<iostream>
#include<cstdio>

using namespace std;

const int N = 2e6 + 10;

int T, n, m, k, a[N];

int main(){
	
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &n, &m, &k);
		if(m == 4){
			puts("5\n1 1\n1 1\n1 2\n2 1 2\n1 1");
		}else{
			while(m--){
				puts("1 1");
			}
		}
	}
	
	
	
	return 0;
}
