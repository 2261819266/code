#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define mk(x,y) (make_pair(x,y))
using namespace std;
const int N=3e5+100;
int T,n,anxt[N],bnxt[N],q;
ll a[N],b[N];
vector< pair<int,ull> > d[N];
ull get_ans(int l,int r)
{
	ull res=0;
	int pre=l-1;
	for(int i=0;i<d[l].size();++i)
	{
		if(d[l][i].first<r)
		{
			res+=d[l][i].second*(d[l][i].first-pre);
			pre=d[l][i].first;
		}
		else
		{
			res+=d[l][i].second*(r-pre);
			break ;
		}
	}
	return res;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;++i)
	{
		cin>>b[i];
	}
	for(int i=n;i>=1;--i)
	{
		anxt[i]=i+1;
		while(anxt[i]<=n&&a[anxt[i]]<a[i])
		anxt[i]=anxt[anxt[i]];
		
		bnxt[i]=i+1;
		while(bnxt[i]<=n&&b[bnxt[i]]<b[i])
		bnxt[i]=bnxt[bnxt[i]];
	}
	for(int i=1;i<=n;++i)
	{
		int anow=i,bnow=i;
		while(1)
		{
			int nxt=min(anxt[anow],bnxt[bnow]);
			d[i].push_back(mk(nxt-1,(ull)a[anow]*b[bnow]));
			if(nxt>n)
			break ;
			if(anxt[anow]==nxt)
			anow=nxt;
			if(bnxt[bnow]==nxt)
			bnow=nxt;
		}	
	}
    cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		ull ans=0;
		for(int i=l;i<=r;++i)
		ans+=get_ans(i,r);
		cout<<ans<<'\n';
		//printf("%ulld\n",ans);
	}
	return 0;
}













