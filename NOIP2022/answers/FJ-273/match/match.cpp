#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,ans,Q,a[250005],b[250005],q,l[250005],r[250005];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	cin>>Q;
	for(int i=1;i<=Q;i++){
		cin>>l[i]>>r[i];
		for(int p=l[i];p<=r[i];p++)
		 for(int q=p;q<=r[i];q++)
		 	ans=ans+a[p]*b[q];
		cout<<ans;
	}
	return 0;
}

