#include<bits/stdc++.h>
#define R register
#define ls(k) k<<1
#define rs(k) k<<1|1
const int maxn=3005;
using namespace std;
int t,n,q;
int treea[maxn<<2],treeb[maxn<<2];
int a[maxn],b[maxn];
int maxa[maxn][maxn],maxb[maxn][maxn];
inline void builda(int k,int l,int r)
{
	if(l==r)
	{
		treea[k]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	builda(ls(k),l,mid);
	builda(rs(k),mid+1,r);
	treea[k]=max(treea[ls(k)],treea[rs(k)]);
}
inline void buildb(int k,int l,int r)
{
	if(l==r)
	{
		treeb[k]=b[l];
		return ;
	}
	int mid=(l+r)>>1;
	buildb(ls(k),l,mid);
	buildb(rs(k),mid+1,r);
	treeb[k]=max(treeb[ls(k)],treeb[rs(k)]);
}
inline int querya(int k,int l,int r,int x,int y)
{
	if(l>=x&&r<=y)
	return treea[k];
	int mid=(l+r)>>1;
	int op=0;
	if(x<=mid)
	op=max(op,querya(ls(k),l,mid,x,y));
	if(y>mid)
	op=max(op,querya(rs(k),mid+1,r,x,y));
	return op;
}
inline int queryb(int k,int l,int r,int x,int y)
{
	if(l>=x&&r<=y)
	return treeb[k];
	int mid=(l+r)>>1;
	int op=0;
	if(x<=mid)
	op=max(op,queryb(ls(k),l,mid,x,y));
	if(y>mid)
	op=max(op,queryb(rs(k),mid+1,r,x,y));
	return op;
}
inline int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	t=read(),n=read();
	for(R int i=1;i<=n;i++)
	a[i]=read();
	for(R int i=1;i<=n;i++)
	b[i]=read();
	builda(1,1,n);
	buildb(1,1,n);
	for(R int i=1;i<=n;i++)
	for(R int j=i;j<=n;j++)
	{
		maxa[i][j]=querya(1,1,n,i,j);
		maxb[i][j]=queryb(1,1,n,i,j);
	}
	q=read();
	while(q--)
	{
		long long ans=0;
		int l=read(),r=read();
		for(R int i=l;i<=r;i++)
		for(R int j=i;j<=r;j++)
		ans=ans+maxa[i][j]*maxb[i][j];
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2
2 1
1 2
1
1 2
*/
