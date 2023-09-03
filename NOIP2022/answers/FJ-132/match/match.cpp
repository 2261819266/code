#include<bits/stdc++.h>
using namespace std;
int read()
{
	char c=getchar();int x=0,f=1;
	while(c>'9'||c<'0'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
#define ll long long
const int N=3e5+10;
int a[N],b[N];
unsigned ll ans;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T=read(),n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		b[i]=read();
	int q=read();
	while(q--)
	{
		int l=read(),r=read();
		ans=0;
		for(int i=l;i<=r;i++)
		{
			int maxn1=-1e9,maxn2=-1e9;
			for(int j=i;j<=r;j++) 
			{
				maxn1=max(maxn1,a[j]); 
				maxn2=max(maxn2,b[j]);
				ans+=(unsigned ll)maxn1*maxn2;
			}
		}
		printf("%llu\n",ans);
	}
	return 0;
}
