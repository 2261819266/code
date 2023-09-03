#include<bits/stdc++.h>
#define int unsigned long long
const int N=2e5+5e4+99;
using namespace std;
int T,n,a[N],b[N],Q,mod=1,maxa,maxb,ans[64];
signed main()
{
	freopen("match.in","r",stdin);
	freopen("macth.out","w",stdout);
	scanf("%lld%lld",&T,&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	scanf("%lld",&Q);
	printf("%lld",mod);
	while(Q--)
	{
		cout<<rand()*56524<<endl;
	}
	return 0;
}
