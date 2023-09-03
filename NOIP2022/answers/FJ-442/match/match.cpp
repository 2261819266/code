#include<bits/stdc++.h>
using namespace std;
unsigned long long a[250010];
unsigned long long b[250010];
unsigned long long ans;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,n;
	cin>>T>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	int Q;
	cin>>Q;
	while(Q--){
		int l,r;
		cin>>l>>r;
		unsigned long long s1=0,s2=0;
		ans=0;
		for(int p=l;p<=r;p++)
			for(int q=p;q<=r;q++){
				s1=0,s2=0;
				for(int i=p;i<=q;i++){
					s1=max(a[i],s1);
					s2=max(b[i],s2);
				}
				ans+=s1*s2;
			}
			cout<<ans<<endl;
	}
}
