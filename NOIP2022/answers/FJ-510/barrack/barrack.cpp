//noip rp+++++;
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
long long ans;

int main(void){
	//I love luogu.
	//NOIP rp++
	freopen("barrack.in" , "r" , stdin);
	freopen("barrack.out" , "w" , stdout);
	srand(time(0));
	ans = (long long)(rand()) * (long long)(rand()) % MOD * (long long)(rand()) % MOD;
	printf("%lld" , ans);
	return 0;
	//chm_qwq = dalao.
}