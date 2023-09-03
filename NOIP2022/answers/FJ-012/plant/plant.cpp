#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1005;
const int mod=998244353;
inline int rd()
{
	int x=0; bool f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())
		if(ch=='-') f=0;
	for(;ch>='0'&&ch<='9';ch=getchar())
		x=x*10+(ch^48);
	return f?x:-x;
}
inline bool rdd()
{
	char ch=getchar();
	while(ch<'0'||ch>'1')
		ch=getchar();
	return ch=='1';
}
inline void inc(ll &x,ll y)
{  if((x+=y)>=mod) x-=mod;  }
bool a[N][N];
int rgt[N][N],dwn[N][N];
int sr[N][N];
ll srd[N][N];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T=rd(),id=rd();
	while(T--)
	{
		int n=rd(),m=rd(),c=rd(),f=rd();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				a[i][j]=rdd();
		for(int i=1;i<=n;i++)
			for(int j=m;j;j--)
				if(!a[i][j])
					rgt[i][j]=rgt[i][j+1]+1;
		for(int i=n;i;i--)
			for(int j=1;j<=m;j++)
				if(!a[i][j])
					dwn[i][j]=dwn[i+1][j]+1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				sr[i][j]=sr[i-1][j]+rgt[i][j]-1;
		ll ansc=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]) continue;
				int d=dwn[i][j];
				ll k=rgt[i][j]-1;
				if(d>=3)
					inc(ansc,k*(sr[i+d-1][j]-sr[i+1][j])%mod);
			}
		printf("%lld ",c*ansc);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				srd[i][j]=(rgt[i][j]-1)*(dwn[i][j]-1)%mod;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				inc(srd[i][j],srd[i-1][j]);
		ll ansf=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]) continue;
				int d=dwn[i][j];
				ll k=rgt[i][j]-1;
				if(d>=3)
					inc(ansf,k*(srd[i+d-1][j]-srd[i+1][j]+mod)%mod);
			}
		printf("%lld\n",f*ansf);
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				rgt[i][j]=dwn[i][j]=sr[i][j]=srd[i][j]=0;
	}
	return 0;
}
