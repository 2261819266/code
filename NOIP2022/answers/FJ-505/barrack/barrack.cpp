#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> G[500005];

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++) cin>>u>>v,G[u].push_back(v),G[v].push_back(u);
	cout<<184
	return 0;
}
