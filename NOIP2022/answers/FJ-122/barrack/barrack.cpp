#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=1e6+5;
const int MOD=1e9+7;
int n,m,ans=0;
vector<pair<int,int>> e[N];
map<pair<int,int>,bool> mp;
//bool mp[1000][1000];
int vis_edge[M];
int Pow(int a,int x)
{
	int cnt=a,ans=1;
	while (x)
	{
		if (x&1) ans=ans*cnt%MOD;
		cnt=cnt*cnt%MOD,x>>=1;
	}
	return ans;
}
void dfs(int now,int cl_edge,int cl_point)
{
	if (mp[make_pair(cl_edge,cl_point)]==0) ans=(ans+1)%MOD,mp[make_pair(cl_edge,cl_point)]=1,cout<<now<<' '<<cl_edge<<' '<<cl_point<<' '<<ans<<endl;
	//if (mp[cl_edge][cl_point]==0) ans++,mp[cl_edge][cl_point]=1,cout<<now<<' '<<cl_edge<<' '<<cl_point<<' '<<ans<<endl;
	for (auto i:e[now])
	{
		int num=i.second,to=i.first;
		if (vis_edge[num]>2) return;
		vis_edge[num]++;
		dfs(to,cl_edge|(1<<(num-1)),cl_point);
		dfs(to,cl_edge|(1<<(num-1)),cl_point|(1<<(to-1)));
		vis_edge[num]--;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	if (m==n-1)
	{
		int ans=0;
		for (int i=1;i<=n;++i)
			ans=(ans+1ll*(n-i+1)*(long long)(Pow(2,i)-1)%MOD)%MOD;
		cout<<ans;
		return 0;
	}
	for (int i=1;i<=m;++i)
	{
		int u,v;
		cin>>u>>v;
		e[u].emplace_back(make_pair(v,i));
		e[v].emplace_back(make_pair(u,i));
	}
	for (int i=1;i<=n;++i) dfs(i,0,0);
	cout<<ans;
	return 0;
}
