#include<bits/stdc++.h>
using namespace std;
#define maxn 250010
typedef long long ll;
struct node{
	ll val;
	int id;
	bool operator <(node t)const
	{
		return val>t.val;
	}
}temp;
priority_queue< node,vector<node>,less<node> >que;
ll a[maxn],b[maxn],la[maxn],ra[maxn],lb[maxn],rb[maxn],prea[maxn],preb[maxn];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T,n,Q,l,r,q;
	cin>>T>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		while(!que.empty()&&que.top().val<a[i])
		{
			temp=que.top();
			que.pop();
			ra[temp.id]=i-1;
		}
		la[i]=i;
		que.push((node){a[i],i});
	}
	while(!que.empty())
	{
		temp=que.top();
		que.pop();
		ra[temp.id]=n;
	}
	for(int i=1;i<=n;i++)
	{
		while(!que.empty()&&que.top().val<b[i])
		{
			temp=que.top();
			que.pop();
			rb[temp.id]=i-1;
		}
		lb[i]=i;
		que.push((node){b[i],i});
	}
	while(!que.empty())
	{
		temp=que.top();
		que.pop();
		rb[temp.id]=n;
	}
	for(int i=1;i<=n;i++)
	{
		prea[i]=prea[i-1]+(ra[i]-la[i]+1)*a[i];
		preb[i]=preb[i-1]+(rb[i]-lb[i]+1)*b[i];
	}
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		cout<<prea[i]*preb[i]<<'\n';
	}
	return 0;
}
