#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define SIZE 250005
using namespace std;
unsigned long long T,n,q,l,r;
unsigned long long a[SIZE],b[SIZE],ma[3005][3005],mb[3005][3005];
int main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for(unsigned long long i=1;i<=n;i++) cin>>a[i];
	for(unsigned long long i=1;i<=n;i++) cin>>b[i];
	if(n<=3000) {
		for(unsigned long long i=1;i<=n;i++) ma[i][i]=a[i],mb[i][i]=b[i];
		for(unsigned long long i=1;i<=n;i++) {
			for(unsigned long long j=i+1;j<=n;j++) {
				ma[i][j]=max(ma[i][j-1],a[j]);
				mb[i][j]=max(mb[i][j-1],b[j]);
			}
		}
		cin>>q;
		while(q--) {
			cin>>l>>r;
			unsigned long long ans=0;
			for(unsigned long long i=l;i<=r;i++) {
				for(unsigned long long j=i;j<=r;j++) {
					ans+=ma[i][j]*mb[i][j];
				}
			}
			cout<<ans<<endl;
		}
	}
	else {
		cin>>q;
		while(q--) {
			unsigned long long ans=0;
			cin>>l>>r;
			for(unsigned long long i=l;i<=r;i++) {
				for(unsigned long long j=i;j<=r;j++) {
					unsigned long long maxa=0,maxb=0;
					for(unsigned long long k=i;k<=j;k++) {
						maxa=max(maxa,a[k]);
						maxb=max(maxb,b[k]);
					}
					ans+=maxa*maxb;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
