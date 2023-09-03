#include<bits/stdc++.h>
using namespace std;
constexpr int N=500003,M=2000003,P=1e9+7;
typedef pair<int,int> PII;
bool Mbe;
inline int read()
{
	int x=0,y=1;char ch=getchar();
	while(ch<48||ch>57){if(ch=='-') y=-1;ch=getchar();}
	while(ch>=48&&ch<=57) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*y;
}
int n,Q,a[N],b[N],mx[N][20],mxx[N][20],stk[N],st[N];
unsigned long long ans;
struct node{
	int a,b,c;
};
inline int ge(int l,int r)
{
	int k=__lg(r-l+1);
	return max(mx[l][k],mx[r-(1<<k)+1][k]);
}
inline int get(int l,int r)
{
	int k=__lg(r-l+1);
	return max(mxx[l][k],mxx[r-(1<<k)+1][k]);
}
bool Med;
signed main()
{
	#define Marsrayd
	#ifdef Marsrayd
		freopen("match.in","r",stdin);
		freopen("match.out","w",stdout);
	#endif
	int T=read();n=read();
	for(int i=1;i<=n;i++)
	{
		mx[i][0]=a[i]=read();
	}
	for(int i=1;i<=__lg(n);i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			mx[j][i]=max(mx[j][i-1],mx[j+(1<<i-1)][i-1]);
		}
	for(int i=1;i<=n;i++)
	{
		mxx[i][0]=b[i]=read();
	}
	for(int i=1;i<=__lg(n);i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			mxx[j][i]=max(mxx[j][i-1],mxx[j+(1<<i-1)][i-1]);
		}
	Q=read();
	for(int l,r;Q--;)
	{
		l=read(),r=read(),ans=0;
		for(int i=l;i<=r;i++)
			for(int j=i;j<=r;j++)
				ans=ans+ge(i,j)*get(i,j);
			printf("%llu\n",ans);
	}
	return 0;
}
/*
0 2
2 2 1
3 1 2
4 1
5 1 2
*/

