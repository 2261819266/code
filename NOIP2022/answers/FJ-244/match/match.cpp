#include<bits/stdc++.h>
using namespace std;
int a[100],b[100],T,n,Q,l,r;
unsigned long long ans;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	cin>>Q;
	for(int i=1;i<=Q;i++){
		cin>>l>>r;
		int maxa;
		int maxb;
		for(int j=l;j<=r;j++){
			maxa=a[j];
			maxb=b[j];
			for(int k=j;k<=r;k++){
				if(a[k]>maxa) maxa=a[k];
				if(b[k]>maxb) maxb=b[k];
				ans+=maxa*maxb;
			}
		}
		cout<<ans;
	}
	return 0;
}
