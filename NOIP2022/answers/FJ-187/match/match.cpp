//只会做第一题呜呜呜，我好菜 
#include<bits/stdc++.h>
using namespace std;
const int N = (2e5+5e4+10);
unsigned long long a[N],b[N];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,Q,n;
	cin>>T>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	cin>>Q;
	while(Q--){
		int l,r;
		unsigned long long ans=0;
		cin>>l>>r;
		for(int q=l;q<=r;q++){
			unsigned long long maxa=0,maxb=0;
			for(int p=q;p<=r;p++){
				maxa=max(maxa,a[p]);
				maxb=max(maxb,b[p]);
				ans+=(unsigned long long)maxa*maxb;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
