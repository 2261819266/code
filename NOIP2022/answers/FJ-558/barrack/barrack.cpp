#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;

int n, m;

long long ksm(long long x, int y) {
	
	long long now_ans=1;
	
	while(y) {
		
		if(y&1) now_ans=now_ans*x%MOD;
		
		x=x*x%MOD;
		
		y>>=1;
		
	}
	
	return now_ans;
}

int main() {

	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	printf("%d", ((int)ksm(2, n+m)-1+MOD)%MOD);

	return 0;
}

