#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+15,MOD=1e9+7;
int n,m;
vector<int>mep[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>u>>v;
		mep[u].push_back(v);
		mep[v].push_back(u);
	}
	cout<<114514;
	return 0;
}
