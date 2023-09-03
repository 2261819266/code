#include<bits/stdc++.h>
using namespace std;
int n,q,T,a[250005],b[250005],l,r;
long long ans;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	cin>>q;
	while(q--){
		cin>>l>>r;ans=0;
		for(int i=l;i<=r;i++)
			for(int j=i;j<=r;j++){
				int mn1=0,mn2=0;
				for(int k=i;k<=j;k++) mn1=max(a[k],mn1),mn2=max(b[k],mn2);
				ans+=1ll*mn1*mn2;
			}
		cout<<ans<<"\n";
	}
	return 0;
}
