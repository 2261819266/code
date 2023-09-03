#include <cstdio>
#include <iostream>
using namespace std;
const int N=5e5+1,M=1e6+1,mod=1e9+7;
int n,m; 
int main(){
	freopen ("barrack.in","r",stdin);
	freopen ("barrack.out","w",stdout);
	scanf ("%d%d",&n,&m);
	register long long sum=0,i;
	if (m==n-1){
		for (i=1;i<=n;++i)sum=(sum+i*(1+i)*(n-i+1)/2)%mod;
		cout <<sum;
	}
	return 0;
}
