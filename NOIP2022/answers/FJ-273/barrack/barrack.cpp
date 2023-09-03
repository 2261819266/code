#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll M=1e9+7;
ll n,m,a[500005],b[500005];
int fast(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=(ans*a)%M;
		a=a*a%M;
		b>>=1;
	}
	return ans;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	 cin>>a[i]>>b[i];
	ll ans=fast(2,n);
	cout<<(ans+1)%M;
	return 0;
}

