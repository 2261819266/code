#include<bits/stdc++.h>
#define MOD 18446744073709551615
using namespace std;

int T,n,Q;
unsigned long long a[250010];
unsigned long long b[250010];
pair<unsigned long long,unsigned long long> h[1000010];

void pushup(int index)
{
	h[index].first=max(h[index*2].first,h[index*2+1].first);
	h[index].second=max(h[index*2].second,h[index*2+1].second);
}

void build(int index,int l,int r)
{
	if(l==r)
	{
		h[index]=make_pair(a[l],b[l]);
		return;
	}
	int mid=(l+r)/2;
	build(index*2,l,mid);
	build(index*2+1,mid+1,r);
	pushup(index);
}

pair<unsigned long long,unsigned long long> ask(int index,int l,int r,int start,int end)
{
	if(l==start && r==end) return make_pair(h[index].first,h[index].second);
	if(l>end || r<start) return make_pair(0,0);
	int mid=(l+r)/2;
	if(mid>=end) return ask(index*2,l,mid,start,end);
	else if(mid<start) return ask(index*2+1,mid+1,r,start,end);
	else
	{
		pair<unsigned long long,unsigned long long> as1=ask(index*2,l,mid,start,mid);
		pair<unsigned long long,unsigned long long> as2=ask(index*2+1,mid+1,r,mid+1,end);
		return make_pair(max(as1.first,as2.first),max(as1.second,as2.second));
	}
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
	build(1,1,n);
	cin>>Q;
	int l,r;
	unsigned long long ans=0;
	pair<unsigned long long,unsigned long long> res;
	while(Q--)
	{
		ans=0;
		cin>>l>>r;
		for(int i=l;i<=r;i++)
		{
			for(int j=i;j<=r;j++)
			{
				res=ask(1,1,n,i,j);
				ans=(ans+res.first*res.second%MOD)%MOD;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
rp++
让我拿8分吧 求求你了  
		by 吴含章 hispy 
		2022.11.26
*/
