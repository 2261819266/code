//10
#include<bits/stdc++.h>
using namespace std;
int a[250010],b[250010];
struct xds
{
	int l,r,z;
	int ax;
}ash[1000010],bsh[1000010];
int n;
void z(int l,int r,int w)
{
	ash[w].l=l;bsh[w].l=l;
	ash[w].r=r;bsh[w].r=r;
	if(l==r)
	{
		ash[w].ax=a[l];
		bsh[w].ax=b[l];
		return;
	}
	int md=(l+r)/2;
	z(l,md,w*2);
	z(md+1,r,w*2+1);
	ash[w].ax=max(ash[w*2].ax,ash[w*2+1].ax);
	bsh[w].ax=max(bsh[w*2].ax,bsh[w*2+1].ax);
}
int afax(int l,int r,int w)
{
	if(ash[w].l>=l&&ash[w].r<=r)
	{
		return ash[w].ax;
	}
	if(ash[w].r<l||ash[w].l>r)
	{
		return 0;
	}
	return max(afax(l,r,w*2),afax(l,r,w*2+1));
}
int bfax(int l,int r,int w)
{
	if(bsh[w].l>=l&&bsh[w].r<=r)
	{
		return bsh[w].ax;
	}
	if(bsh[w].r<l||bsh[w].l>r)
	{
		return 0;
	}
	return max(bfax(l,r,w*2),bfax(l,r,w*2+1));
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int bh;
	cin>>bh>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	z(1,n,1);
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		unsigned long long ans=0;
		for(int j=l;j<=r;j++)
		{
			for(int k=j;k<=r;k++)
			{
				ans+=afax(j,k,1)*bfax(j,k,1);
			}
		}        
		cout<<ans<<endl;  
	}
	return 0;
}
