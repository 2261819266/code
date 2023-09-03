#include<bits/stdc++.h>
using namespace std;
int t,n,a[4000],b[4000],maxa[4000][4000],maxb[4000][4000];
inline int read()
{
	int x=0;
	char c;
	while(c=getchar())if(c>='0'&&c<='9')break;
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	t=read();
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	for(int i=1;i<=n;++i)
	{
		maxa[i][i]=a[i];
		for(int j=i+1;j<=n;++j)maxa[i][j]=max(maxa[i][j-1],a[j]);
	}
	for(int i=1;i<=n;++i)
	{
		maxb[i][i]=b[i];
		for(int j=i+1;j<=n;++j)maxb[i][j]=max(maxb[i][j-1],b[j]);
	}
	int q;
	q=read();
	int l,r;
	while(q--)
	{
		l=read();
		r=read();
		unsigned long long ans=0;
		for(int i=l;i<=r;++i)
		{
			for(int j=i;j<=r;++j)
			{
				ans=ans+maxa[i][j]*maxb[i][j];
			}
		}
		cout<<ans<<endl;
	}
}