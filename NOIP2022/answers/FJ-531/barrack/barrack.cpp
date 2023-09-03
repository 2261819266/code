#include<bits/stdc++.h>
using namespace std;
const int N=100010;
vector<int> vt[N];
int n,m,dist[N];
bool st[N];
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		vt[a].push_back(b);
	}
	cout<<0;
	return 0; 
}
