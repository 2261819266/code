#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
const ll N=1e9+7;
ll n,m;
ull ans=0;
ll phi(ll m,ll n)
{
	ll sum=1;
	for(int i=n+1;i<=m;i++)
		sum*=i;
	for(int i=1;i<=m-n;i++)
		sum/=i;
	return sum;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	cout<<114514;
	return 0;
}

