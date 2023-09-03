#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e3+5,mod=998244353;
int T,n,m,id,C,F,a[N][N],f[N][N],g[N][N],h[N][N],ans,ans1;
char c[N];
inline int AD(LL x,int y){x+=y;return x>=mod?x-mod:x;}
int main()
{
	freopen("plant.in","r",stdin);freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&C,&F);ans=ans1=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",c);
			for(int j=1;j<=m;j++) a[i][j]=c[j-1]-'0';
		}
		for(int i=1;i<=n;i++)
		{
			f[i][m+1]=m+1;
			for(int j=m;j>=1;j--) f[i][j]=(a[i][j])?j:f[i][j+1];
		}
//		for(int i=1;i<=n;i++,puts("")) for(int j=1;j<=m;j++) printf("%d ",f[i][j]-j);
		for(int j=1;j<=m;j++)
		{
			g[n+1][j]=h[n+1][j]=0;int las=n+1;
			for(int i=n;i>=1;i--)
			{
				if(a[i][j]) g[i][j]=h[i][j]=0,las=i;
				else g[i][j]=AD(g[i+1][j],f[i][j]-j-1),h[i][j]=AD(h[i+1][j],1ll*(f[i][j]-j-1)*(las-i-1)%mod);
			}
		}
		
		for(int i=1;i<=n-2;i++) for(int j=1;j<=m;j++)
			if(!a[i][j]&&!a[i+1][j]&&!a[i+2][j])
				ans=AD(ans,1ll*(f[i][j]-j-1)*g[i+2][j]%mod),ans1=AD(ans1,1ll*(f[i][j]-j-1)*h[i+2][j]%mod);
		printf("%d %d\n",C*ans,F*ans1);
	}
	return 0;
}
/*
2 0
6 6 1 1
000010
011000
000110
010000
011000
000000
16 12 1 1
000000000001
011111111111
000000000011
011111111111
010011111111
010111100011
010011101111
011111100011
111111111111
000011111111
011111111111
000000111111
011111000111
011111011111
011111000111
011111011111

*/
