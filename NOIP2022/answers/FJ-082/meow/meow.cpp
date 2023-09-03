#include<bits/stdc++.h>
#define mod 998244353
#define int long long
#define N 1010
using namespace std;
int T,ne,cz,cnt,n,m,k;
int t[N],zt[N],zw[N],ans[N],f[N],ans2[N];
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
signed main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>T;
	while(T--)
	{
		n=read();m=read();k=read();
		ne=1; cnt=0;
		for(int ci,i=1;i<=m;i++)
		{
			ci=read();
			if(t[ci]==0)
			{
				t[ci]=ne;
				if(zt[ne]==0)zt[ne]=ci;
				zw[ne]=ci;
				ans[++cnt]=ne,f[cnt]=1;
				if(ne==n-1)ne=1;
				else ne++;
			}
			else 
			{
				if(zt[t[ci]]==ci&&zw[t[ci]]==ci)
				{
					ans[++cnt]=t[ci],f[cnt]=1;
					ne=t[ci],zt[ne]=0,zw[ne]=0;
				}
				else if(zt[t[ci]]==ci)
				{
					ans[++cnt]=n,f[cnt]=1;
					ans[++cnt]=n,ans2[cnt]=t[ci],f[cnt]=2;
					zt[t[ci]]=zw[t[ci]];
					ne=t[ci];
				}
				else if(zw[t[ci]]==ci)
				{
					ans[++cnt]=t[ci],f[cnt]=1;
					zw[t[ci]]=zt[t[ci]];
					ne=t[ci];
				}
				t[ci]=0;
			}
		}
		for(int i=1;i<=cnt;i++)
		{
			cout<<f[i]<<" ";
			if(f[i]==1)cout<<ans[i]<<" ";
			if(f[i]==2)cout<<ans2[i]<<" "<<ans[i];
			cout<<endl;
		}
	}
}
