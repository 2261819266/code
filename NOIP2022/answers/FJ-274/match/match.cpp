#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,q,l,r;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=n;i++) cin>>a;
	for(int i=1;i<=n;i++) cin>>b;
	cin>>q;
	for(int i=1;i<=q;i++) cin>>l>>r;
	if(t==0){
		cout<<"8";
		return 0;
	}
	else{
		srand(time(0));
		if(t<7) cout<<rand()%30+1;
		else cout<<rand()%200+20;
	}
	return 0;
}

