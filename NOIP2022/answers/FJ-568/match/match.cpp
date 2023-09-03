#include<bits/stdc++.h>

using namespace std;
const int N=10010;
int a[N],b[N];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,n;
	cin>>T>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	int Q,l,r,ma,mb;
	long long ans=0;
	cin>>Q;
	while(Q--){
		cin>>l>>r;
		ans=0;
		for(int p=l;p<=r;p++){
			for(int q=p;q<=r;q++){
				mb=ma=-1;
				for(int i=p;i<=q;i++){
					ma=max(ma,a[i]);
					mb=max(mb,b[i]);
				}
				ans+=ma*mb;
			}
		}
		cout<<ans<<endl;
	}
}
