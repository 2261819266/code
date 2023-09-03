#include<bits/stdc++.h>
using namespace std;

long long t,n,w,l,r,a[250010],b[250010];
long long mod=pow(2,64);
int zdz(long long l,long long r,long long c[]){
	int zd=0;
	for(long long i=l;i<=r;i++){
		if(zd<c[i]) zd=c[i];
	}
	return zd;
}

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=n;i++) cin>>b[i];
	cin>>w;
	while(w--){
		long long ans=0;
		cin>>l>>r;
		for(long long p=l;p<=r;p++){
			for(long long q=p;q<=r;q++){
				ans=(ans+(zdz(p,q,a)%mod*zdz(p,q,b))%mod)%mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
