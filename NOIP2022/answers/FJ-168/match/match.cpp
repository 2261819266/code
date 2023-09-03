#include<bits/stdc++.h>
using namespace std;
int a[300000],b[300000];
struct node
{
	int a;
	int b;
}tree[1200000];
int maxi(int x,int y)
{
	return y>x?y:x;
} 
void build(int now,int l,int r)
{
	if(l==r)
	{
		tree[now].a=a[l];
		tree[now].b=b[l];
		return ;
	}
	int mid=(l+r)/2;
	build(now*2  ,l,mid);
	build(now*2+1,mid+1,r);
	tree[now].a=maxi(tree[now*2].a,tree[now*2+1].a);
	tree[now].b=maxi(tree[now*2].b,tree[now*2+1].b);
}
node ask(int now,int l,int r,int gl,int gr)
{
	if(l>=gl&&r<=gr)
	{
		return tree[now];
	}
	int mid=(l+r)/2;
	node ans=(node){-1,-1},j=(node){-1,-1},k=(node){-1,-1};
	if(gl<=mid)j=ask(now*2,l,mid,gl,gr);
	if(gr>mid)k=ask(now*2+1,mid+1,r,gl,gr);
	ans.a=maxi(j.a,k.a);
	ans.b=maxi(j.b,k.b);
	return ans;
}
int vis[3010][3010];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,n;
	scanf("%d%d",&T,&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)scanf("%d",&b[i]);
	
	build(1,1,n);
	
	int q;
	scanf("%d",&q);
	unsigned long long ans=0;
	for (int i=1;i<=q;i++)
	{
		int l;int r;
		scanf("%d%d",&l,&r);
		for (int p=l;p<=r;p++)
		{
			for (int q=p;q<=r;q++)
			{	
				if(p<=3000&&q<=3000)
				{
					if(vis[p][q]==0)
					{
						node x=ask(1,1,n,p,q);
						vis[p][q]=x.a*x.b;
					}
					ans+=vis[p][q];
				}
				else
				{
					node x=ask(1,1,n,p,q);
					ans+=x.a*x.b;
				}
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
/*
	我果然还是太菜了,估计这三题暴力也拿不了多少分吧 
*/
