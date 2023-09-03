#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int read()
{
	char c=getchar();bool f=0;int ret=0;
	while (!isdigit(c))
	{
		if (c=='-') f=1;
		c=getchar();
	}
	while (isdigit(c))
	{
		ret*=10;ret+=c-'0';
		c=getchar();
	}
	if (f) return -ret;
	else return ret;
}
int t,n;int q;
int a[250010],b[250010];
void sub1()
{
	while (q--)
	{
		int ans=0;
		int l,r;l=read();r=read();
		for (int p=l;p<=r;++p)
		{
			int mx1=0,mx2=0;
			for (int q=p;q<=r;++q)
			{
				mx1=max(mx1,a[q]);mx2=max(mx2,b[q]);
				ans+=mx1*mx2;
			}
		}
		cout<<ans<<'\n';
	}
}
signed main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	t=read();n=read();
	for (int i=1;i<=n;++i) a[i]=read();
	for (int i=1;i<=n;++i) b[i]=read();
	q=read();
//	if (t==0 && n==3000)
//	if (n<=30 && q<=30) 
		sub1();
	fclose(stdin);fclose(stdout);
	return 0;
}

