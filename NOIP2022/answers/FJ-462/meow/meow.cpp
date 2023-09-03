#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T,n,k;
	long long m,a[9999999],ans=0;
	cin>>T>>n>>m>>k;
	for(long long  i=1;i<=m;i++){
		cin>>a[i];
	}
	cout<<m+m/k-1<<endl;
	for(long long i=1;i<=k;i++){
		for(long long j=1;j<=m;j++){
			if(a[j]==k);
		}
	}
	for(int i=1;i<=m;i++){
		if(a[i]!=a[i+1])cout<<1<<" ";
	}
	return 0;
}
