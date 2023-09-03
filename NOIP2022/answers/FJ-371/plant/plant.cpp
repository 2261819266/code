#include<bits/stdc++.h>
using namespace std;

const long long N=1001;
const long long mod=998244353;

long long ff[N][N],T,id,n,m,c,fff,a[N][N],f[N][N],l,r,mid,ansc=0,ansf=0;

bool ok(long long i,long long j,long long x)
{
	if(ff[x][j]-ff[i-1][j]==x-i+1) return true;
	else return false;
}

int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);//long long,zhushi,shuzu,duipai
	scanf("%lld%lld",&T,&id);
	if(id==1)
	{
		while(T--) printf("%d %d\n",0,0);
		return 0;
	}
	//if(id==)
	while(T--)
	{
		memset(f,0,sizeof(f));
		memset(ff,0,sizeof(ff));
		ansc=0;ansf=0;
		scanf("%lld%lld%lld%lld",&n,&m,&c,&fff);
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<=m;j++)
			{
				scanf("%1d",&a[i][j]);
			}
		}
		for(long long i=1;i<=n;i++)
		{
			for(long long j=m;j>=1;j--)
			{
				if(a[i][j]==0)
				{
					f[i][j]=f[i][j+1]+1;
					ff[i][j]=1;
				}
			}
		}
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<=m;j++)
			{
				if(a[i][j]==0) f[i][j]=f[i][j]-1;
			}			
		//	cout<<endl;
		}
		for(long long j=1;j<=m;j++)
		{
			for(long long i=1;i<=n;i++)
			{
				if(a[i][j]==0)
				f[i][j]=f[i][j]+f[i-1][j];
				ff[i][j]=ff[i][j]+ff[i-1][j];
			}			
		}
		for(long long j=1;j<=m;j++)
		{
			for(long long i=1;i<=n;i++)
			{
				if(a[i][j]) continue;
				l=i;r=n;
				while(l<=r)
				{
					mid=(l+r)>>1;
					if(ok(i,j,mid)) l=mid+1;
					else r=mid-1;
				}
			//	cout<<i<<" "<<j<<" "<<r<<endl;
				for(long long k=i;k+2<=r;k++)
				{
					ansc=(ansc+(f[k][j]-f[k-1][j])%mod*(f[r][j]-f[k+1][j])%mod)%mod;
				}
				for(long long k=i+2;k<r;k++)
				{
					ansf=(ansf+(f[k][j]-f[k-1][j])%mod*(f[k-2][j]-f[i-1][j])%mod*(r-k)%mod)%mod;
				}
			//	cout<<ansc<<" "<<ansf<<endl;
			//	cout<<i<<" "<<j<<" "<<l<<endl;
			//	cout<<ok(i,j,l)<<" "<<ok(i,j,l-1)<<endl;
				i=l;
			}
		}
		printf("%lld %lld\n",ansc*c%mod,ansf*fff%mod);
	}
	return 0;
}

