#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll unsigned long long
using namespace std;
ll a[1000001],b[1000001];
ll am[30][100001],bm[30][1000001];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ll t,n;
	cin>>t>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++) cin>>b[i];
	ll q;
	cin>>q;
	for(ll i=1;i<=q;i++){
		ll l,r,ans=0;
		cin>>l>>r;
		for(ll j=l;j<=r;j++){
			for(ll k=j;k<=r;k++){
				ll am=0,bm=0;
				for(int o=j;o<=k;o++){
					am=max(a[o],am);
					bm=max(b[o],bm);
				}
				ans=ans+am*bm; 
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
