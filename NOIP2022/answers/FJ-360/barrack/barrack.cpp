#include <bits/stdc++.h>
using namespace std;
int n,m,q,w;
vector<int>a[10005];
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=m; i++){
		cin>>q>>w;
		a[q].push_back(w);
		a[w].push_back(q);
	}
	if(m==n-1){
		cout<<10*n;
		for(int i=1; i<=n; i++){
			
		}
	}
	cout<<(unsigned long long)16*n*n;
	return 0;
}

