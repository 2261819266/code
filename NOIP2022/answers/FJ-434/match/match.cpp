#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int zsa,n,Q,x,y,ans1,ans2;
	cin>>zsa>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	cin>>Q;
	while(Q--){
		cin>>x>>y;
		unsigned long long ans=0;
		for(int i=x;i<=y;i++){
			for(int j=i;j<=y;j++){
				ans1=-1;
				ans2=-1;
				for(int k=i;k<=j;k++){
					ans1=max(ans1,a[k]);
					ans2=max(ans2,b[k]);
				}
				ans+=(unsigned long long)1*ans1*ans2;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
