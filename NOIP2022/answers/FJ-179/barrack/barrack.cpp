#include <cstdio>

using namespace std;

long long mod = 1e9 + 7;

int main() {
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	long long n,m,sum = 1;
	scanf("%d %d",&n,&m);
	sum = n;
	for(int i = 1;i <= m;++i){
		sum *= m;
	}
	printf("%lld",sum % mod);
	
	return 0;
}
