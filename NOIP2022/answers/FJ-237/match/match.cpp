#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,n,Q;
ll a[250010],b[250010],ans;
ll fa[500010][20],fb[500010][20];
ll ma,mb;
void init()
{
	for(int j=1;j<=18;j++)
	for(int i=1;i<=n;i++)
	{
		fa[i][j]=max(fa[i][j-1],fa[i+(1<<(j-1))][j-1]);
		fb[i][j]=max(fb[i][j-1],fb[i+(1<<(j-1))][j-1]);
	}
	return;
}
ll getmaxa(int l,int r)
{
	if(l==r) return fa[l][0];
	int p=log2(r-l);
	return max(fa[l][p],fa[r-(1<<p)][p]);
}
ll getmaxb(int l,int r)
{
	if(l==r) return fb[l][0];
	int p=log2(r-l);
	return max(fb[l][p],fb[r-(1<<p)][p]);
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int l,r;
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		fa[i][0]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",b+i);
		fb[i][0]=b[i];
	}
	init();
	scanf("%d",&Q);
	while(Q--)
	{
		ans=0;
		scanf("%d%d",&l,&r);
		for(int p=l;p<=r;p++)
		{
			for(int q=p;q<=r;q++)
			{
				ma=getmaxa(p,q+1);
				mb=getmaxb(p,q+1);
				ans+=ma*mb;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
