#include <bits/stdc++.h>
#define N 250005
using namespace std;
int q,t,n,a[N],b[N],l,r;
unsigned long long ans;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	cin>>q;
	while(q--){
		cin>>l>>r;
		l--;
		ans=0;
		for(int p1=l;p1<r;p1++){
			for(int q1=p1+1;q1<=r;q1++){
				int mx1=0,mx2=0;
				for(int i=p1;i<q1;i++)
					mx1=max(mx1,a[i]);
				for(int i=p1;i<q1;i++)
					mx2=max(mx2,b[i]);
				ans+=mx1*mx2;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
