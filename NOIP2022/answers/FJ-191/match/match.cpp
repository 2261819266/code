#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,Q; 
const int N=1e6+5;
ll mx1[N],mx2[N];
ll a[N],b[N];
void upd(int rt)
{
	mx1[rt]=max(mx1[rt*2],mx1[rt*2+1]);
	mx2[rt]=max(mx2[rt*2],mx2[rt*2+1]);
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		mx1[rt]=a[l];
		mx2[rt]=b[l];
		return ;
	}
	int mid=l+r>>1;
	build(l,mid,rt*2);
	build(mid+1,r,rt*2+1);
	upd(rt);
}

ll Query(int x,int y,int l,int r,int rt)
{
	ll sum=0;
	if(x<=l&&r<=y)
	{
		return mx1[rt]*mx2[rt];
	}
	int mid=l+r>>1;
	if(x<=mid)sum+=Query(x,y,l,mid,rt*2);
	if(y>mid)sum+=Query(x,y,mid+1,r,rt*2);
	return sum;	
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	build(1,n,1);
	cin>>Q;
	int l,r;
	while(Q--)
	{
		ll sum=0;
		cin>>l>>r;
		for(int i=l;i<=r;i++)
		for(int j=i;j<=r;j++)
		{
			sum+=Query(i,j,1,n,1);
		}
		cout<<sum<<endl;
	}	
	
	return 0;
}
