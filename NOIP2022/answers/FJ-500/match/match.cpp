#include<bits/stdc++.h>
using namespace std;
const int N=2.5e5+50;
int read(){
	int x=0,hhh=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') hhh=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*hhh;
}
struct SegmentTree{
	int l,r,sum;
}ta[N<<1],tb[N<<1];
int a[N],b[N];
void build(int p,int l,int r,int *az,SegmentTree *hh)
{
	hh[p].l=l,hh[p].r=r;
	if(l==r) { hh[p].sum=az[l]; return; }
	int mid=(l+r)>>1;
	build(p<<1,l,mid,az,hh);
	build(p<<1|1,mid+1,r,az,hh);
	hh[p].sum=max(hh[p<<1].sum,hh[p<<1|1].sum);
}
int ask(int p,int l,int r,SegmentTree *hh)
{
	if(l<=hh[p].l&&hh[p].r<=r) return hh[p].sum;
	int mid=(hh[p].l+hh[p].r)>>1;
	int az=0;
	if(l<=mid) az=ask(p<<1,l,mid,hh);
	if(mid<r) az=max(ask(p<<1|1,mid+1,r,hh),az);
	return az; 
}
int n;
unsigned long long ans;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
	int T=read();
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) b[i]=read();
	build(1,1,n,a,ta);
	build(1,1,n,b,tb);
	int Q=read();
	while(Q--)
	{
		ans=0ll;
		int l=read(),r=read();
		for(int i=l;i<=r;++i)
		{
			ans+=a[i]*b[i];
			for(int j=i+1;j<=r;++j)
				ans+=ask(1,i,j,ta)*ask(1,i,j,tb);
		}
		cout<<ans<<endl;
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
