#include<bits/stdc++.h>
using namespace std;
const int N=305;
const int M=2e6+5;
int n,m,k,tot=0;
int a[M];
deque<int> s[N];
bool check()
{
	for (int i=1;i<=tot;++i) if (!s[i].empty()) return 1;
	return 0;
}
void solve()
{
	for (int i=1;i<=m;++i)
	{
		bool f=1;
		for (int j=1;j<=tot;++j)
		{
			if (a[i]==s[j].back()) {s[j].pop_back();cout<<1<<' '<<j<<endl;f=0;break;}
			if (a[i]>s[j].back() || s[j].empty()) {s[j].emplace_back(a[i]);cout<<1<<' '<<j<<endl;f=0;break;}
		}
		if (f && tot<n) s[++tot].emplace_back(a[i]),cout<<1<<' '<<tot<<endl;
		else if (f && tot==n) s[tot].emplace_back(a[i]),cout<<1<<' '<<tot<<endl;
		for (int j=1;j<=tot;++j)
			for (int k=j+1;k<=tot;++k)
				while (s[j].front()==s[k].front()) cout<<2<<' '<<j<<' '<<k<<endl,s[j].pop_front(),s[k].pop_front();
	}
	while (check())
	{
		for (int i=1;i<=tot;++i)
			for (int j=i+1;j<=tot;++j)
				while (s[i].front()==s[j].front() && !s[i].empty() && !s[j].empty()) cout<<2<<' '<<i<<' '<<j<<endl,s[i].pop_front(),s[j].pop_front();
	}
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n>>m>>k;
		for (int i=1;i<=m;++i) cin>>a[i];
		solve();
	}
	return 0;
}
