#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(){}
template <typename T,typename ... T2>
inline void read(T &x,T2 &... oth)
{
	register bool opt=1;x=0;
	register char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')opt=0;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=opt?x:-x;
	read(oth...);
}
const int N=1010,mod=998244353;
char b[N];
int n,m,cc,ff,a[N][N],c[N][N];
int w[N][N],h[N][N],t[N][N],sumw[N][N],sumf[N][N];
int ansc,ansf;
inline void Get_w(int pos,int l,int r,int x)
{
	for(int i=l;i<=r;i++)w[pos][i]=x-i;
}
inline void Get_h(int pos,int l,int r,int x)
{
	for(int i=l;i<=r;i++)h[i][pos]=x-i;
}
void init()
{
	for(int i=1;i<=n;i++)
		for(int j=1,x=0;j<=m+1;j++)
			if(a[i][j]||j>m)Get_w(i,x+1,j-1,j-1),x=j,w[i][j]=0;
	for(int j=1;j<=m;j++)
		for(int i=1,x=0;i<=n+1;i++)
			if(a[i][j]||i>n)Get_h(j,x+1,i-1,i),x=i,h[i][j]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			t[i][j]=w[i][j]*(h[i][j]-1);
	memset(sumw,0,sizeof(sumw));
	memset(sumf,0,sizeof(sumf));
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			sumw[j][i]=a[j][i]?0:sumw[j-1][i]+w[j][i];
			sumf[j][i]=a[j][i]?0:sumf[j-1][i]+t[j][i];
		}
}
void Solve()
{
	read(n,m,cc,ff);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",b+1);
		for(int j=1;j<=m;j++)a[i][j]=b[j]-'0';
	}
	ansc=ansf=0;
	init();
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(h[i][j]>1)
			{
				ansc=(ansc+w[i][j]*(sumw[i+h[i][j]-1][j]-sumw[i+1][j])%mod)%mod;
				ansf=(ansf+w[i][j]*(sumf[i+h[i][j]-1][j]-sumf[i+1][j])%mod)%mod;
			}
		}
	}
	printf("%lld %lld\n",ansc*cc,ansf*ff);
}
signed main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	read(T,id);
	while(T--)Solve();
	return 0;
}
