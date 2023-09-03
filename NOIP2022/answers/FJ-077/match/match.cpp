#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
long long t,n,Q,l,r,x,y,h;
long long ans;
long long a[1000001],b[1000001];
long long fa[1000001][31];
long long fb[1000001][31];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	//init();
	for(int i=1; i<=n; i++)
	{
		scanf("%lld",&a[i]);
		fa[i][0]=a[i];
	}
	for(int i=1; i<=n; i++)
	{
		scanf("%lld",&b[i]);
		fb[i][0]=b[i];
	}
	for(int k=1; k<=log(n)/log(2); k++)
	{
		for(int i=1; i+(1<<k)-1<=n; i++)
		{
			fa[i][k]=max(fa[i][k-1],fa[i+(1<<(k-1))][k-1]);
			fb[i][k]=max(fb[i][k-1],fb[i+(1<<(k-1))][k-1]);
		}
	}
	cin>>Q;
	while(Q--)
	{
		scanf("%lld%lld",&l,&r);
		ans=0;
		for(int p=l; p<=r; p++)
		{
			for(int q=p; q<=r; q++)
			{
				h=log(q-p+1)/log(2);
				x=max(fa[p][h],fa[q-(1<<h)+1][h]);
				y=max(fb[p][h],fb[q-(1<<h)+1][h]);
				ans+=(x*y);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
