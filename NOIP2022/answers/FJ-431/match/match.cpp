#include<bits/stdc++.h>
using namespace std;
unsigned long long ans;
int t,n,q,l,r,a[3005],b[3005],c[3005][3005],am,bm;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	cin>>q;
	for(int i=1;i<=n;i++,am=bm=0)
		for(int j=i;j<=n;j++){
			if(a[j]>am) am=a[j];
			if(b[j]>bm) bm=b[j];
			c[i][j]=am*bm;
		}
	while(q--){
		cin>>l>>r;ans=0;
		for(int i=l;i<=r;i++)
			for(int j=i;j<=r;j++) ans+=c[i][j];
		cout<<ans<<'\n';
		
	}
	return 0;
}
