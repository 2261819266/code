#include <bits/stdc++.h>
using namespace std;
const long long inf=pow(2,64);
int T,n,a[200002],b[200002],Q,l,r;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=1;j<=n;j++) cin>>b[j];
	cin>>Q;
	while(Q--){
		cin>>l>>r;
		long long ans=0;
		for(int i=l;i<=r;i++){
			int mxa=-99999,mxb=-99999;
			for(int j=i;j<=r;j++){
				mxa=max(mxa,a[j]);
				mxb=max(mxb,b[j]);
				ans+=mxa*mxb;
				ans%=inf;
			}	
		}
		cout<<ans<<endl;
	}
	return 0;
}
