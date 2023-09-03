#include<bits/stdc++.h>

#define rep(i,j,k) for(int i=j;i<=k;i++)
#define drp(i,j,k) for(int i=j;i>=k;i--)

using namespace std;
const long long N=3e5+100;
int T,n,a[N],b[N],fa[N][30],fb[N][30],q,l,r;
unsigned long long ans;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	
	scanf("%d%d",&T,&n);
	rep(i,1,n) 
	{
		scanf("%d",&a[i]);
		fa[i][0]=a[i];
	}
	rep(i,1,n)
	{
		scanf("%d",&b[i]);
		fb[i][0]=b[i];
	}
	rep(i,1,log(n)/log(2))
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			fa[j][i]=max(fa[j][i-1],fa[j+(1<<(i-1))][i-1]);
			fb[j][i]=max(fb[j][i-1],fb[j+(1<<(i-1))][i-1]);
		}
		
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		ans=0;
		rep(i,l,r)
			rep(j,i,r)
			{
				int k=log(j-i+1)/log(2);
				ans=(ans+(unsigned long long)max(fa[i][k],fa[j-(1<<k)+1][k])*(unsigned long long)max(fb[i][k],fb[j-(1<<k)+1][k]));
			}
		printf("%lld\n",ans);
	}
	
	return 0;
} 
