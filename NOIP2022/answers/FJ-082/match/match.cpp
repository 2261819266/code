#include<bits/stdc++.h>
#define mod 998244353
#define int long long
#define N 10010
using namespace std;
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int T,n,q,a[N],b[N],ans;
signed main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	cin>>q;
	for(int l,r,i=1;i<=q;i++)
	{
		l=read();r=read();
		ans=0;
		for(int q=l;q<=r;q++)
		{
			for(int p=q;p<=r;p++)
			{
				int x=0;
				for(int j=q;j<=p;j++) x=max(x,a[j]);
				int y=0;
				for(int j=q;j<=p;j++) y=max(y,b[j]);
				ans+=x*y;
			}
		}
		cout<<ans;
	}
}
