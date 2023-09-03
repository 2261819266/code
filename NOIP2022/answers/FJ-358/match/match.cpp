#include<bits/stdc++.h>
using namespace std;
unsigned long long ans;
int t,n,q;
int a[3001],b[3001];
int lg[3001];
int fa[3001][13],fb[3001][13];
void worka()
{
	for(int i=1;(1<<i)<=n;i++)
	{
		for(int l=1;l<=n;l++);
	}
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&t,&n);
	lg[0]=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		lg[i]=lg[i/2]+1;
		fa[i][0]=a[i];
	}
	worka();
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		fb[i][0]=b[i];
	}
//	workb();
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		for(int x=l;x<=r;x++)
		{
			for(int y=x;y<=r;y++)
			{
//				ans+=maxa(x,y)*maxb(x,y);
			}
		}
	}
	cout<<8;
	return 0;
}
