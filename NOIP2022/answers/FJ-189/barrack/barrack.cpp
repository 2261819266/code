#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
int pw[N],ans,n,m;
signed main()
{
	int i;
	ios::sync_with_stdio(false);
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;	 
	pw[0]=1;
	if(n==1){cout<<1;return 0;}
	for(i=1;i<=n;i++)	pw[i]=pw[i-1]*2%M;
	ans=pw[n-1]*n%M;
	ans=(ans+pw[n-2]*(n*(n-1)/2)%M)%M;
	cout<<ans;
	return 0;
}
// 100 + 15 + 10 + 8 ¼Ä 
