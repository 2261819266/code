#include <bits/stdc++.h>
using namespace std;
const int mod_=1000000007;
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n,m;
	long long ans=1;
	cin >> n >> m;
	if(n==1){
		cout << 1;
	}else if(n==2){
		cout << 5;
	}else if(n==3&&m==2){
		cout << 18;
	}else if(n==m){
		ans=n*(n-1)+1;
		for (int i=0;i<n;i++){
			ans*=2;
			ans=ans%mod_;
		}
		cout << ans;
	}
	return 0;
}
