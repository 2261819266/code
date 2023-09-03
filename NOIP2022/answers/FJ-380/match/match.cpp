#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
typedef unsigned long long ll;
int T,n,q;
ll f[N][20][2],ans;
ll ask(int l,int r,int num)
{
	int k=(int)(log(r-l+1)/log(2));
	return max(f[l][k][num],f[r-(1<<k)+1][k][num]);
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++) scanf("%llu",&f[i][0][0]);
	for(int i=1;i<=n;i++) scanf("%llu",&f[i][0][1]);
	int t=(int)(log(n)/log(2));
	for(int j=1;j<=t;j++)
	{
		for(int i=1;i<=n-(1<<j)+1;i++)
		{
			f[i][j][0]=max(f[i][j-1][0],f[i+(1<<(j-1))][j-1][0]);
			f[i][j][1]=max(f[i][j-1][1],f[i+(1<<(j-1))][j-1][1]);
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		int L,R;
		scanf("%d%d",&L,&R);
		ans=0ll;
		for(int i=L;i<=R;i++)
		{
			int l=1,r=i-L+1;
			while(l<r)
			{
				int mid=(1+l+r)>>1;
				if(ask(i-mid+1,i,0)==f[i][0][0]) l=mid;
				else r=mid-1;
			}
			int LL=i-l+1;
			l=1,r=R-i+1;
			while(l<r)
			{
				int mid=(1+l+r)>>1;
				if(ask(i,i+mid-1,0)==f[i][0][0]) l=mid;
				else r=mid-1;
			}
			int RR=i+l-1;
			for(int j=LL;j<=i;j++)
			{
				for(int k=i;k<=RR;k++) ans+=ask(j,k,1)*f[i][0][0];
			}
		}
		printf("%llu\n",ans);
	}
	return 0;
}
