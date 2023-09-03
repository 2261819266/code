#include<bits/stdc++.h>
using namespace std;

int a[10000],b[10000],c[10000][2];

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out,","w",stdout);
	int t,n,q;
	cin>>t>>n;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	for(int i = 0;i<n;i++){
		cin>>b[i];
	}
	cin>>q;
	for(int i = 0;i<q;i++){
		cin>>c[i][0]>>c[i][1];
	}
	return 0;
}
