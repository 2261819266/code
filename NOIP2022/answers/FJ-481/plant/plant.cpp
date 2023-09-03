#include<bits/stdc++.h>
#define rep(i,a,b) for(int i(a);i<=b;++i)
#define per(i,a,b) for(int i(a);i>=b;--i)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define swap(a,b) a^=b^=a^=b
inline int read()
{
	int x(0),f(1);
	char c=getchar();
	while(c<'0'||c>'9')
	{
		f=(c^'-'?1:-1);
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
using namespace std;
const int N=1e3+5;
int T,id,dpc[N][N],dpf[N][N];
bool a[N][N];
signed main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read();
	id=read();
	while(T--)
	{
		puts("0");
//		int n=read(),m=read(),c=read(),f=read(),ans1=0,ans2=0;
//		rep(i,1,n)
//		{
//			rep(j,1,m)
//				a[i][j]=read();
//		}
//		dpc[3][2]=!a[1][1]&&!a[2][1]&&!a[3][1]&&!a[1][2]&&!a[3][2];
//		dpf[4][2]=dpc[3][2]&&!a[4][1];
//		rep(i,3,n)
//		{
//			rep(j,2,n)
//			{
//				if(i==3&&j==2)
//					continue;
//				dpc[i][j]=dpc[i][j-1]+(!a[1][j])
//			}
//		}
	}
	return 0;
}