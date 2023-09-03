#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	std::ios::sync_with_stdio(false);
	int T,n,a[250010],b[250010],Q,l[250010],r[250010],w,v;
	long long ans;
	cin>>T>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	cin>>Q;
	for(int i=1;i<=Q;i++){
		cin>>l[i]>>r[i];
	}
	for(int i=1;i<=Q;i++){
		ans=0;
		for(int p=l[i];p<=r[i];p++){
			for(int q=r[i];q>=p;q--){
				w=0,v=0;
				for(int m=p;m<=q;m++){
					w=max(w,a[m]);
					v=max(v,b[m]);
				}
				ans+=w*v;
			}
				
		}
		cout<<ans<<endl;
	}
	return 0;
}
