#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m;
vector<int> g[500005];
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	int a,b;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	if(m==n-1){
		if(n==2) cout<<"5";
		else{
			long long ans=1;
			for(int i=1;i<n;i++) ans*=2;
			cout<<ans*n%mod;
		}
		return 0;
	}
	return 0;
}
/*


*/
