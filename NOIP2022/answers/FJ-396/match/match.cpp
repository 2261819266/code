#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2.5e5+5;
int id,n,a[2][N],q,tr[2][N];
void build(int k,int u,int l,int r)
{
	if(l==r)
	{
		tr[k][u]=a[k][l];
		return ;
	}
	int mid=(l+r)>>1;
	build(k,u<<1,l,mid);
	build(k,u<<1|1,mid+1,r);
	tr[k][u]=max(tr[k][u<<1],tr[k][u<<1|1]);
}
int get(int k,int u,int l,int r,int s,int t)
{
	if(s<=l&&r<=t) return tr[k][u];
	int mid=(l+r)>>1,ans=0;
	if(mid>=s) ans=max(ans,get(k,u<<1,l,mid,s,t));
	if(mid+1<=t) ans=max(ans,get(k,u<<1|1,mid+1,r,s,t));
	return ans;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>id>>n;
	for(int i=1;i<=n;i++)
		cin>>a[0][i];
	for(int i=1;i<=n;i++)
		cin>>a[1][i];
	build(0,1,1,n);
	build(1,1,1,n);
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		ull res=0;
		for(int p=l;p<=r;p++)
			for(int q=p;q<=r;q++)
				res+=get(0,1,1,n,p,q)*get(1,1,1,n,p,q);
		cout<<res<<endl;
	}
	return 0;
}
