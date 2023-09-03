#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1000000007;
int n,m;
ll as1,as2;
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	ll p=1;
	for(int i=1;i<=m;i++)
		p=p*2%mod;
	as1=p*n%mod;
	p=1;
	as2=n-1;
	for(int i=3;i<=n;i++)
	{
		p=p*2%mod;
		as2=(as2+p*(n-i+1)%mod)%mod;
	}
	cout<<(as1+as2)%mod;
	return 0;
}
//1
//1
//4
//5
//1
//4
//
//1
//9
//1
//9
//8
//1
//0
//
//xzh AK NOIp
//hyx AK NOIp
//wkc AK NOIp
//jxw AK NOIp
//wk AK NOIp
//sbh AK NOIp
//cyc AK NOIp
//ycz AK NOIp
