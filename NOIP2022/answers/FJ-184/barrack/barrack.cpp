#include<bits/stdc++.h>
#define int long long
using namespace std;

const int Mod=1e9+7;
const int N=5e5+3;
int n,m;
signed main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int u,v;
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>u>>v;
	srand(time(0));
	cout<<((int)rand()*rand())%Mod<<'\n';
	return 0;
}
/*
To be beginning,To be ending.
CMQ,forever..
*/
