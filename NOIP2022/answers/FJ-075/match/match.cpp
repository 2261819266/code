#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int read()
{
	char ch;
	int s=1;
	while((ch=getchar())<'0' || ch>'9')
	  if(ch=='-')
	    s=-1;
	int res=ch-'0';
	while((ch=getchar())>='0' && ch<='9')
	  res=(res<<3)+(res<<1)+ch-'0';
	return res*s;
}
int T,n,q;
int a[1000001];
int b[1000001];
int tra[2000001];
int trb[2000001];
void build(int *tree,int *a,int k,int l,int r)
{
	if(l==r)
	{
		tree[k]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(tree,a,k<<1,l,mid);
	build(tree,a,k<<1|1,mid+1,r);
	tree[k]=max(tree[k<<1],tree[k<<1|1]);
}
ull query(int *tree,int k,int l,int r,int x,int y)
{
	if(l>y || r<x)
	  return 0;
	if(l>=x && r<=y)
	  return tree[k];
	int mid=(l+r)>>1;
	return max(query(tree,k<<1,l,mid,x,y),query(tree,k<<1|1,mid+1,r,x,y));
}
ull ans;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read(),n=read();
	for(int i=1;i<=n;i++)
	  a[i]=read();
	for(int i=1;i<=n;i++)
	  b[i]=read();
	build(tra,a,1,1,n);
	build(trb,b,1,1,n);
	q=read();
	for(int i=1;i<=q;i++)
	{
		int aa=read(),bb=read();
		ans=0;
		for(int j=aa;j<=bb;j++)
		{
			for(int k=j;k<=bb;k++)
			{
				ans+=query(tra,1,1,n,j,k)*query(trb,1,1,n,j,k);
			}
		}
		cout<<ans<<endl;
	}
}
