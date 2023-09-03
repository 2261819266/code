#include <cstdio>
using namespace std;
const int maxn = 1e6;
const int mod = 1e9+7;

int n, m;

long long fa(int num)
{
	long long fan = 1;
	for (int i = 1; i <= num; i ++)
	{
		fan = (fan<<1) % mod;
//		fan <<= 1;
	}
	
	return fan;
}

int main(void)
{
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
	}
	
//	printf("%lld", fa(n) * (n - 1) + 1);
	printf("%lld", ((fa(n) * (n - 1)) % mod + 1) % mod);
	
	return 0;
}
