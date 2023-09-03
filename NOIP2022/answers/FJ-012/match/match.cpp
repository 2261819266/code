#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=3005;
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
int lg2[N];
struct ST
{
	int m;
	int c[N][20];
	void init(int *f,int n)
	{
		m=n;
		for(int i=1;i<=n;i++)
			c[i][0]=f[i];
		for(int len=1;(1<<len)<=n;len++)
			for(int l=1;l+(1<<len)-1<=n;l++)
				c[l][len]=max(c[l][len-1],c[l+(1<<(len-1))][len-1]);
	}
	ull fmax(int l,int r)
	{
		int d=lg2[r-l+1];
		return (ull)max(c[l][d],c[r-(1<<d)+1][d]);
	}
}sa,sb;
int a[N],b[N];
vector<ull> ans[N];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T=rd(),n=rd();
	lg2[1]=0;
	for(int i=2;i<=n;i++)
		lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=n;i++)
		a[i]=rd();
	for(int i=1;i<=n;i++)
		b[i]=rd();
	sa.init(a,n);
	sb.init(b,n);
	if(T<=5)
	{
		for(int i=1;i<=n;i++)
			for(int j=0;j<=n;j++)
				ans[i].push_back(0);
		for(int p=1;p<=n;p++)
			for(int q=p;q<=n;q++)
				ans[p][q]=sa.fmax(p,q)*sb.fmax(p,q);
		for(int len=2;len<=n;len++)
			for(int l=1;l+len-1<=n;l++)
			{
				int r=l+len-1;
				ans[l][r]+=ans[l+1][r]+ans[l][r-1];
				if(l+1<=r-1)
				ans[l][r]-=ans[l+1][r-1];
			}
		int Q=rd();
		while(Q--)
		{
			int l=rd(),r=rd();
			printf("%llu\n",ans[l][r]);
		}
		return 0;
	}
	int Q=rd();
	while(Q--)
	{
		int l=rd(),r=rd();
		ull res=0;
		for(int p=l;p<=r;p++)
			for(int q=p;q<=r;q++)
				res+=sa.fmax(p,q)*sb.fmax(p,q);
		printf("%llu\n",res);
	}
	
	
	
	return 0;
}

