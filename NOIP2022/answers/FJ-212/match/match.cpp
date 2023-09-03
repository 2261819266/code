#include<bits/stdc++.h>
using namespace std;
int t,n,q,l,r;
unsigned long long s;
int a[50000],b[50000];
int am[10000][10000],bm[10000][10000];

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	cin>>q;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	for(int i=0;i<n;i++){
		am[i][i]=a[i];
		bm[i][i]=b[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			am[i][j]=max(am[i][j-1],a[j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			bm[i][j]=max(bm[i][j-1],b[j]);
		}
	}
	for(;q>0;q--){
		s=0;
		cin>>l>>r;
		for(int i=l-1;i<r;i++){
			for(int j=i;j<r;j++){
				s+=am[i][j]*bm[i][j];
			}
		}
	cout<<s<<endl;
	}
	return 0;
}
