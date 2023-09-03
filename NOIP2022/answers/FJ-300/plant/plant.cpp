#include<bits/stdc++.h>
using namespace std;
bool Mbe;
constexpr int N=1003,P=998244353; 
inline int read()
{
	int x=0,y=1;char ch=getchar();
	while(ch<48||ch>57){if(ch=='-') y=-1;ch=getchar();}
	while(ch>=48&&ch<=57) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*y;
}

/*
dp[i][j][k]: 格子 i,j 状态为 k 方案数。

k=0: c/f 的上面
k=1：c/f 两横的中间。
k=2: c/f 的下面
k=3: c/f 的下面的下面 
*/
int n,m,C,F,anc,anf;
bool a[N][N];
int dp[N][N][5],js[N];
char str[N];
inline void solve()
{
	n=read(),m=read(),C=read(),F=read(),anc=anf=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str+1);
		for(int j=1;j<=m;j++)
		{
			a[i][j]=str[j]-'0';
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			printf("%d ",a[i][j]);
//		}
//		puts("");
//	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		js[m+1]=-1;
		for(int j=m;j>=1;j--)
		{
			if(!a[i][j]) dp[i][j][0]=js[j]=js[j+1]+1;
			else dp[i][j][0]=js[j]=-1;
		}
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]) continue;
			if(dp[i-1][j][0]>0) dp[i][j][1]+=dp[i-1][j][0];
			dp[i][j][1]+=dp[i-1][j][1];
			dp[i][j][2]+=dp[i-1][j][1];
			dp[i][j][3]+=dp[i-1][j][4];
		}
		for(int j=1;j<=m;j++)
		{
			if(js[j]>0) dp[i][j][2]*=js[j];
			else dp[i][j][2]=0;
			if(!a[i][j]) dp[i][j][4]=dp[i-1][j][4]+dp[i][j][2];
		}
//		for(int j=1;j<=m;j++)
//		{
////			printf("%d %d %d %d\n",dp[i][j][0],dp[i][j][1],dp[i][j][2],dp[i][j][3]);
//			printf("%d ",dp[i][j][3]);
//		}
//		puts("");
		for(int j=1;j<=m;j++)
		{
			anc+=dp[i][j][2],anf+=dp[i][j][3];
		}
	}
//	printf("%d %d %d %d %d\n",anc,anf,C,F,1ll*F*anf%P);
	printf("%lld %lld\n",1ll*C*anc%P,1ll*F*anf%P);
} 

bool Med;
signed main()
{
	#define Marsrayd
	#ifdef Marsrayd
		freopen("plant.in","r",stdin);
		freopen("plant.out","w",stdout);
	#endif
	int T=read(),ID=read();
	while(T--) solve(); 
	return 0;
}
