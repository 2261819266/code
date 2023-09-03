#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	std::ios::sync_with_stdio(false);
	int n,m,a[1000010],b[1000010],ans=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans+=j;
		}
	}
	for(int i=1;i<=m;i++){
		
	}
	return 0;
}
