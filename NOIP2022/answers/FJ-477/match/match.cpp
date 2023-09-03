#include<bits/stdc++.h>

using namespace std;

int t,n,a[250005],b[250005],q,l,r;
unsigned long long ans;
int main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	cin>>q;
	while(q--) {
		ans=0;
		cin>>l>>r;
		for(int i=l;i<=r;i++) {
			int maxa=a[i],maxb=b[i];
			for(int j=i;j<=r;j++) maxa=max(maxa,a[j]),maxb=max(maxb,b[j]),ans+=maxa*maxb;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
