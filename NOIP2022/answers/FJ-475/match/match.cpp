#include<bits/stdc++.h>
using namespace std;
unsigned long long ans;
int a[250010],b[250010];
int t,n,q;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	cin>>q;
	while(q--){
		ans=0;
		int l,r;
		cin>>l,r;
		for(int p=l;p<=r;p++){
			int mx1=0,mx2=0;
			for(int q=p;q<=r;q++){
				mx1=max(mx1,a[q]);
				mx2=max(mx2,b[q]);
				ans+=mx1*mx2;
			}
		}
	}
	return 0;
}
