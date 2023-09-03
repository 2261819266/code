#include<bits/stdc++.h>
#define mod	1000000007
using namespace std;
typedef long long ll;
inline int read()
{
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		g*=10;
		g+=ch-'0';
		ch=getchar();
	}
	return f*g;
}
int a[250005],b[250005];
struct node{
	int l,r;
	ll maxx=0;
}tree1[1000015],tree2[1000015];
int aa[3005][3005];
int bb[3005][3005];
void build1(int id,int l,int r)
{
	tree1[id].l=l;
	tree1[id].r=r;
	if(l==r)
	{
		tree1[id].maxx=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build1(id<<1,l,mid);
	build1(id<<1|1,mid+1,r);
	tree1[id].maxx=max(tree1[id<<1].maxx,tree1[id<<1|1].maxx);
}
void build2(int id,int l,int r)
{
	tree2[id].l=l;
	tree2[id].r=r;
	if(l==r)
	{
		tree2[id].maxx=b[l];
		return;
	}
	int mid=(l+r)>>1;
	build2(id<<1,l,mid);
	build2(id<<1|1,mid+1,r);
	tree2[id].maxx=max(tree2[id<<1].maxx,tree2[id<<1|1].maxx);
}
int query1(int id,int l,int r)
{
	if(tree1[id].l>r||tree1[id].r<l)
	{
		return 0;
	}
	if(tree1[id].l>=l&&tree1[id].r<=r)
	{
		return tree1[id].maxx;
	}
	return max(query1(id<<1,l,r),query1(id<<1|1,l,r));
}
int query2(int id,int l,int r)
{
	if(tree2[id].l>r||tree2[id].r<l)
	{
		return 0;
	}
	if(tree2[id].l>=l&&tree2[id].r<=r)
	{
		return tree2[id].maxx;
	}
	return max(query2(id<<1,l,r),query2(id<<1|1,l,r));
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int id=read(),n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=read();
	}
	build1(1,1,n);
	build2(1,1,n);
	int q=read();
	if(id<=2)
	{
		for(int i=1;i<=n;i++)
		{
			aa[i][i]=a[i];
			bb[i][i]=b[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				aa[i][j]=query1(1,i,j);
				bb[i][j]=query2(1,i,j);
			//	cout<<aa[i][j]<<' ';
				
			}
			//cout<<endl;
		}

		while(q--)
		{
			int x=read(),y=read();
			ll ans=0;
			for(int i=x;i<=y;i++)
			{
				for(int j=i;j<=y;j++)
				{
					ans+=1ll*aa[i][j]*bb[i][j];
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
//3005 3005
