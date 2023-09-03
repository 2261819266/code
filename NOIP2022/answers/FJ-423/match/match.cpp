#include<bits/stdc++.h>
using namespace std;
int t,n,a[250000],b[250000],Q,l[250000],r[250000],maxa,maxb;
long long ans;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	cin>>Q;
	for(int i=1;i<=Q;i++)cin>>l[i]>>r[i];
	for(int i=1;i<=Q;i++){
		for(int p=l[i];p<=r[i];p++){
			for(int q=p;q<=r[i];q++){
				maxa=0;
				maxb=0;
				for(int j=p;j<=q;j++){
					maxa=max(a[j],maxa);
					maxb=max(b[j],maxb);
				}
				ans=ans+maxa*maxb;
			}
		}
	}
	cout<<ans;
}
