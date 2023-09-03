#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int N = 5e5 + 10, M = 1e6 + 10, MOD = 1e9 + 7;

int n, m;
int res = 1;

int main()
{
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++ ) res = ((long long)res * 2ll) % MOD;
	res = ((long long)(res - 1) % MOD + MOD) % MOD;
	for(int i = 1; i <= m; i ++ ) res = ((long long)res * 2ll) % MOD;
	printf("%d\n", res);
	return 0;
}
