#include <bits/stdc++.h>
using namespace std;
unsigned long long t, n, a[3010], b[3010], ans;
int main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for (unsigned long long i=1; i<=n; ++i)cin>>a[i];
	for (unsigned long long i=1; i<=n; ++i)cin>>b[i];
	unsigned long long q;
	cin>>q;
	while(q--) {
		unsigned long long l, r;
		cin>>l>>r;
		for (unsigned long long i=l; i<=r; ++i)
			for (unsigned long long j=i; j<=r; ++j) {
				unsigned long long ma=0, mb=0;
				for (int k=i; k<=j; ++k) {
					if (a[k]>ma) ma=a[k];
					if (b[k]>mb) mb=b[k];
				}
				ans=ans+ma*mb;
			}
	}
	cout<<ans<<endl;
	return 0;
}
