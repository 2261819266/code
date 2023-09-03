#include<bits/stdc++.h>

using namespace std;

int n,m;
long long ans=1;
int main() {
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++) ans=ans*2%1000000007;
	cout<<ans-1; 
	return 0;
}
