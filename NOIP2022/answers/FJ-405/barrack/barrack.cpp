#include<bits/stdc++.h>
using namespace std;
int n,m,line[3001][3001],u,v;
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		cin >> u >> v;
	}
	cout << (n*n-1)*n*m-(m*(m+1)/2);
	




	return 0;
}

