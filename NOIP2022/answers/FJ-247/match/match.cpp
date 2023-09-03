#include<bits/stdc++.h>
using namespace std;
long long mod=pow(2,64),ans;
int t,n,a[250000],b[250000],q,l,r,x[250000],y[250000],i,j,k,p;
int main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for(i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(i=1; i<=n; i++) {
		cin>>b[i];
	}
	cin>>q;
	for(i=1; i<=q; i++) {
		cin>>l>>r;
		for(j=l; j<=r; j++) {
			x[j]=a[j];
			y[j]=b[j];
		}
		for(j=l; j<=r; j++) {
			for(k=j; k<=l; k++) {
				sort(x+j,x+k);
				sort(y+j,y+k);
				ans+=x[j]*y[j];
				ans=ans%mod;
				for(p=j; p<=k; p++) {
					x[p]=a[p];
					y[p]=b[p];
				}
			}
		}
	}
	cout<<ans%mod;
	return 0;
}
