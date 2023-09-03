#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rint register int
const int p=1000000007;
ll power(ll a,ll b){
	ll c=1;
	for(;b;b>>=1){
		if(b&1)c=c%p*a%p;
		a=c%p*a%p;
	}
	return c%p;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=10;i++)cout<<power(2,i)<<endl;
	return 0;
}

