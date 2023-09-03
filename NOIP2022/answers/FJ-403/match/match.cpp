#include<bits/stdc++.h>
using namespace std;
const long long p=(long long)pow(2,64);
long long t,n,a[1000010],b[1000010],q,ans;
int main(){
//	cout<<p;
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%lld%lld",&t,&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&b[i]);
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int l,r;
		ans=0;
		scanf("%d%d",&l,&r);
		for(int j=l;j<=r;j++){
			for(int k=j;k<=r;k++){
				long long x=-1,y=-1;
				for(int u=j;u<=k;u++){
					x=max(x,a[u]);
					y=max(y,b[u]);
				}
				ans+=x*y;
				ans%=p;
//				cout<<ans<<endl;
			}
		}
		printf("%lld\n",ans);
	}
				
	return 0;
}
