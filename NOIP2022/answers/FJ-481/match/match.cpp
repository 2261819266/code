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
typedef unsigned long long ull;
const int N=2.5e5+5;
int st1[N][19],st2[N][19],Log[N];
ull ans=0;
inline int query1(int l,int r)
{
	int k=Log[r-l+1];
	return max(st1[l][k],st1[r-(1<<k)+1][k]);
}
inline int query2(int l,int r)
{
	int k=Log[r-l+1];
	return max(st2[l][k],st2[r-(1<<k)+1][k]);
}
signed main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T=read(),n=read();
	rep(i,2,n)
		Log[i]=Log[i>>1]+1;
	rep(i,1,n)
		st1[i][0]=read();
	rep(j,1,Log[n])
	{
		rep(i,1,n-(1<<j)+1)
			st1[i][j]=max(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
	}
	rep(i,1,n)
		st2[i][0]=read();
	rep(j,1,Log[n])
	{
		rep(i,1,n-(1<<j)+1)
			st2[i][j]=max(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
	}
	int Q=read();
	rep(i,1,Q)
	{
		int l=read(),r=read();
		ans=0;
		vector<int> chs1,chs2;
		rep(len,1,r-l+1)
		{
			rep(p,l,r-len+1)
			{
				int q=p+len-1;
//				printf("%d %d of %d %d end.\n",p,q,query1(p,q),query2(p,q));
				chs1.push_back(query1(p,q));
				chs2.push_back(query2(p,q));
			}
		}
		rep(i,0,chs1.size()-1)
			ans+=(ull)(chs1[i])*(ull)(chs2[i]);
		printf("%llu\n",ans);
	}
	return 0;
}