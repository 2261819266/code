#include <bits/stdc++.h>
using namespace std;
long long n,m,s;
long long MOD=1000000007;
int main() {
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin >> n >> m;
	for (int num=1;num<=n;num++) {
		s+=(long long)(pow(2,num))%MOD*(long long)(pow(2,m-num+1))%MOD;
		s%=MOD;
	}
	cout << s;
	return 0;
}

