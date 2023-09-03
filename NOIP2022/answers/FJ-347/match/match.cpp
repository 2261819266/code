#include<bits/stdc++.h>
using namespace std;
long long t,n,q,a[250010],b[250010];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	cin>>q;
	int l,r;
	for(int st=1;st<=q;st++){
		long long ans=0;
		cin>>l>>r;
		long long q=0,p=0;
		for(int i=l;i<=r;i++){
			for(int j=i;j<=r;j++){
				q=0; p=0;
				for(int k=j;k<=r;k++){
					q=max(q,a[k]);
					p=max(p,b[k]);
				}
				ans=ans+q*p;
			}
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
