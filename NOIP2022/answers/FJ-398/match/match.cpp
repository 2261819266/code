#include<bits/stdc++.h>
using namespace std;
const int MAX=3*1e5;
unsigned long long t,n,Q,a[MAX],b[MAX];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	cin>>Q;
	for(int s=1;s<=Q;s++){
		unsigned long long l,r,ans=0;
		cin>>l>>r;
		for(int p=l;p<=r;p++)
			for(int q=p;q<=r;q++){
				unsigned long long ansa=0,ansb=0;
				for(int k=p;k<=q;k++){
					ansa=max(ansa,a[k]);
					ansb=max(ansb,b[k]);
				}
				ans+=ansa*ansb;
			}
		cout<<ans<<endl;
	}
	return 0;
}
