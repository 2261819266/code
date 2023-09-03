#include<bits/stdc++.h>
using namespace std;
const int maxx=31;
int a[maxx],b[maxx],t,n,l[maxx],r[maxx],q;
int ans=0;
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>t>>n;
	if(t<3){
		for(int x=1;x<=n;x++){
			cin>>a[x];
		}
		for(int x=1;x<=n;x++){
			cin>>b[x];
		}
		cin>>q;
		for(int x=1;x<=q;x++){
			cin>>l[x]>>r[x];
		}
	}
	return 0;
}
